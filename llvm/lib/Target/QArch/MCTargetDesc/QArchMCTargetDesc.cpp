#include "MCTargetDesc/QArchInfo.h"
#include "QArch.h"
#include "TargetInfo/QArchTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "QArchGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "QArchGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "QArchGenSubtargetInfo.inc"

static MCRegisterInfo *createQArchMCRegisterInfo(const Triple &TT) {
  QARCH_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitQArchMCRegisterInfo(X, QArch::R0);
  return X;
}

static MCInstrInfo *createQArchMCInstrInfo() {
  QARCH_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitQArchMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createQArchMCSubtargetInfo(const Triple &TT,
        StringRef CPU, StringRef FS) {
QARCH_DUMP_MAGENTA
return createQArchMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeQArchTargetMC() {
  QARCH_DUMP_MAGENTA
  Target &TheQArchTarget = getTheQArchTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheQArchTarget, createQArchMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheQArchTarget, createQArchMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheQArchTarget,
                                          createQArchMCSubtargetInfo);
}
