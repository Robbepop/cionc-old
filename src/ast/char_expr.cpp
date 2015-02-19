#include "cion/ast/char_expr.hpp"
#include "cion/ast/builtin_type.hpp"

namespace cion {
namespace ast {

	CharExpr::CharExpr(CharExpr::storage_type value) :
		Expr{std::unique_ptr<Type>{std::make_unique<BuiltinCharType>()}},
		m_value{value}
	{}

	CharExpr::storage_type & CharExpr::value() {
		return m_value;
	}

	CharExpr::storage_type const& CharExpr::value() const {
		return m_value;
	}

	void CharExpr::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
