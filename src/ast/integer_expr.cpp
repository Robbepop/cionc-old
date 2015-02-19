#include "cion/ast/integer_expr.hpp"

namespace cion {
namespace ast {

	IntegerExpr::IntegerExpr(
		IntegerExpr::storage_type p_value,
		bool p_signed,
		BuiltinIntType::Width p_width
	):
		Expr{std::unique_ptr<Type>{std::make_unique<BuiltinIntType>(p_signed, p_width)}},
		m_value{p_value}
	{}

	IntegerExpr::IntegerExpr(
		IntegerExpr::storage_type p_value,
		BuiltinIntType::Width p_width
	):
		IntegerExpr{p_value, true, p_width}
	{}

	IntegerExpr::IntegerExpr(
		IntegerExpr::storage_type p_value,
		bool p_signed
	):
		IntegerExpr{p_value, p_signed, BuiltinIntType::Width::unspecified}
	{}

	IntegerExpr::IntegerExpr(IntegerExpr::storage_type p_value) :
		IntegerExpr{p_value, true, BuiltinIntType::Width::unspecified}
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
