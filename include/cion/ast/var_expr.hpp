#ifndef CION_AST_VAR_EXPR_HEADER
#define CION_AST_VAR_EXPR_HEADER

#include "cion/ast/expr.hpp"

#include <string>

namespace cion {
namespace ast {

	class VarExpr : public Expr {
	public:
		VarExpr(std::string const& name);

		std::string & name();
		std::string const& name() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		std::string m_name;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_VAR_EXPR_HEADER
