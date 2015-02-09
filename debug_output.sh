CMakeFiles/cion_compiler.dir/ast/builtin_int_type.cpp.o: In function `cion::ast::BuiltinType::BuiltinType()':
/home/robbepop/coding/c++/projects/cion/include/ast/builtin_type.hpp:9: undefined reference to `vtable for cion::ast::BuiltinType'
CMakeFiles/cion_compiler.dir/ast/builtin_int_type.cpp.o:(.rodata._ZTIN4cion3ast14BuiltinIntTypeE[_ZTIN4cion3ast14BuiltinIntTypeE]+0x10): undefined reference to `typeinfo for cion::ast::BuiltinType'
CMakeFiles/cion_compiler.dir/ast/builtin_bool_type.cpp.o:(.rodata._ZTIN4cion3ast15BuiltinBoolTypeE[_ZTIN4cion3ast15BuiltinBoolTypeE]+0x10): undefined reference to `typeinfo for cion::ast::BuiltinType'
CMakeFiles/cion_compiler.dir/ast/builtin_char_type.cpp.o:(.rodata._ZTIN4cion3ast15BuiltinCharTypeE[_ZTIN4cion3ast15BuiltinCharTypeE]+0x10): undefined reference to `typeinfo for cion::ast::BuiltinType'
CMakeFiles/cion_compiler.dir/ast/builtin_float_type.cpp.o:(.rodata._ZTIN4cion3ast16BuiltinFloatTypeE[_ZTIN4cion3ast16BuiltinFloatTypeE]+0x10): undefined reference to `typeinfo for cion::ast::BuiltinType'
CMakeFiles/cion_compiler.dir/parser/print_ast_pass.cpp.o: In function `cion::CompilerPass::CompilerPass()':
/home/robbepop/coding/c++/projects/cion/include/parser/compiler_pass.hpp:44: undefined reference to `vtable for cion::CompilerPass'
CMakeFiles/cion_compiler.dir/parser/print_ast_pass.cpp.o:(.rodata._ZTIN4cion12PrintASTPassE[_ZTIN4cion12PrintASTPassE]+0x10): undefined reference to `typeinfo for cion::CompilerPass'
collect2: error: ld returned 1 exit status
make[2]: *** [src/cion_compiler] Error 1
make[1]: *** [src/CMakeFiles/cion_compiler.dir/all] Error 2
make: *** [all] Error 2
