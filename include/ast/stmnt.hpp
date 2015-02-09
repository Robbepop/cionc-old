#ifndef CION_AST_STMNT_HEADER
#define CION_AST_STMNT_HEADER

#include "compiler_pass.hpp"

namespace cion {
	class CompilerPass;

namespace ast {
	class Stmnt {
	public:
		virtual void accept(CompilerPass & pass) = 0;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_STMNT_HEADER
