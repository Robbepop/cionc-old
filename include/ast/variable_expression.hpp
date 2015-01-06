#ifndef CION_AST_VARIABLE_EXPRESSION_HEADER
#define CION_AST_VARIABLE_EXPRESSION_HEADER

#include "ast/expression.hpp"

#include <string>

namespace cion {
namespace ast {

	class VariableExpression : public Expression {
	public:
		VariableExpression(std::string const& name);

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::string m_name;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_VARIABLE_EXPRESSION_HEADER
