#include "ast/call_expression.hpp"

#include <cassert>

namespace cion {
namespace ast {

	CallExpression::CallExpression(
		std::unique_ptr<Expr> callee,
		std::unique_ptr<ExpressionList> args
	):
		m_callee{std::move(callee)},
		m_args{std::move(args)}
	{}

	CallExpression::CallExpression(
		std::unique_ptr<Expr> callee
	):
		CallExpression{std::move(callee), std::make_unique<ExpressionList>()}
	{}

	Expr & CallExpression::callee() {
		assert(m_callee != nullptr);
		return *m_callee;
	}

	Expr const& CallExpression::callee() const {
		assert(m_callee != nullptr);
		return *m_callee;
	}

	ExpressionList & CallExpression::args() {
		assert(m_args != nullptr);
		return *m_args;
	}

	ExpressionList const& CallExpression::args() const {
		assert(m_args != nullptr);
		return *m_args;
	}

	void CallExpression::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void CallExpression::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
