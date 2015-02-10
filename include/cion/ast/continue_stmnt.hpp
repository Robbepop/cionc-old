#ifndef CION_AST_CONTINUE_STMNT_HEADER
#define CION_AST_CONTINUE_STMNT_HEADER

#include "cion/ast/stmnt.hpp"

namespace cion {
namespace ast {

	class ContinueStmnt : public Stmnt {
	public:
		ContinueStmnt() = default;

		virtual void accept(IASTVisitor & pass) override;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_CONTINUE_STMNT_HEADER
