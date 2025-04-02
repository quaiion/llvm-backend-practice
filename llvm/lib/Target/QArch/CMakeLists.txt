add_llvm_component_group(QArch)

set(LLVM_TARGET_DEFINITIONS QArch.td)

tablegen(LLVM QArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM QArchGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM QArchGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM QArchGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM QArchGenDAGISel.inc -gen-dag-isel)

add_public_tablegen_target(QArchCommonTableGen)

add_llvm_target(QArchCodeGen
  QArchTargetMachine.cpp
  QArchRegisterInfo.cpp
  QArchInstrInfo.cpp
  QArchSubtarget.cpp
  QArchAsmPrinter.cpp
  QArchISelDagToDag.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  QArchInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  QArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
