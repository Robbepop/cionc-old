#ifndef CION_AST_IF_STATEMENT_HEADER
#define CION_AST_IF_STATEMENT_HEADER

#include "ast/statement.hpp"
#include "ast/compound_statement.hpp"
#include "ast/expression.hpp"

#include <memory>

namespace cion {
namespace ast {

	class IfStatement : public Statement {
	public:
		IfStatement(
			std::unique_ptr<Expression> condition,
			std::unique_ptr<Statement> then_stmnt,
			std::unique_ptr<Statement> else_stmnt = nullptr);

		Expression & condition();
		Expression const& condition() const;

		Statement & then_stmnt();
		Statement const& then_stmnt() const;

		Statement & else_stmnt();
		Statement const& else_stmnt() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::unique_ptr<Expression> m_condition;
		std::unique_ptr<Statement> m_then_stmnt;
		std::unique_ptr<Statement> m_else_stmnt;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_IF_STATEMENT_HEADER
