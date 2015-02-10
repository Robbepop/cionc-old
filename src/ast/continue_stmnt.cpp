#include "ast/continue_stmnt.hpp"

namespace cion {
namespace ast {

	void ContinueStmnt::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
