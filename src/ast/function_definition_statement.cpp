#include "ast/function_definition_statement.hpp"

#include <utility>

namespace cion {
namespace ast {

	FunctionDefinitionStatement::FunctionDefinitionStatement(
		std::string const& name,
		std::unique_ptr<LogicalParameterPack> args,
		std::unique_ptr<TypeSpecifier> return_type,
		std::unique_ptr<CompoundStatement> body
	):
		m_name{name},
		m_args{std::move(args)},
		m_return_type{std::move(return_type)},
		m_body{std::move(body)}
	{}

} // namespace ast
} // namespace cion
