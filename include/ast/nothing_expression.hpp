#ifndef CION_AST_NOTHING_EXPRESSION_HEADER
#define CION_AST_NOTHING_EXPRESSION_HEADER

#include "ast/expression.hpp"

namespace cion {
namespace ast {
	class NothingExpression : public Expression {
	public:
		NothingExpression() = default;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_NOTHING_EXPRESSION_HEADER
