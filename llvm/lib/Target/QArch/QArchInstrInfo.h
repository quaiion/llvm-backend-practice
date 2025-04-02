#ifndef LLVM_LIB_TARGET_QARCH_QARCHINSTRINFO_H
#define LLVM_LIB_TARGET_QARCH_QARCHINSTRINFO_H

#include "QArchRegisterInfo.h"
#include "MCTargetDesc/QArchInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "QArchGenInstrInfo.inc"

namespace llvm {

class QArchSubtarget;

class QArchInstrInfo : public QArchGenInstrInfo {
public:
  QArchInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_QARCH_QARCHINSTRINFO_H
