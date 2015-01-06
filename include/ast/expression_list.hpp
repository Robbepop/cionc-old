#ifndef CION_AST_EXPRESSION_LIST_HEADER
#define CION_AST_EXPRESSION_LIST_HEADER

#include "ast/expression.hpp"

#include <vector>
#include <memory>

namespace cion {
namespace ast {

	class ExpressionList : public Expression {
	public:
		ExpressionList();
		ExpressionList(std::vector<std::unique_ptr<Expression>> expressions);

		std::vector<std::unique_ptr<Expression>> & expressions();
		std::vector<std::unique_ptr<Expression>> const& expressions() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::vector<std::unique_ptr<Expression>> m_expressions;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_EXPRESSION_LIST_HEADER
