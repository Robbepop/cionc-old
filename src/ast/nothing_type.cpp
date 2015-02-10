#include "cion/ast/nothing_type.hpp"

namespace cion {
namespace ast {

	void NothingType::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
