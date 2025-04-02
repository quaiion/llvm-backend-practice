#ifndef LLVM_LIB_TARGET_QARCH_MCTARGETDESC_QARCHMCASMINFO_H
#define LLVM_LIB_TARGET_QARCH_MCTARGETDESC_QARCHMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class QArchELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit QArchELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_QARCH_MCTARGETDESC_QARCHMCASMINFO_H
