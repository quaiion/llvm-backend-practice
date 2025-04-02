#ifndef LLVM_LIB_TARGET_QARCH_QARCHREGISTERINFO_H
#define LLVM_LIB_TARGET_QARCH_QARCHREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "QArchGenRegisterInfo.inc"

namespace llvm {

struct QArchRegisterInfo : public QArchGenRegisterInfo {
public:
  QArchRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_QARCH_QARCHREGISTERINFO_H
