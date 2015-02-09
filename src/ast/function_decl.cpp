#include "ast/function_decl.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	FunctionDecl::FunctionDecl(
		std::string const& name,
		std::vector<std::unique_ptr<ParamDecl>> params,
		std::unique_ptr<Type> return_type,
		std::unique_ptr<CompoundStmnt> body
	):
		m_name{name},
		m_params{std::move(params)},
		m_return_type{std::move(return_type)},
		m_body{std::move(body)}
	{}

	std::string & FunctionDecl::name() {
		return m_name;
	}

	std::string const& FunctionDecl::name() const {
		return m_name;
	}

	std::vector<std::unique_ptr<ParamDecl>> & FunctionDecl::params() {
		return m_params;
	}

	std::vector<std::unique_ptr<ParamDecl>> const& FunctionDecl::params() const {
		return m_params;
	}

	Type & FunctionDecl::return_type() {
		assert(m_return_type != nullptr);
		return *m_return_type;
	}

	Type const& FunctionDecl::return_type() const {
		assert(m_return_type != nullptr);
		return *m_return_type;
	}

	CompoundStmnt & FunctionDecl::body() {
		assert(m_body != nullptr);
		return *m_body;
	}

	CompoundStmnt const& FunctionDecl::body() const {
		assert(m_body != nullptr);
		return *m_body;
	}

	void FunctionDecl::accept(CompilerPass & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
