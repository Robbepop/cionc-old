#ifndef CION_AST_VARIABLE_DECLARATION_STATEMENT_HEADER
#define CION_AST_VARIABLE_DECLARATION_STATEMENT_HEADER

#include "ast/statement.hpp"
#include "ast/expression.hpp"
#include "ast/type_specifier.hpp"

#include <string>
#include <memory>

namespace cion {
namespace ast {

	class VariableDeclarationStatement : public Statement {
	public:
		VariableDeclarationStatement(VariableDeclarationStatement const& rhs) = delete;
		VariableDeclarationStatement & operator=(VariableDeclarationStatement const& rhs) = delete;

		VariableDeclarationStatement(
			std::string const& name,
			std::unique_ptr<TypeSpecifier> type_specifier,
			std::unique_ptr<Expression> expr);

		std::string & name();
		std::string const& name() const;

		TypeSpecifier & specified_type();
		TypeSpecifier const& specified_type() const;

		Expression & expr();
		Expression const& expr() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::string m_name;
		std::unique_ptr<TypeSpecifier> m_type_specifier;
		std::unique_ptr<Expression> m_expr;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_VARIABLE_DECLARATION_STATEMENT_HEADER
