#include "QArchRegisterInfo.h"
#include "QArch.h"
#include "QArchFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "QArchGenRegisterInfo.inc"

QArchRegisterInfo::QArchRegisterInfo() : QArchGenRegisterInfo(QArch::R0) {
  QARCH_DUMP_GREEN
}
