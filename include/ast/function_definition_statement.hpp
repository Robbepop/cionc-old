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
			std::unique_ptr<TypeSpecifier> return_type,
			std::unique_ptr<CompoundStatement> body);

		std::string & name();
		std::string const& name() const;

		LogicalParameterPack & args();
		LogicalParameterPack const& args() const;

		TypeSpecifier & specified_type();
		TypeSpecifier const& specified_type() const;

		CompoundStatement & body();
		CompoundStatement const& body() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::string m_name;
		std::unique_ptr<LogicalParameterPack> m_args;
		std::unique_ptr<TypeSpecifier> m_return_type;
		std::unique_ptr<CompoundStatement> m_body;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_FUNCTION_DEFINITION_STATEMENT_HEADER
