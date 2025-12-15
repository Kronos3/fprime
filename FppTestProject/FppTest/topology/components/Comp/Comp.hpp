// ======================================================================
// \title  Comp.hpp
// \author tumbar
// \brief  hpp file for Comp component implementation class
// ======================================================================

#ifndef FppTest_Comp_HPP
#define FppTest_Comp_HPP

#include "FppTest/topology/components/Comp/CompComponentAc.hpp"

namespace FppTest {

class Comp final : public CompComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct Comp object
    Comp(const char* const compName  //!< The component name
    );

    //! Destroy Comp object
    ~Comp();

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command Command
    void Command_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                            U32 cmdSeq,           //!< The command sequence number
                            U32 a,
                            F32 b,
                            const Fw::CmdStringArg& c) override;

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for data products
    // ----------------------------------------------------------------------

    //! Receive a container of type Product
    void dpRecv_Product_handler(DpContainer& container,  //!< The container
                                Fw::Success::T status    //!< The container status
                                ) override;
};

}  // namespace FppTest

#endif
