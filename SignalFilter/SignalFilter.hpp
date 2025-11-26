// ======================================================================
// \title  SignalFilter.hpp
// \author brand
// \brief  hpp file for SignalFilter component implementation class
// ======================================================================

#ifndef Components_SignalFilter_HPP
#define Components_SignalFilter_HPP

#include "SignalFilter/SignalFilterComponentAc.hpp"

namespace Components {

class SignalFilter final : public SignalFilterComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct SignalFilter object
    SignalFilter(const char* const compName  //!< The component name
    );

    //! Destroy SignalFilter object
    ~SignalFilter();

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------
    F32 m_last_val;
    //! Handler implementation for command INPUT_SIGNAL
    //!
    //! Command to receive a noisy signal value
    void INPUT_SIGNAL_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                                 U32 cmdSeq,           //!< The command sequence number
                                 F32 value) override;
};

}  // namespace Components

#endif
