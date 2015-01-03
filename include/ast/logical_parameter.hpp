#ifndef CION_AST_LOGICAL_PARAMETER_HEADER
#define CION_AST_LOGICAL_PARAMETER_HEADER

#include "ast/node.hpp"
#include "ast/type_specifier.hpp"

#include <string>
#include <memory>

namespace cion {
namespace ast {
	class LogicalParameter : public Node {
	public:
		LogicalParameter(std::string const& name, std::unique_ptr<TypeSpecifier> type_specifier);

	private:
		std::string m_name;
		std::unique_ptr<TypeSpecifier> m_type_specifier;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_LOGICAL_PARAMETER_HEADER
