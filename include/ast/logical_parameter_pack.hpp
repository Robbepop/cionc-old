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

		std::vector<std::unique_ptr<LogicalParameter>> & params();
		std::vector<std::unique_ptr<LogicalParameter>> const& params() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::vector<std::unique_ptr<LogicalParameter>> m_params;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_LOGICAL_PARAMETER_PACK_HEADER
