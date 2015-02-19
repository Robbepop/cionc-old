#ifndef CION_AST_FLOAT_EXPR_HEADER
#define CION_AST_FLOAT_EXPR_HEADER

#include "cion/ast/expr.hpp"
#include "cion/ast/builtin_type.hpp"

namespace cion {
namespace ast {
	class FloatExpr : public Expr {
	public:
		using storage_type = double;

		FloatExpr(storage_type p_value);
		FloatExpr(storage_type p_value, BuiltinFloatType::Width p_width);

		storage_type & value();
		storage_type const& value() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		storage_type m_value;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_FLOAT_EXPR_HEADER
