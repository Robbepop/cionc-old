#ifndef CION_AST_NOTHING_EXPR_HEADER
#define CION_AST_NOTHING_EXPR_HEADER

#include "ast/expr.hpp"

namespace cion {
namespace ast {
	class NothingExpr : public Expr {
	public:
		NothingExpr() = default;

		virtual void accept(CompilerPass & pass) override;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_NOTHING_EXPR_HEADER
