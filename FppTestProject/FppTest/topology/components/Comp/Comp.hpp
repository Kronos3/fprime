// ======================================================================
// \title  Comp.hpp
// \author tumbar
// \brief  hpp file for Comp component implementation class
// ======================================================================

#ifndef FppTest_Comp_HPP
#define FppTest_Comp_HPP

#include "FppTest/topology/components/Comp/CompComponentAc.hpp"
#include "Fw/Types/StringTemplate.hpp"

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
    // Handler implementations for typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for EmitEventIn
    void EmitEventIn_handler(FwIndexType portNum,  //!< The port number
                             U32 a,
                             F32 b,
                             const Fw::StringBase& c) override;

    //! Handler implementation for EmitTelemetryIn
    void EmitTelemetryIn_handler(FwIndexType portNum,  //!< The port number
                                 U32 a) override;

    //! Handler implementation for PingIn
    void PingIn_handler(FwIndexType portNum,  //!< The port number
                        U32 key               //!< Value to return to pinger
                        ) override;

    //! Handler implementation for SetParameter
    U32 GetParameter_handler(FwIndexType portNum) override;

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command Start
    void Start_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                          U32 cmdSeq,            //!< The command sequence number
                          U32 nRecords
                          ) override;

    //! Handler implementation for command Data
    void Data_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                         U32 cmdSeq,           //!< The command sequence number
                         U32 a,
                         F32 b,
                         const Fw::CmdStringArg& c) override;

    //! Handler implementation for command End
    void End_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                        U32 cmdSeq            //!< The command sequence number
                        ) override;

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for data products
    // ----------------------------------------------------------------------

    //! Receive a container of type Product
    void dpRecv_Product_handler(DpContainer& container,  //!< The container
                                Fw::Success::T status    //!< The container status
                                ) override;

    private:

    DpContainer m_dpContainer;
    bool m_dpInProgress;
    FwOpcodeType m_opcode;
    U32 m_cmdSeq;
};

}  // namespace FppTest

#endif
