#ifndef LLVM_LIB_TARGET_QARCH_QARCHISELLOWERING_H
#define LLVM_LIB_TARGET_QARCH_QARCHISELLOWERING_H

#include "QArch.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class QArchSubtarget;
class QArchTargetMachine;

namespace QArchISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace QArchISD

} // end namespace llvm

#endif // LLVM_LIB_TARGET_QARCH_QARCHISELLOWERING_H
