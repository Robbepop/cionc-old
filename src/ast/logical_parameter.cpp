#include "ast/logical_parameter.hpp"

#include <utility>
#include <cassert>

namespace cion {
namespace ast {

	LogicalParameter::LogicalParameter(
		std::string const& name,
		std::unique_ptr<TypeSpecifier> type_specifier
	):
		m_name{name},
		m_type_specifier{std::move(type_specifier)}
	{}

	std::string & LogicalParameter::name() {
		return m_name;
	}

	std::string const& LogicalParameter::name() const {
		return m_name;
	}

	TypeSpecifier & LogicalParameter::specified_type() {
		assert(m_type_specifier != nullptr);
		return *m_type_specifier;
	}

	TypeSpecifier const& LogicalParameter::specified_type() const {
		assert(m_type_specifier != nullptr);
		return *m_type_specifier;
	}

	void LogicalParameter::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void LogicalParameter::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
