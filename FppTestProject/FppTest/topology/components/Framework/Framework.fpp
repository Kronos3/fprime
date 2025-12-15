module FppTest {

    active component Framework {

        @ Command dispatch port
        output port compCmdSend: [CmdDispatcherComponentCommandPorts] Fw.Cmd

        @ Output Command Status Port
        output port seqCmdStatus: [CmdDispatcherSequencePorts] Fw.CmdResponse

        @ Command Registration Port. max_number should match dispatch port.
        guarded input port compCmdReg: [CmdDispatcherComponentCommandPorts] Fw.CmdReg

        @ Input Command Status Port
        async input port compCmdStat: Fw.CmdResponse

        @ Command buffer input port for sequencers or other sources of command buffers
        async input port seqCmdBuff: [CmdDispatcherSequencePorts] Fw.Com assert

        # ----------------------------------------------------------------------
        # Port matching specifiers
        # ----------------------------------------------------------------------

        match compCmdSend with compCmdReg

        match seqCmdStatus with seqCmdBuff

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

    }

}