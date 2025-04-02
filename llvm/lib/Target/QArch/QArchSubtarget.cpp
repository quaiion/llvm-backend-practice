#include "QArchSubtarget.h"
#include "QArch.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "qarch-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "QArchGenSubtargetInfo.inc"

QArchSubtarget::QArchSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : QArchGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  QARCH_DUMP_CYAN
}
