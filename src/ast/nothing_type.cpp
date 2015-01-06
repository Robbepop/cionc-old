#include "ast/nothing_type.hpp"

namespace cion {
namespace ast {

	void NothingType::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void NothingType::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
