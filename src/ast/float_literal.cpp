#include "ast/float_literal.hpp"

namespace cion {
namespace ast {

	FloatLiteral::FloatLiteral(FloatLiteral::storage_type value) :
		m_value{value}
	{}

} // namespace ast
} // namespace cion
