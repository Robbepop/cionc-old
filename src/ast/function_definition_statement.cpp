#include "ast/function_definition_statement.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	FunctionDefinitionStatement::FunctionDefinitionStatement(
		std::string const& name,
		std::unique_ptr<LogicalParameterPack> args,
		std::unique_ptr<TypeSpecifier> return_type,
		std::unique_ptr<CompoundStatement> body
	):
		m_name{name},
		m_args{std::move(args)},
		m_return_type{std::move(return_type)},
		m_body{std::move(body)}
	{}

	std::string & FunctionDefinitionStatement::name() {
		return m_name;
	}

	std::string const& FunctionDefinitionStatement::name() const {
		return m_name;
	}

	LogicalParameterPack & FunctionDefinitionStatement::args() {
		assert(m_args != nullptr);
		return *m_args;
	}

	LogicalParameterPack const& FunctionDefinitionStatement::args() const {
		assert(m_args != nullptr);
		return *m_args;
	}

	TypeSpecifier & FunctionDefinitionStatement::specified_type() {
		assert(m_return_type != nullptr);
		return *m_return_type;
	}

	TypeSpecifier const& FunctionDefinitionStatement::specified_type() const {
		assert(m_return_type != nullptr);
		return *m_return_type;
	}

	CompoundStatement & FunctionDefinitionStatement::body() {
		assert(m_body != nullptr);
		return *m_body;
	}

	CompoundStatement const& FunctionDefinitionStatement::body() const {
		assert(m_body != nullptr);
		return *m_body;
	}

	void FunctionDefinitionStatement::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void FunctionDefinitionStatement::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
