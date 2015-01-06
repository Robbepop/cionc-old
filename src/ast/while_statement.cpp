#include "ast/while_statement.hpp"

#include <utility>

namespace cion {
namespace ast {

	WhileStatement::WhileStatement(
		std::unique_ptr<Expression> condition,
		std::unique_ptr<CompoundStatement> body
	):
		m_condition{std::move(condition)},
		m_body{std::move(body)}
	{}

	void WhileStatement::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void WhileStatement::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
