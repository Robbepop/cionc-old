#ifndef CION_AST_CALL_EXPR_HEADER
#define CION_AST_CALL_EXPR_HEADER

#include "ast/expr.hpp"
#include "ast/expression_list.hpp"

#include <string>
#include <memory>

namespace cion {
namespace ast {
	class CallExpression : public Expr {
	public:
		CallExpression(
			std::unique_ptr<Expr> callee,
			std::unique_ptr<ExpressionList> args);

		CallExpression(
			std::unique_ptr<Expr> callee);

		Expr & callee();
		Expr const& callee() const;

		ExpressionList & args();
		ExpressionList const& args() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::unique_ptr<Expr> m_callee;
		std::unique_ptr<ExpressionList> m_args;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_CALL_EXPR_HEADER
