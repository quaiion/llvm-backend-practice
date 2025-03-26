#ifndef LLVM_LIB_TARGET_QArch_QArch_H
#define LLVM_LIB_TARGET_QArch_QArch_H

#include "llvm/Support/raw_ostream.h"

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

#endif // LLVM_LIB_TARGET_QArch_QArch_H

