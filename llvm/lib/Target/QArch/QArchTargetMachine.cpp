#include "QArchTargetMachine.h"
#include "QArch.h"
#include "TargetInfo/QArchTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeQArchTarget() {
  // Register the target.
  QARCH_DUMP_CYAN
  RegisterTargetMachine<QArchTargetMachine> A(getTheQArchTarget());
}

QArchTargetMachine::QArchTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  QARCH_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// QArch Code Generator Pass Configuration Options.
class QArchPassConfig : public TargetPassConfig {
public:
  QArchPassConfig(QArchTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  QArchTargetMachine &getQArchTargetMachine() const {
    return getTM<QArchTargetMachine>();
  }

  bool addInstSelector() override {
    QARCH_DUMP_CYAN
    addPass(createQArchISelDag(getQArchTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *QArchTargetMachine::createPassConfig(PassManagerBase &PM) {
  QARCH_DUMP_CYAN
  return new QArchPassConfig(*this, PM);
}

TargetLoweringObjectFile *QArchTargetMachine::getObjFileLowering() const {
  QARCH_DUMP_CYAN
  return TLOF.get();
}
