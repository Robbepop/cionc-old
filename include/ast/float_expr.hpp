#ifndef CION_AST_FLOAT_EXPR_HEADER
#define CION_AST_FLOAT_EXPR_HEADER

#include "ast/expr.hpp"

namespace cion {
namespace ast {
	class FloatExpr : public Expr {
	public:
		using storage_type = double;

		FloatExpr(storage_type value);

		storage_type & value();
		storage_type const& value() const;

		virtual void accept(CompilerPass & pass) override;

	private:
		storage_type m_value;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_FLOAT_EXPR_HEADER
