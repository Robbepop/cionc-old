#ifndef CION_AST_BREAK_STATEMENT_HEADER
#define CION_AST_BREAK_STATEMENT_HEADER

#include "ast/statement.hpp"

namespace cion {
namespace ast {

	class BreakStatement : public Statement {
	public:
		BreakStatement() = default;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_BREAK_STATEMENT_HEADER
