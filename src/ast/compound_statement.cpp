#include "ast/compound_statement.hpp"

#include <utility>

namespace cion {
namespace ast {

	CompoundStatement::CompoundStatement(
		std::vector<std::unique_ptr<Statement>> statements
	):
		m_statements{std::move(statements)}
	{}

} // namespace ast
} // namespace cion
