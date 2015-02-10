#ifndef CION_AST_EXPR_HEADER
#define CION_AST_EXPR_HEADER

#include "ast/stmnt.hpp"
#include "parser/i_ast_visitor.hpp"

namespace cion {
	class IASTVisitor;

namespace ast {
	class Expr : public Stmnt {
	public:
		virtual void accept(IASTVisitor & pass) = 0;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_EXPR_HEADER
