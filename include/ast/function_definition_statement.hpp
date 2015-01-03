#ifndef CION_AST_FUNCTION_DEFINITION_STATEMENT_HEADER
#define CION_AST_FUNCTION_DEFINITION_STATEMENT_HEADER

#include "ast/statement.hpp"
#include "ast/logical_parameter_pack.hpp"
#include "ast/compound_statement.hpp"

#include <string>
#include <vector>
#include <memory>

namespace cion {
namespace ast {
	class FunctionDefinitionStatement : public Statement {
	public:
		FunctionDefinitionStatement(
			std::string const& name,
			std::unique_ptr<LogicalParameterPack> args,
			//std::vector<std::unique_ptr<LogicalParameter>> args,
			std::unique_ptr<TypeSpecifier> return_type,
			std::unique_ptr<CompoundStatement> body);

	private:
		std::string m_name;
		std::unique_ptr<LogicalParameterPack> m_args;
		//std::vector<std::unique_ptr<LogicalParameter>> m_args;
		std::unique_ptr<TypeSpecifier> m_return_type;
		std::unique_ptr<CompoundStatement> m_body;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_FUNCTION_DEFINITION_STATEMENT_HEADER
