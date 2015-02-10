#ifndef CION_AST_CHAR_EXPR_HEADER
#define CION_AST_CHAR_EXPR_HEADER

#include "cion/ast/expr.hpp"

namespace cion {
namespace ast {
	class CharExpr : public Expr {
	public:
		using storage_type = char;

		CharExpr(storage_type value);

		storage_type & value();
		storage_type const& value() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		storage_type m_value;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_CHAR_EXPR_HEADER
