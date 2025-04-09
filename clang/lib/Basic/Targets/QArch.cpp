#include "QArch.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

void QArchTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__qarch__");
}

ArrayRef<Builtin::Info> QArchTargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}
