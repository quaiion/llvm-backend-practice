#ifndef LLVM_LIB_TARGET_QARCH_MCTARGETDESC_QARCHINFO_H
#define LLVM_LIB_TARGET_QARCH_MCTARGETDESC_QARCHINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace QArchOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace QArchOp

} // end namespace llvm

#endif
