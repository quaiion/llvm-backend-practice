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
const MCPhysReg *
QArchRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  QARCH_DUMP_GREEN
  return CSR_QArch_SaveList;
}

BitVector QArchRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  QARCH_DUMP_GREEN
  QArchFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(QArch::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(QArch::R2);
  }
  return Reserved;
}

bool QArchRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool QArchRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  QARCH_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register QArchRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  QARCH_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? QArch::R2 : QArch::R1;
}

const uint32_t *
QArchRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  QARCH_DUMP_GREEN
  return CSR_QArch_RegMask;
}
