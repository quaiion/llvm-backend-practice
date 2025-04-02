#include "QArch.h"
#include "TargetInfo/QArchTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "QArchGenRegisterInfo.inc"

static MCRegisterInfo *createQArchMCRegisterInfo(const Triple &TT) {
  QARCH_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitQArchMCRegisterInfo(X, QArch::R0);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeQArchTargetMC() {
  QARCH_DUMP_MAGENTA
  Target &TheQArchTarget = getTheQArchTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheQArchTarget, createQArchMCRegisterInfo);
}
