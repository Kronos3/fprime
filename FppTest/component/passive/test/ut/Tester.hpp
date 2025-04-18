// ======================================================================
// \title  PassiveTest/test/ut/Tester.hpp
// \author tiffany
// \brief  hpp file for PassiveTest test harness implementation class
// ======================================================================

#ifndef TESTER_HPP
#define TESTER_HPP

#include "FppTest/component/active/SerialPortIndexEnumAc.hpp"
#include "FppTest/component/active/TypedPortIndexEnumAc.hpp"
#include "FppTest/component/passive/PassiveTest.hpp"
#include "FppTest/component/tests/CmdTests.hpp"
#include "FppTest/component/tests/EventTests.hpp"
#include "FppTest/component/tests/ParamTests.hpp"
#include "FppTest/component/tests/PortTests.hpp"
#include "FppTest/component/tests/TlmTests.hpp"
#include "FppTest/component/types/FormalParamTypes.hpp"
#include "PassiveTestGTestBase.hpp"

class Tester : public PassiveTestGTestBase {
    // ----------------------------------------------------------------------
    // Construction and destruction
    // ----------------------------------------------------------------------

  public:
    // Maximum size of histories storing events, telemetry, and port outputs
    static const U32 MAX_HISTORY_SIZE = 100;
    // Instance ID supplied to the component instance under test
    static const FwEnumStoreType TEST_INSTANCE_ID = 0;
    // Queue depth supplied to component instance under test
    static const FwSizeType TEST_INSTANCE_QUEUE_DEPTH = 10;

    //! Construct object Tester
    //!
    Tester();

    //! Destroy object Tester
    //!
    ~Tester();

  public:
    // ----------------------------------------------------------------------
    // Tests
    // ----------------------------------------------------------------------

    PORT_TEST_DECLS

    CMD_TEST_DECLS

    EVENT_TEST_DECLS

    TLM_TEST_DECLS

    void testParam();

    PARAM_CMD_TEST_DECLS

    void testTime();

  PRIVATE:

    #include "FppTest/component/common/tester.hpp"

  PRIVATE:
    // ----------------------------------------------------------------------
    // Handlers for serial from ports
    // ----------------------------------------------------------------------

    //! Handler for from_serialOut
    //!
    void from_serialOut_handler(FwIndexType portNum,        //!< The port number
                                Fw::SerializeBufferBase& Buffer //!< The serialization buffer
    );

  public:
    // ----------------------------------------------------------------------
    // Helper methods
    // ----------------------------------------------------------------------

    //! Connect ports
    //!
    void connectPorts();

    //! Connect prmSetIn port
    void connectPrmSetIn();

    //! Connect timeGetOut port
    void connectTimeGetOut();

    //! Connect serial ports to special ports
    void connectSpecialPortsSerial();

    //! Set prmValid
    void setPrmValid(Fw::ParamValid valid);

    //! Initialize components
    //!
    void initComponents();

    //! Check successful status of a serial port invocation
    void checkSerializeStatusSuccess();

    //! Check unsuccessful status of a serial port invocation
    void checkSerializeStatusBufferEmpty();

  PRIVATE:
    // ----------------------------------------------------------------------
    // Variables
    // ----------------------------------------------------------------------

    //! The component under test
    //!
    PassiveTest component;

    // Values returned by typed output ports
    FppTest::Types::BoolType noParamReturnVal;
    FppTest::Types::U32Type primitiveReturnVal;
    FppTest::Types::EnumType enumReturnVal;
    FppTest::Types::ArrayType arrayReturnVal;
    FppTest::Types::StructType structReturnVal;
    FppTest::Types::StringType stringReturnVal;
    FppTest::Types::StringType stringAliasReturnVal;
    FppTest::Types::AliasStringArrayType arrayStringAliasReturnVal;

    // Buffers from serial output ports;
    U8 primitiveData[InputPrimitiveArgsPort::SERIALIZED_SIZE];
    U8 stringData[InputStringArgsPort::SERIALIZED_SIZE];
    U8 enumData[InputEnumArgsPort::SERIALIZED_SIZE];
    U8 arrayData[InputArrayArgsPort::SERIALIZED_SIZE];
    U8 structData[InputStructArgsPort::SERIALIZED_SIZE];
    U8 serialData[SERIAL_ARGS_BUFFER_CAPACITY];

    Fw::SerialBuffer primitiveBuf;
    Fw::SerialBuffer stringBuf;
    Fw::SerialBuffer enumBuf;
    Fw::SerialBuffer arrayBuf;
    Fw::SerialBuffer structBuf;
    Fw::SerialBuffer serialBuf;

    // Parameter test values
    FppTest::Types::BoolParam boolPrm;
    FppTest::Types::U32Param u32Prm;
    FppTest::Types::PrmStringParam stringPrm;
    FppTest::Types::EnumParam enumPrm;
    FppTest::Types::ArrayParam arrayPrm;
    FppTest::Types::StructParam structPrm;
    Fw::ParamValid prmValid;

    // Time test values
    Fw::Time time;
};

#endif
