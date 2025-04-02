#ifndef LLVM_LIB_TARGET_QARCH_QARCHFRAMELOWERING_H
#define LLVM_LIB_TARGET_QARCH_QARCHFRAMELOWERING_H

#include "QArch.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class QArchSubtarget;

class QArchFrameLowering : public TargetFrameLowering {
public:
  QArchFrameLowering(const QArchSubtarget &STI)
      : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(4), 0),
        STI(STI) {
    QARCH_DUMP_GREEN
  }

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  void emitPrologue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}
  void emitEpilogue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}

  /// hasFP - Return true if the specified function should have a dedicated
  /// frame pointer register. For most targets this is true only if the function
  /// has variable sized allocas or if frame pointer elimination is disabled.
  bool hasFPImpl(const MachineFunction &MF) const override { return false; }

private:
  const QArchSubtarget &STI;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_QARCH_QARCHFRAMELOWERING_H
