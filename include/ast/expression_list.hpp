#ifndef CION_AST_EXPRESSION_LIST_HEADER
#define CION_AST_EXPRESSION_LIST_HEADER

#include "ast/expr.hpp"

#include <vector>
#include <memory>

namespace cion {
namespace ast {

	class ExpressionList : public Expr {
	public:
		ExpressionList();
		ExpressionList(std::vector<std::unique_ptr<Expr>> expressions);

		std::vector<std::unique_ptr<Expr>> & expressions();
		std::vector<std::unique_ptr<Expr>> const& expressions() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::vector<std::unique_ptr<Expr>> m_expressions;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_EXPRESSION_LIST_HEADER
