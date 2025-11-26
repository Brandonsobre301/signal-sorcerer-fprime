module Components {
    @ Physics Based Noise Filter
    active component SignalFilter {

    # ----------------------------------------------------------------------
    # General Ports
    # ----------------------------------------------------------------------

    @ Port for requesting the current time
    time get port timeCaller

    @ Port for sending command registrations
    command reg port cmdRegOut

    @ Port for receiving commands
    command recv port cmdIn

    @ Port for sending command responses
    command resp port cmdResponseOut

    @ Port for sending telemetry channels
    telemetry port tlmOut

    @ Port for sending text events (logs)
    text event port logOut

    # ----------------------------------------------------------------------
    # YOUR NEW COMMANDS AND TELEMETRY
    # ----------------------------------------------------------------------

    @ Command to receive a noisy signal value
    async command INPUT_SIGNAL(value: F32)

    @ Telemetry channel for the cleaned signal
    telemetry CleanSignal: F32 id 0

  }
}