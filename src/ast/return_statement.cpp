#include "ast/return_statement.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	ReturnStatement::ReturnStatement(
		std::unique_ptr<Expression> expr
	):
		m_expr{std::move(expr)}
	{}

	ReturnStatement::ReturnStatement() :
		ReturnStatement{nullptr}
	{}

	Expression & ReturnStatement::expr() {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	Expression const& ReturnStatement::expr() const {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	void ReturnStatement::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void ReturnStatement::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
