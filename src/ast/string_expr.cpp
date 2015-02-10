#include "ast/string_expr.hpp"

namespace cion {
namespace ast {

	StringExpr::StringExpr(StringExpr::storage_type value) :
		m_value{value}
	{}

	StringExpr::storage_type & StringExpr::value() {
		return m_value;
	}

	StringExpr::storage_type const& StringExpr::value() const {
		return m_value;
	}

	void StringExpr::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
