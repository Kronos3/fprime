// ======================================================================
// \title  ComStub.hpp
// \author mstarch
// \brief  hpp file for ComStub component implementation class
// ======================================================================

#ifndef Svc_ComStub_HPP
#define Svc_ComStub_HPP

#include "Svc/ComStub/ComStubComponentAc.hpp"

namespace Svc {

class ComStub final : public ComStubComponentBase {
  public:
    const FwIndexType RETRY_LIMIT = 10;
    // ----------------------------------------------------------------------
    // Construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct object ComStub
    //!
    ComStub(const char* const compName /*!< The component name*/
    );

    //! Destroy object ComStub
    //!
    ~ComStub() override;

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for user-defined typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for comDataIn
    //!
    Drv::SendStatus comDataIn_handler(const FwIndexType portNum, /*!< The port number*/
                                      Fw::Buffer& sendBuffer) override;

    //! Handler implementation for drvConnected
    //!
    void drvConnected_handler(const FwIndexType portNum) override;

    //! Handler implementation for drvDataIn
    //!
    void drvDataIn_handler(const FwIndexType portNum,
                           /*!< The port number*/ Fw::Buffer& recvBuffer,
                           const Drv::RecvStatus& recvStatus) override;

    bool m_reinitialize;  //!< Stores if a ready signal is needed on connection
};

}  // end namespace Svc

#endif
