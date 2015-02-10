#include "cion/ast/var_expr.hpp"

namespace cion {
namespace ast {

	VarExpr::VarExpr(std::string const& name) :
		m_name{name}
	{}

	std::string & VarExpr::name() {
		return m_name;
	}

	std::string const& VarExpr::name() const {
		return m_name;
	}

	void VarExpr::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
