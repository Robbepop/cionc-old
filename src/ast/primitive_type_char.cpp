#include "ast/primitive_type_char.hpp"

namespace cion {
namespace ast {

	void PrimitiveTypeChar::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void PrimitiveTypeChar::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
