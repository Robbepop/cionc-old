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

		std::string & name();
		std::string const& name() const;

		TypeSpecifier & specified_type();
		TypeSpecifier const& specified_type() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::string m_name;
		std::unique_ptr<TypeSpecifier> m_type_specifier;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_LOGICAL_PARAMETER_HEADER
