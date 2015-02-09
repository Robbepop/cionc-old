#include "ast/break_stmnt.hpp"

namespace cion {
namespace ast {

	void BreakStmnt::accept(CompilerPass & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
