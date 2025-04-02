#ifndef LLVM_LIB_TARGET_QARCH_INSTPRINTER_QARCHINSTPRINTER_H
#define LLVM_LIB_TARGET_QARCH_INSTPRINTER_QARCHINSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCRegister.h"

namespace llvm {

class QArchInstPrinter : public MCInstPrinter {
public:
  QArchInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                 const MCRegisterInfo &MRI)
      : MCInstPrinter(MAI, MII, MRI) {}

  std::pair<const char *, uint64_t>
  getMnemonic(const MCInst &MI) const override {}

  // Override MCInstPrinter.
  void printRegName(raw_ostream &O, MCRegister Reg) override {}
  void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                 const MCSubtargetInfo &STI, raw_ostream &O) override {}
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_QARCH_INSTPRINTER_QARCHINSTPRINTER_H
