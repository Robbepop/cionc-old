#ifndef CION_AST_BREAK_STMNT_HEADER
#define CION_AST_BREAK_STMNT_HEADER

#include "cion/ast/stmnt.hpp"

namespace cion {
namespace ast {

	class BreakStmnt : public Stmnt {
	public:
		BreakStmnt() = default;

		virtual void accept(IASTVisitor & pass) override;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_BREAK_STMNT_HEADER
