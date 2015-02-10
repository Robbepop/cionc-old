#ifndef CION_AST_EMPTY_STMNT_HEADER
#define CION_AST_EMPTY_STMNT_HEADER

#include "cion/ast/stmnt.hpp"

namespace cion {
namespace ast {

	class EmptyStmnt : public Stmnt {
	public:
		EmptyStmnt() = default;

		virtual void accept(IASTVisitor & pass) override;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_EMPTY_STMNT_HEADER
