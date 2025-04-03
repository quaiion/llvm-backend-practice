#ifndef LLVM_LIB_TARGET_QARCH_MCTARGETDESC_QARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_QARCH_MCTARGETDESC_QARCHMCTARGETDESC_H

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createQArchMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createQArchAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                    const MCRegisterInfo &MRI,
                                    const MCTargetOptions &Options);
} // namespace llvm

// Defines symbolic names for QArch registers. This defines a mapping from
// register name to register number.

#define GET_REGINFO_ENUM
#include "QArchGenRegisterInfo.inc"

// Defines symbolic names for the QArch instructions.
#define GET_INSTRINFO_ENUM
#include "QArchGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_QARCH_MCTARGETDESC_QARCHMCTARGETDESC_H
