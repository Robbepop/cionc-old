#include "ast/expression_list.hpp"

#include <utility>

namespace cion {
namespace ast {

	ExpressionList::ExpressionList(
		std::vector<std::unique_ptr<Expression>> expressions
	):
		m_expressions{std::move(expressions)}
	{}

	ExpressionList::ExpressionList() :
		m_expressions{}
	{}

	std::vector<std::unique_ptr<Expression>> & ExpressionList::expressions() {
		return m_expressions;
	}

	std::vector<std::unique_ptr<Expression>> const& ExpressionList::expressions() const {
		return m_expressions;
	}

	void ExpressionList::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void ExpressionList::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
