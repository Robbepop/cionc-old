#include "ast/variable_declaration_statement.hpp"

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

	VariableDeclarationStatement::VariableDeclarationStatement(
		std::string const& name,
		std::unique_ptr<TypeSpecifier> type_specifier,
		std::unique_ptr<Expr> expr
	):
		m_name{name},
		m_type_specifier{std::move(type_specifier)},
		m_expr{std::move(expr)}
	{}

	std::string & VariableDeclarationStatement::name() {
		return m_name;
	}

	std::string const& VariableDeclarationStatement::name() const {
		return m_name;
	}

	TypeSpecifier & VariableDeclarationStatement::specified_type() {
		assert(m_type_specifier != nullptr);
		return *m_type_specifier;
	}

	TypeSpecifier const& VariableDeclarationStatement::specified_type() const {
		assert(m_type_specifier != nullptr);
		return *m_type_specifier;
	}

	Expr & VariableDeclarationStatement::expr() {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	Expr const& VariableDeclarationStatement::expr() const {
		assert(m_expr != nullptr);
		return *m_expr;
	}

	void VariableDeclarationStatement::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void VariableDeclarationStatement::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
