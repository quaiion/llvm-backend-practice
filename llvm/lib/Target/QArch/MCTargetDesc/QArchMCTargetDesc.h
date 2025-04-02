#ifndef LLVM_LIB_TARGET_QARCH_MCTARGETDESC_QARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_QARCH_MCTARGETDESC_QARCHMCTARGETDESC_H

// Defines symbolic names for QArch registers. This defines a mapping from
// register name to register number.

#define GET_REGINFO_ENUM
#include "QArchGenRegisterInfo.inc"

// Defines symbolic names for the QArch instructions.
#define GET_INSTRINFO_ENUM
#include "QArchGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_QARCH_MCTARGETDESC_QARCHMCTARGETDESC_H
