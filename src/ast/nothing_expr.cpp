#include "cion/ast/nothing_expr.hpp"

namespace cion {
namespace ast {

	void NothingExpr::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
