#include "cion/ast/function_decl.hpp"
#include "cion/ast/type.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	FunctionDecl::FunctionDecl(
		std::string const& p_name,
		std::vector<std::unique_ptr<ParamDecl>> p_params,
		std::unique_ptr<Type> p_return_type,
		std::unique_ptr<CompoundStmnt> p_body
	):
		m_name{p_name},
		m_params{std::move(p_params)},
		m_return_type{std::move(p_return_type)},
		m_body{std::move(p_body)}
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

	void FunctionDecl::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
