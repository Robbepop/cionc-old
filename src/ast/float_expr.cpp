#include "cion/ast/float_expr.hpp"

namespace cion {
namespace ast {

	FloatExpr::FloatExpr(
		FloatExpr::storage_type p_value,
		BuiltinFloatType::Width p_width
	):
		Expr{std::unique_ptr<Type>{std::make_unique<BuiltinFloatType>(p_width)}},
		m_value{p_value}
	{}

	FloatExpr::FloatExpr(
		FloatExpr::storage_type p_value
	):
		FloatExpr{p_value, BuiltinFloatType::Width::unspecified}
	{}

	FloatExpr::storage_type & FloatExpr::value() {
		return m_value;
	}

	FloatExpr::storage_type const& FloatExpr::value() const {
		return m_value;
	}

	void FloatExpr::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
