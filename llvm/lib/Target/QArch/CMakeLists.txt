add_llvm_component_group(QArch)

add_llvm_target(QArchCodeGen
  QArchTargetMachine.cpp

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

