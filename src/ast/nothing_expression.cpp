#include "ast/nothing_expression.hpp"

namespace cion {
namespace ast {

	void NothingExpression::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void NothingExpression::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
