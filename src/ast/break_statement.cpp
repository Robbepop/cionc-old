#include "ast/break_statement.hpp"

namespace cion {
namespace ast {

	void BreakStatement::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void BreakStatement::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
