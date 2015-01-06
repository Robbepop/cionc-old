#ifndef CION_AST_COMPOUND_STATEMENT_HEADER
#define CION_AST_COMPOUND_STATEMENT_HEADER

#include "ast/statement.hpp"

#include <vector>
#include <memory>

namespace cion {
namespace ast {

	class CompoundStatement : public Statement {
	public:
		CompoundStatement(std::vector<std::unique_ptr<Statement>> statements);

		std::vector<std::unique_ptr<Statement>> & statements();
		std::vector<std::unique_ptr<Statement>> const& statements() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::vector<std::unique_ptr<Statement>> m_statements;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_COMPOUND_STATEMENT_HEADER
