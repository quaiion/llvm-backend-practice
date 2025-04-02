include "llvm/Target/Target.td"
include "QArchRegisterInfo.td"
include "QArchInstrInfo.td"

def QArchInstrInfo : InstrInfo;
def QArch : Target {
  let InstructionSet = QArchInstrInfo;
}
