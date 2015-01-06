#ifndef CION_AST_WHILE_STATEMENT_HEADER
#define CION_AST_WHILE_STATEMENT_HEADER

#include "ast/statement.hpp"
#include "ast/compound_statement.hpp"
#include "ast/expression.hpp"

#include <memory>

namespace cion {
namespace ast {

	class WhileStatement : public Statement {
	public:
		WhileStatement(
			std::unique_ptr<Expression> condition,
			std::unique_ptr<CompoundStatement> body);

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::unique_ptr<Expression> m_condition;
		std::unique_ptr<CompoundStatement> m_body;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_WHILE_STATEMENT_HEADER
