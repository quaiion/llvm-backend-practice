include "llvm/Target/Target.td"
include "QArchRegisterInfo.td"
include "QArchInstrInfo.td"
include "QArchCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def QArchInstrInfo : InstrInfo;
def QArch : Target {
  let InstructionSet = QArchInstrInfo;
}
