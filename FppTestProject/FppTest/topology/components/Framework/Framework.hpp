// ======================================================================
// \title  Framework.hpp
// \author tumbar
// \brief  hpp file for Framework component implementation class
// ======================================================================

#ifndef FppTest_Framework_HPP
#define FppTest_Framework_HPP

#include "FppTest/topology/components/Framework/FrameworkComponentAc.hpp"

namespace FppTest {

class Framework final : public FrameworkComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct Framework object
    Framework(const char* const compName  //!< The component name
    );

    //! Destroy Framework object
    ~Framework();

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for LogRecv
    //!
    //! Event input port
    void LogRecv_handler(FwIndexType portNum,              //!< The port number
                         FwEventIdType id,                 //!< Log ID
                         Fw::Time& timeTag,                //!< Time Tag
                         const Fw::LogSeverity& severity,  //!< The severity argument
                         Fw::LogBuffer& args               //!< Buffer containing serialized log entry
                         ) override;

    //! Handler implementation for ParamGetIn
    //!
    //! Port that replies with parameter value
    Fw::ParamValid ParamGetIn_handler(FwIndexType portNum,  //!< The port number
                                      FwPrmIdType id,       //!< Parameter ID
                                      Fw::ParamBuffer& val  //!< Buffer containing serialized parameter value.
                                                            //!< Unmodified if param not found.
                                      ) override;

    //! Handler implementation for ParamSetIn
    //!
    //! Port that sets a parameter
    void ParamSetIn_handler(FwIndexType portNum,  //!< The port number
                            FwPrmIdType id,       //!< Parameter ID
                            Fw::ParamBuffer& val  //!< Buffer containing serialized parameter value
                            ) override;

    //! Handler implementation for TextLogRecv
    //!
    //! Text Event input port
    void TextLogRecv_handler(FwIndexType portNum,              //!< The port number
                             FwEventIdType id,                 //!< Log ID
                             Fw::Time& timeTag,                //!< Time Tag
                             const Fw::LogSeverity& severity,  //!< The severity argument
                             Fw::TextLogString& text           //!< Text of log message
                             ) override;

    //! Handler implementation for TlmRecv
    //!
    //! Guarded port for receiving telemetry values
    void TlmRecv_handler(FwIndexType portNum,  //!< The port number
                         FwChanIdType id,      //!< Telemetry Channel ID
                         Fw::Time& timeTag,    //!< Time Tag
                         Fw::TlmBuffer& val    //!< Buffer containing serialized telemetry value
                         ) override;

    //! Handler implementation for compCmdReg
    //!
    //! Command Registration Port. max_number should match dispatch port.
    void compCmdReg_handler(FwIndexType portNum,  //!< The port number
                            FwOpcodeType opCode   //!< Command Op Code
                            ) override;

    //! Handler implementation for compCmdStat
    //!
    //! Input Command Status Port
    void compCmdStat_handler(FwIndexType portNum,             //!< The port number
                             FwOpcodeType opCode,             //!< Command Op Code
                             U32 cmdSeq,                      //!< Command Sequence
                             const Fw::CmdResponse& response  //!< The command response argument
                             ) override;

    //! Handler implementation for productGetIn
    //!
    //! Ports for responding to a data product get from a client component
    Fw::Success productGetIn_handler(FwIndexType portNum,  //!< The port number
                                     FwDpIdType id,        //!< The container ID (input)
                                     FwSizeType dataSize,  //!< The data size of the requested buffer (input)
                                     Fw::Buffer& buffer    //!< The buffer (output)
                                     ) override;

    //! Handler implementation for productRequestIn
    //!
    //! Ports for receiving data product buffer requests from a client component
    void productRequestIn_handler(FwIndexType portNum,  //!< The port number
                                  FwDpIdType id,        //!< The container ID
                                  FwSizeType dataSize   //!< The data size of the requested buffer
                                  ) override;

    //! Handler implementation for seqCmdBuff
    //!
    //! Command buffer input port for sequencers or other sources of command buffers
    void seqCmdBuff_handler(FwIndexType portNum,  //!< The port number
                            Fw::ComBuffer& data,  //!< Buffer containing packet data
                            U32 context           //!< Call context value; meaning chosen by user
                            ) override;

    //! Handler implementation for timeGetIn
    //!
    //! Port for getting current time
    void timeGetIn_handler(FwIndexType portNum,  //!< The port number
                           Fw::Time& time        //!< Reference to Time object
                           ) override;
};

}  // namespace FppTest

#endif
