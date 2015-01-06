#include "ast/logical_parameter.hpp"

#include <utility>

namespace cion {
namespace ast {

	LogicalParameter::LogicalParameter(
		std::string const& name,
		std::unique_ptr<TypeSpecifier> type_specifier
	):
		m_name{name},
		m_type_specifier{std::move(type_specifier)}
	{}

	void LogicalParameter::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void LogicalParameter::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
