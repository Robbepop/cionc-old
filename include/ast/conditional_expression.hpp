#ifndef CION_AST_CONDITIONAL_EXPRESSION_HEADER
#define CION_AST_CONDITIONAL_EXPRESSION_HEADER

#include "ast/expr.hpp"

#include <memory>

namespace cion {
namespace ast {

	class ConditionalExpression : public Expr {
	public:
		ConditionalExpression(
			std::unique_ptr<Expr> conditional,
			std::unique_ptr<Expr> then_expression,
			std::unique_ptr<Expr> else_expression);

		Expr & condition();
		Expr const& condition() const;

		Expr & then_expr();
		Expr const& then_expr() const;

		Expr & else_expr();
		Expr const& else_expr() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::unique_ptr<Expr> m_condition;
		std::unique_ptr<Expr> m_then_expression;
		std::unique_ptr<Expr> m_else_expression;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_CONDITIONAL_EXPRESSION_HEADER
