add_llvm_component_group(QArch)

set(LLVM_TARGET_DEFINITIONS QArch.td)

tablegen(LLVM QArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM QArchGenInstrInfo.inc -gen-instr-info)

add_public_tablegen_target(QArchCommonTableGen)

add_llvm_target(QArchCodeGen
  QArchTargetMachine.cpp
  QArchRegisterInfo.cpp
  QArchInstrInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  QArchInfo

  ADD_TO_COMPONENT
  QArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)

