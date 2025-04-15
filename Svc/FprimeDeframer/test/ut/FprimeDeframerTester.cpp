// ======================================================================
// \title  FprimeDeframerTester.cpp
// \author thomas-bc
// \brief  cpp file for FprimeDeframer component test harness implementation class
// ======================================================================

#include "FprimeDeframerTester.hpp"
#include "STest/Random/Random.hpp"

namespace Svc {

// ----------------------------------------------------------------------
// Construction and destruction
// ----------------------------------------------------------------------

FprimeDeframerTester ::FprimeDeframerTester()
    : FprimeDeframerGTestBase("FprimeDeframerTester", FprimeDeframerTester::MAX_HISTORY_SIZE), component("FprimeDeframer") {
    this->initComponents();
    this->connectPorts();
}

FprimeDeframerTester ::~FprimeDeframerTester() {}

// ----------------------------------------------------------------------
// Tests
// ----------------------------------------------------------------------

void FprimeDeframerTester ::testNominalFrame() {
    // Get random byte of data
    U8 randomByte = static_cast<U8>(STest::Random::lowerUpper(0, 255));
    //           |  F´ start word        |     Length (= 1)      |   Data     |   Checksum (4 bytes)   |
    U8 data[13] = {0xDE, 0xAD, 0xBE, 0xEF, 0x00, 0x00, 0x00, 0x01,  randomByte,  0x00, 0x00, 0x00, 0x00};
    // Inject the checksum into the data and send it to the component under test
    this->injectChecksum(data, sizeof(data));
    this->mockReceiveData(data, sizeof(data));

    ASSERT_from_deframedOut_SIZE(1); // something emitted on deframedOut
    ASSERT_from_bufferDeallocate_SIZE(0); // nothing emitted on bufferDeallocate
    // Assert that the data that was emitted on deframedOut is equal to Data field above (randomByte)
    ASSERT_EQ(this->fromPortHistory_deframedOut->at(0).data.getData()[0], randomByte);
    ASSERT_EVENTS_SIZE(0); // no events emitted
}

void FprimeDeframerTester ::testIncorrectLengthToken() {
    // Frame:     |  F´ start word       |  INCORRECT Length=5   | Data |   Checksum (4 bytes)   |
    U8 data[13] = {0xDE, 0xAD, 0xBE, 0xEF, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00};
    // Inject the checksum into the data and send it to the component under test
    this->injectChecksum(data, sizeof(data));
    this->mockReceiveData(data, sizeof(data));

    ASSERT_from_deframedOut_SIZE(0); // nothing emitted on deframedOut
    ASSERT_from_bufferDeallocate_SIZE(1); // invalid buffer was deallocated
    // Check which event was emitted
    ASSERT_EVENTS_SIZE(1); // exactly 1 event emitted
    ASSERT_EVENTS_InvalidLengthReceived_SIZE(1); // event was emitted for invalid length
}

void FprimeDeframerTester ::testIncorrectStartWord() {
    // Frame:     |  INCORRECT start word |      Length = 1      | Data |   Checksum (4 bytes)   |
    U8 data[13] = {0x00, 0x11, 0x22, 0x33, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00};
    // Inject the checksum into the data and send it to the component under test
    this->injectChecksum(data, sizeof(data));
    this->mockReceiveData(data, sizeof(data));

    ASSERT_from_deframedOut_SIZE(0); // nothing emitted on deframedOut
    ASSERT_from_bufferDeallocate_SIZE(1); // invalid buffer was deallocated
    // Check which event was emitted
    ASSERT_EVENTS_SIZE(1); // exactly 1 event emitted
    ASSERT_EVENTS_InvalidStartWord_SIZE(1); // event was emitted for invalid start word
}

void FprimeDeframerTester ::testIncorrectCrc() {
    // Frame:     |   F´ start word      |      Length = 1       | Data |  INCORRECT Checksum  |
    U8 data[13] = {0xDE, 0xAD, 0xBE, 0xEF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00};
    this->mockReceiveData(data, sizeof(data));
    ASSERT_from_deframedOut_SIZE(0); // nothing emitted on deframedOut
    ASSERT_from_bufferDeallocate_SIZE(1); // invalid buffer was deallocated
    // Check which event was emitted
    ASSERT_EVENTS_SIZE(1); // exactly 1 event emitted
    ASSERT_EVENTS_InvalidChecksum_SIZE(1); // event was emitted for invalid checksum
}

void FprimeDeframerTester::testTruncatedFrame() {
    // Send a truncated frame, too short to be valid
    U8 data[11] = {0xDE, 0xAD, 0xBE, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    this->mockReceiveData(data, sizeof(data));
    ASSERT_from_deframedOut_SIZE(0); // nothing emitted on deframedOut
    ASSERT_from_bufferDeallocate_SIZE(1); // invalid buffer was deallocated
    // Check which event was emitted
    ASSERT_EVENTS_SIZE(1); // exactly 1 event emitted
    ASSERT_EVENTS_InvalidBufferReceived_SIZE(1); // event was emitted for invalid buffer
}

void FprimeDeframerTester::testZeroSizeFrame() {
    // Send an empty frame, too short to be valid
    this->mockReceiveData(nullptr, 0);
    ASSERT_from_deframedOut_SIZE(0); // nothing emitted on deframedOut
    ASSERT_from_bufferDeallocate_SIZE(1); // invalid buffer was deallocated
    // Check which event was emitted
    ASSERT_EVENTS_SIZE(1); // exactly 1 event emitted
    ASSERT_EVENTS_InvalidBufferReceived_SIZE(1); // event was emitted for invalid buffer
}

// ----------------------------------------------------------------------
// Test Helpers
// ----------------------------------------------------------------------

void FprimeDeframerTester::injectChecksum(U8* data, FwSizeType size) {
    // Needs 4 bytes for the checksum field and at least 1 byte of data to checksum
    if (size < 5) {
        return;
    }
    // Compute the checksum
    Utils::Hash crc_calculator;
    Utils::HashBuffer crc_result;
    crc_calculator.update(data, size - 4);
    crc_calculator.final(crc_result);
    // Inject the checksum into the data
    for (FwSizeType i = 0; i < 4; i++) {
        data[size - 4 + i] = static_cast<U8>(crc_result.asBigEndianU32() >> (8 * (3 - i)) & 0xFF);
    }
}

void FprimeDeframerTester::mockReceiveData(U8* data, FwSizeType size) {
    Fw::Buffer nullContext;
    Fw::Buffer buffer(data, static_cast<Fw::Buffer::SizeType>(size));
    this->invoke_to_framedIn(0, buffer, nullContext);
}

}  // namespace Svc
