#ifndef CION_AST_EXPR_HEADER
#define CION_AST_EXPR_HEADER

#include "ast/stmnt.hpp"
#include "compiler_pass.hpp"

namespace cion {
	class CompilerPass;

namespace ast {
	class Expr : public Stmnt {
	public:
		virtual void accept(CompilerPass & pass) = 0;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_EXPR_HEADER