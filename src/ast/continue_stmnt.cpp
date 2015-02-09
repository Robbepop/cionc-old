#include "ast/continue_stmnt.hpp"

namespace cion {
namespace ast {

	void ContinueStmnt::accept(CompilerPass & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
