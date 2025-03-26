add_llvm_component_library(LLVMQArchDesc
  QArchMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  Support
  QArchInfo

  ADD_TO_COMPONENT
  QArch
 )

