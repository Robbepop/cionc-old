#include "cion/ast/expr.hpp"
#include "cion/ast/nothing_type.hpp"

namespace cion {
namespace ast {

	Expr::Expr(std::unique_ptr<Type> p_type):
		m_type{std::move(p_type)}
	{}

	Expr::Expr():
		Expr{std::unique_ptr<Type>{std::make_unique<NothingType>()}}
	{}

	Type & Expr::type() {
		return *m_type;
	}

	Type const& Expr::type() const {
		return *m_type;
	}

} // namespace ast
} // namespace cion
