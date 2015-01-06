#include "ast/logical_parameter_pack.hpp"

#include <utility>

namespace cion {
namespace ast {

	LogicalParameterPack::LogicalParameterPack(
		std::vector<std::unique_ptr<LogicalParameter>> args
	):
		m_args{std::move(args)}
	{}

	void LogicalParameterPack::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void LogicalParameterPack::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
