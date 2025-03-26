add_llvm_component_library(LLVMQArchInfo
  QArchTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  QArch
  )

