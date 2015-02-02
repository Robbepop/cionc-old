#include "ast/boolean_expr.hpp"

namespace cion {
namespace ast {

	BooleanExpr::BooleanExpr(BooleanExpr::storage_type value) :
		m_value{value}
	{}

	BooleanExpr::storage_type & BooleanExpr::value() {
		return m_value;
	}

	BooleanExpr::storage_type const& BooleanExpr::value() const {
		return m_value;
	}

	void BooleanExpr::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void BooleanExpr::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
