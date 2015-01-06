#include "ast/variable_expression.hpp"

namespace cion {
namespace ast {

	VariableExpression::VariableExpression(std::string const& name) :
		m_name{name}
	{}

	void VariableExpression::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void VariableExpression::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
