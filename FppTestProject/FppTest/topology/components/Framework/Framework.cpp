// ======================================================================
// \title  Framework.cpp
// \author tumbar
// \brief  cpp file for Framework component implementation class
// ======================================================================

#include "FppTest/topology/components/Framework/Framework.hpp"

namespace FppTest {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

Framework ::Framework(const char* const compName) : FrameworkComponentBase(compName) {}

Framework ::~Framework() {}

// ----------------------------------------------------------------------
// Handler implementations for typed input ports
// ----------------------------------------------------------------------

void Framework ::LogRecv_handler(FwIndexType portNum,
                                 FwEventIdType id,
                                 Fw::Time& timeTag,
                                 const Fw::LogSeverity& severity,
                                 Fw::LogBuffer& args) {
    // TODO
}

Fw::ParamValid Framework ::ParamGetIn_handler(FwIndexType portNum, FwPrmIdType id, Fw::ParamBuffer& val) {
    return {Fw::ParamValid::DEFAULT};
}

void Framework ::ParamSetIn_handler(FwIndexType portNum, FwPrmIdType id, Fw::ParamBuffer& val) {
    // TODO
}

void Framework ::PingReturn_handler(FwIndexType portNum, U32 key) {
    // TODO
}

void Framework ::TextLogRecv_handler(FwIndexType portNum,
                                     FwEventIdType id,
                                     Fw::Time& timeTag,
                                     const Fw::LogSeverity& severity,
                                     Fw::TextLogString& text) {
    // TODO
}

void Framework ::TlmRecv_handler(FwIndexType portNum, FwChanIdType id, Fw::Time& timeTag, Fw::TlmBuffer& val) {
    // TODO
}

void Framework ::compCmdReg_handler(FwIndexType portNum, FwOpcodeType opCode) {
    // TODO
}

void Framework ::compCmdStat_handler(FwIndexType portNum,
                                     FwOpcodeType opCode,
                                     U32 cmdSeq,
                                     const Fw::CmdResponse& response) {
    // TODO
}

Fw::Success Framework ::productGetIn_handler(FwIndexType portNum,
                                             FwDpIdType id,
                                             FwSizeType dataSize,
                                             Fw::Buffer& buffer) {
    return {Fw::Success::SUCCESS};
}

void Framework ::productRequestIn_handler(FwIndexType portNum, FwDpIdType id, FwSizeType dataSize) {
    // TODO
}

void Framework ::timeGetIn_handler(FwIndexType portNum, Fw::Time& time) {
    // TODO
}

}  // namespace FppTest
