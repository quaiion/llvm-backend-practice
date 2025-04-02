#ifndef LLVM_LIB_TARGET_QARCH_QARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_QARCH_QARCHTARGETMACHINE_H

#include "QArchSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheQArchTarget;

class QArchTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  QArchSubtarget Subtarget;

public:
  QArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                     StringRef FS, const TargetOptions &Options,
                     std::optional<Reloc::Model> RM,
                     std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                     bool JIT);

  const QArchSubtarget *getSubtargetImpl(const Function &) const override {
    QARCH_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_QARCH_QARCHTARGETMACHINE_H
