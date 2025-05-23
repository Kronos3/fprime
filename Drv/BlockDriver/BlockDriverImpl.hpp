#ifndef DRV_BLOCK_DRIVER_IMPL_HPP
#define DRV_BLOCK_DRIVER_IMPL_HPP

#include <Drv/BlockDriver/BlockDriverComponentAc.hpp>

namespace Drv {

    class BlockDriverImpl final : public BlockDriverComponentBase  {

    public:

        // Only called by derived class
        BlockDriverImpl(const char* compName);

        ~BlockDriverImpl();
        // a little hack to get the reference running
        void callIsr();

    private:

        // downcalls for input ports
        void InterruptReport_internalInterfaceHandler(U32 ip);
        void BufferIn_handler(FwIndexType portNum, Drv::DataBuffer& buffer);
        void Sched_handler(FwIndexType portNum, U32 context);
        //! Handler implementation for PingIn
        //!
        void PingIn_handler(
            const FwIndexType portNum, /*!< The port number*/
            U32 key /*!< Value to return to pinger*/
        );

        // static ISR callback
        static void s_driverISR(void* arg);

        // cycle count
        U32 m_cycles;

    };
}

#endif
