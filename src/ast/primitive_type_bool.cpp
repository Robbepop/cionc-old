#include "ast/primitive_type_bool.hpp"

namespace cion {
namespace ast {

	void PrimitiveTypeBool::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void PrimitiveTypeBool::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
