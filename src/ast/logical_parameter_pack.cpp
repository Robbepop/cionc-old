#include "ast/logical_parameter_pack.hpp"

#include <utility>

namespace cion {
namespace ast {

	LogicalParameterPack::LogicalParameterPack(
		std::vector<std::unique_ptr<LogicalParameter>> args
	):
		m_args{std::move(args)}
	{}

} // namespace ast
} // namespace cion
