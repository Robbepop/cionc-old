#include "ast/logical_parameter_pack.hpp"

#include <utility>

namespace cion {
namespace ast {

	LogicalParameterPack::LogicalParameterPack(
		std::vector<std::unique_ptr<LogicalParameter>> params
	):
		m_params{std::move(params)}
	{}

	std::vector<std::unique_ptr<LogicalParameter>> & LogicalParameterPack::params() {
		return m_params;
	}

	std::vector<std::unique_ptr<LogicalParameter>> const& LogicalParameterPack::params() const {
		return m_params;
	}

	void LogicalParameterPack::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void LogicalParameterPack::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
