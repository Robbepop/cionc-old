#include "ast/variable_declaration_statement.hpp"

#include <utility>

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
		std::unique_ptr<Expression> expr
	):
		m_name{name},
		m_type_specifier{std::move(type_specifier)},
		m_expr{std::move(expr)}
	{}

	void VariableDeclarationStatement::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void VariableDeclarationStatement::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
