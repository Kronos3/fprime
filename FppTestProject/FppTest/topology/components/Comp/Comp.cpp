// ======================================================================
// \title  Comp.cpp
// \author tumbar
// \brief  cpp file for Comp component implementation class
// ======================================================================

#include "FppTest/topology/components/Comp/Comp.hpp"

namespace FppTest {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

Comp ::Comp(const char* const compName) : CompComponentBase(compName) {}

Comp ::~Comp() {}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void Comp ::Command_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, U32 a, F32 b, const Fw::CmdStringArg& c) {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

// ----------------------------------------------------------------------
// Handler implementations for data products
// ----------------------------------------------------------------------

void Comp ::dpRecv_Product_handler(DpContainer& container, Fw::Success::T status) {
    // TODO
}

}  // namespace FppTest
