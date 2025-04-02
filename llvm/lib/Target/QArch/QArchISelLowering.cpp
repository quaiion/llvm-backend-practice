#include "QArchISelLowering.h"
#include "QArch.h"
#include "QArchRegisterInfo.h"
#include "QArchSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "QArch-lower"

using namespace llvm;

QArchTargetLowering::QArchTargetLowering(const TargetMachine &TM,
                                     const QArchSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  QARCH_DUMP_RED
  addRegisterClass(MVT::i32, &QArch::GPRRegClass);
}

const char *QArchTargetLowering::getTargetNodeName(unsigned Opcode) const {
  QARCH_DUMP_RED
  switch (Opcode) {
  case QArchISD::CALL:
    return "QArchISD::CALL";
  case QArchISD::RET:
    return "QArchISD::RET";
  }
  return nullptr;
}
