#include "ast/continue_statement.hpp"

namespace cion {
namespace ast {

	void ContinueStatement::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void ContinueStatement::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
