#ifndef CION_AST_EMPTY_STATEMENT_HEADER
#define CION_AST_EMPTY_STATEMENT_HEADER

#include "ast/statement.hpp"

namespace cion {
namespace ast {

	class EmptyStatement : public Statement {
	public:
		EmptyStatement() = default;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_EMPTY_STATEMENT_HEADER
