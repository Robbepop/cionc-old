#ifndef CION_AST_EXPR_HEADER
#define CION_AST_EXPR_HEADER

#include "cion/ast/stmnt.hpp"
#include "cion/ast/type.hpp"
#include "cion/parser/i_ast_visitor.hpp"

#include <memory>

namespace cion {
	class IASTVisitor;

namespace ast {
	class Expr : public Stmnt {
	public:
		Expr();
		explicit Expr(std::unique_ptr<Type> p_type);

		virtual Type & type();
		virtual Type const& type() const;

		virtual void accept(IASTVisitor & pass) = 0;

	protected:
		std::unique_ptr<Type> m_type;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_EXPR_HEADER
