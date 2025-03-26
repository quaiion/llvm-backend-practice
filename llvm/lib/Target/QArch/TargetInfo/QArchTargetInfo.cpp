#include "TargetInfo/QArchTargetInfo.h"
#include "QArch.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheQArchTarget() {
  QARCH_DUMP_YELLOW
  static Target TheQArchTarget;
  return TheQArchTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeQArchTargetInfo() {
  QARCH_DUMP_YELLOW
  RegisterTarget<Triple::qarch> X(getTheQArchTarget(), "qarch",
                                  "quaiion's toy architecture", "QARCH");
}

