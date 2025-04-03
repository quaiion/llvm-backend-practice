#include "MCTargetDesc/QArchMCTargetDesc.h"
#include "QArch.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCValue.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

namespace {
class QArchELFObjectWriter : public MCELFObjectTargetWriter {
public:
  QArchELFObjectWriter(bool Is64Bit, uint8_t OSABI)
      : MCELFObjectTargetWriter(Is64Bit, OSABI, ELF::EM_QARCH,
                                /*HasRelocationAddend*/ true) {}

  ~QArchELFObjectWriter() override = default;

protected:
  unsigned getRelocType(MCContext &Ctx, const MCValue &Target,
                        const MCFixup &Fixup, bool IsPCRel) const override;

  bool needsRelocateWithSymbol(const MCValue &Val, const MCSymbol &Sym,
                               unsigned Type) const override;
};
} // namespace

unsigned QArchELFObjectWriter::getRelocType(MCContext &Ctx, const MCValue &Target,
                                            const MCFixup &Fixup,
                                            bool IsPCRel) const {
  MCFixupKind Kind = Fixup.getKind();
  if (Kind >= FirstLiteralRelocationKind)
    return Kind - FirstLiteralRelocationKind;

  llvm_unreachable("Unimplemented fixup -> relocation");
}

bool QArchELFObjectWriter::needsRelocateWithSymbol(const MCValue &,
                                                   const MCSymbol &,
                                                   unsigned Type) const {
  return false;
}

std::unique_ptr<MCObjectTargetWriter>
llvm::createQArchELFObjectWriter(bool Is64Bit, uint8_t OSABI) {
  return std::make_unique<QArchELFObjectWriter>(Is64Bit, OSABI);
}
