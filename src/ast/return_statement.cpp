#include "ast/return_statement.hpp"

#include <utility>

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

	void ReturnStatement::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void ReturnStatement::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
