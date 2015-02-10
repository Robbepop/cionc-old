#include "cion/ast/integer_expr.hpp"

namespace cion {
namespace ast {

	IntegerExpr::IntegerExpr(IntegerExpr::storage_type value) :
		m_value{value}
	{}

	IntegerExpr::storage_type & IntegerExpr::value() {
		return m_value;
	}

	IntegerExpr::storage_type const& IntegerExpr::value() const {
		return m_value;
	}

	void IntegerExpr::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
