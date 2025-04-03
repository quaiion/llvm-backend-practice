add_llvm_component_library(LLVMQArchDesc
  QArchMCTargetDesc.cpp
  QArchMCAsmInfo.cpp
  QArchInstPrinter.cpp
  QArchMCCodeEmitter.cpp
  QArchAsmBackend.cpp
  QArchELFObjectWriter.cpp

  LINK_COMPONENTS
  MC
  Support
  QArchInfo

  ADD_TO_COMPONENT
  QArch
 )

