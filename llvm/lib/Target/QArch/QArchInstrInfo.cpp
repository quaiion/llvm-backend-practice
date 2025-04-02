#include "QArchInstrInfo.h"
#include "QArch.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "QArchGenInstrInfo.inc"

#define DEBUG_TYPE "QArch-inst-info"

QArchInstrInfo::QArchInstrInfo() : QArchGenInstrInfo() { QARCH_DUMP_GREEN }
