// ======================================================================
// \title  SignalFilter.cpp
// \author brand
// \brief  cpp file for SignalFilter component implementation class
// ======================================================================

#include "SignalFilter/SignalFilter.hpp"

namespace Components {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

SignalFilter ::SignalFilter(const char* const compName) : SignalFilterComponentBase(compName), m_last_val(0.0f) {}

SignalFilter ::~SignalFilter() {}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void SignalFilter ::INPUT_SIGNAL_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, F32 value) {
// Simple Low-Pass Filter Logic
    // This smoothing algorithm mimics physical inertia
    this->m_last_val = (this->m_last_val * 0.9f) + (value * 0.1f);

    // 1. Downlink the clean data
    this->tlmWrite_CleanSignal(this->m_last_val);

    // 2. Tell Ground System the command succeeded
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // namespace Components
