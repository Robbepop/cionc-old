#include "ast/float_expr.hpp"

namespace cion {
namespace ast {

	FloatExpr::FloatExpr(FloatExpr::storage_type value) :
		m_value{value}
	{}

	FloatExpr::storage_type & FloatExpr::value() {
		return m_value;
	}

	FloatExpr::storage_type const& FloatExpr::value() const {
		return m_value;
	}

	void FloatExpr::accept(CompilerPass & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
