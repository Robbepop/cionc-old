#ifndef CION_AST_VARIABLE_EXPRESSION_HEADER
#define CION_AST_VARIABLE_EXPRESSION_HEADER

#include "ast/expr.hpp"

#include <string>

namespace cion {
namespace ast {

	class VariableExpression : public Expr {
	public:
		VariableExpression(std::string const& name);

		std::string & name();
		std::string const& name() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::string m_name;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_VARIABLE_EXPRESSION_HEADER
