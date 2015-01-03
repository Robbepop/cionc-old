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

} // namespace ast
} // namespace cion
