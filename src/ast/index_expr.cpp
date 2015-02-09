#include "ast/index_expr.hpp"

#include <cassert>

namespace cion {
namespace ast {

	IndexExpr::IndexExpr(
		std::unique_ptr<Expr> expr,
		std::vector<std::unique_ptr<Expr>> indices
	):
		m_expr{std::move(expr)},
		m_indices{std::move(indices)}
	{}

	Expr & IndexExpr::expr() {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	Expr const& IndexExpr::expr() const {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	std::vector<std::unique_ptr<Expr>> & IndexExpr::indices() {
		return m_indices;
	}

	std::vector<std::unique_ptr<Expr>> const& IndexExpr::indices() const {
		return m_indices;
	}

	void IndexExpr::accept(CompilerPass & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
