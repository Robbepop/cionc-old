#include "ast/char_expr.hpp"

namespace cion {
namespace ast {

	CharExpr::CharExpr(CharExpr::storage_type value) :
		m_value{value}
	{}

	CharExpr::storage_type & CharExpr::value() {
		return m_value;
	}

	CharExpr::storage_type const& CharExpr::value() const {
		return m_value;
	}

	void CharExpr::accept(CompilerPass & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
