#ifndef LLVM_LIB_TARGET_QArch_QArch_H
#define LLVM_LIB_TARGET_QArch_QArch_H

#include "MCTargetDesc/QArchMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define QARCH_DUMP(Color)                                                      \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define QARCH_DUMP(Color) {}

#define QARCH_DUMP_RED QARCH_DUMP(llvm::raw_ostream::RED)
#define QARCH_DUMP_GREEN QARCH_DUMP(llvm::raw_ostream::GREEN)
#define QARCH_DUMP_YELLOW QARCH_DUMP(llvm::raw_ostream::YELLOW)
#define QARCH_DUMP_CYAN QARCH_DUMP(llvm::raw_ostream::CYAN)
#define QARCH_DUMP_MAGENTA QARCH_DUMP(llvm::raw_ostream::MAGENTA)
#define QARCH_DUMP_WHITE QARCH_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class QArchTargetMachine;
class FunctionPass;
class QArchSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerQArchMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                    AsmPrinter &AP);
bool LowerQArchMachineOperandToMCOperand(const MachineOperand &MO,
                                         MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createQArchISelDag(QArchTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_QArch_QArch_H
