let TargetPrefix = "qarch" in {  // All intrinsics start with "llvm.qarch.".
 
 def int_qarch_putpixel: ClangBuiltin<"qarch_put_pixel">,
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_qarch_flush: ClangBuiltin<"qarch_flush">,
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_qarch_rand: ClangBuiltin<"qarch_rand">,
   Intrinsic<[llvm_i32_ty], [llvm_i32_ty, llvm_i32_ty], [IntrNoMem]>;
 
 def int_qarch_init: ClangBuiltin<"qarch_init">,
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_qarch_is_quit: ClangBuiltin<"qarch_is_quit">,
   Intrinsic<[llvm_i32_ty], [], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_qarch_quit: ClangBuiltin<"qarch_quit">,
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "qarch"
