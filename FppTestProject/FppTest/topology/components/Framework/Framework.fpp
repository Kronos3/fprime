module FppTest {

    active component Framework {

        @ Command dispatch port
        output port compCmdSend: [CmdDispatcherComponentCommandPorts] Fw.Cmd

        @ Command Registration Port. max_number should match dispatch port.
        guarded input port compCmdReg: [CmdDispatcherComponentCommandPorts] Fw.CmdReg

        @ Input Command Status Port
        async input port compCmdStat: Fw.CmdResponse

        @ Event input port
        sync input port LogRecv: Fw.Log

        @ Text Event input port
        sync input port TextLogRecv: Fw.LogText

        @ Guarded port for receiving telemetry values
        guarded input port TlmRecv: Fw.Tlm

        @ Port that replies with parameter value
        sync input port ParamGetIn: Fw.PrmGet

        @ Port that sets a parameter
        sync input port ParamSetIn: Fw.PrmSet

        @ Port for getting current time
        sync input port timeGetIn: Fw.Time

        @ Ports for responding to a data product get from a client component
        sync input port productGetIn: [DpManagerNumPorts] Fw.DpGet

        @ Ports for receiving data product buffer requests from a client component
        async input port productRequestIn: [DpManagerNumPorts] Fw.DpRequest

        @ Ports for sending requested data product buffers to a client component
        output port productResponseOut: [DpManagerNumPorts] Fw.DpResponse

        @ Ping output port
        output port PingSend: [HealthPingPorts] Svc.Ping

        @ Ping return port
        async input port PingReturn: [HealthPingPorts] Svc.Ping

        # ----------------------------------------------------------------------
        # Port matching specifiers
        # ----------------------------------------------------------------------

        match compCmdSend with compCmdReg

    }

}