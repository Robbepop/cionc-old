#include "ast/if_statement.hpp"

#include <utility>

namespace cion {
namespace ast {

	IfStatement::IfStatement(
		std::unique_ptr<Expression> condition,
		std::unique_ptr<CompoundStatement> then_stmnt,
		std::unique_ptr<Statement> else_stmnt
	):
		m_condition{std::move(condition)},
		m_then_stmnt{std::move(then_stmnt)},
		m_else_stmnt{std::move(else_stmnt)}
	{}

} // namespace ast
} // namespace cion
