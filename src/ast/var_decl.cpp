#include "cion/ast/var_decl.hpp"

#include <utility>
#include <cassert>

#define DEBUG
#ifdef DEBUG
#include <iostream>
#define DEBUG_STDOUT(x) (std::cout << x)
#define DEBUG_STDERR(x) (std::cerr << x)
#undef DEBUG
#else
#define DEBUG_STDOUT(x)
#define DEBUG_STDERR(x)
#endif

namespace cion {
namespace ast {

	VarDecl::VarDecl(
		std::string const& p_name,
		std::unique_ptr<Type> p_type,
		std::unique_ptr<Expr> p_expr
	):
		m_name{p_name},
		m_type{std::move(p_type)},
		m_expr{std::move(p_expr)}
	{}

	std::string & VarDecl::name() {
		return m_name;
	}

	std::string const& VarDecl::name() const {
		return m_name;
	}

	Type & VarDecl::type() {
		assert(m_type != nullptr);
		return *m_type;
	}

	Type const& VarDecl::type() const {
		assert(m_type != nullptr);
		return *m_type;
	}

	Expr & VarDecl::expr() {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	Expr const& VarDecl::expr() const {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	void VarDecl::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
