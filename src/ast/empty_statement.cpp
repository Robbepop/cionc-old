#include "ast/empty_statement.hpp"

namespace cion {
namespace ast {

	void EmptyStatement::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void EmptyStatement::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
