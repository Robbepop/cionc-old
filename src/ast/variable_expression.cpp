#include "ast/variable_expression.hpp"

namespace cion {
namespace ast {

	VariableExpression::VariableExpression(std::string const& name) :
		m_name{name}
	{}

} // namespace ast
} // namespace cion
