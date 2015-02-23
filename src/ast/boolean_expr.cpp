#include "cion/ast/boolean_expr.hpp"
#include "cion/ast/builtin_type.hpp"

namespace cion {
namespace ast {

	BooleanExpr::BooleanExpr(BooleanExpr::storage_type value) :
		Expr{std::unique_ptr<Type>{std::make_unique<BoolType>()}},
		m_value{value}
	{}

	BooleanExpr::storage_type & BooleanExpr::value() {
		return m_value;
	}

	BooleanExpr::storage_type const& BooleanExpr::value() const {
		return m_value;
	}

	void BooleanExpr::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
