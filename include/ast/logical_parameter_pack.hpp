#ifndef CION_AST_LOGICAL_PARAMETER_PACK_HEADER
#define CION_AST_LOGICAL_PARAMETER_PACK_HEADER

#include "ast/node.hpp"
#include "ast/logical_parameter.hpp"

#include <vector>
#include <memory>

namespace cion {
namespace ast {

	class LogicalParameterPack : public Node {
	public:
		LogicalParameterPack(std::vector<std::unique_ptr<LogicalParameter>> args);

	private:
		std::vector<std::unique_ptr<LogicalParameter>> m_args;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_LOGICAL_PARAMETER_PACK_HEADER