#ifndef CION_AST_NOTHING_EXPR_HEADER
#define CION_AST_NOTHING_EXPR_HEADER

#include "cion/ast/expr.hpp"

namespace cion {
namespace ast {
	class NothingExpr : public Expr {
	public:
		NothingExpr() = default;

		virtual void accept(IASTVisitor & pass) override;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_NOTHING_EXPR_HEADER
