#include "ast/index_expression.hpp"

#include <cassert>

namespace cion {
namespace ast {

	IndexExpression::IndexExpression(
		std::unique_ptr<Expression> expr,
		std::unique_ptr<ExpressionList> indices
	):
		m_expr{std::move(expr)},
		m_indices{std::move(indices)}
	{}

	Expression & IndexExpression::expr() {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	Expression const& IndexExpression::expr() const {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	ExpressionList & IndexExpression::indices() {
		assert(m_indices != nullptr);
		return *m_indices;
	}

	ExpressionList const& IndexExpression::indices() const {
		assert(m_indices != nullptr);
		return *m_indices;
	}

	void IndexExpression::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void IndexExpression::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
