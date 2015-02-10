#include "ast/empty_stmnt.hpp"

namespace cion {
namespace ast {

	void EmptyStmnt::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
