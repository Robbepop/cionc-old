#include "cion/ast/break_stmnt.hpp"

namespace cion {
namespace ast {

	void BreakStmnt::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
