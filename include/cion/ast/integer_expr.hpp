#ifndef CION_AST_INTEGER_EXPR_HEADER
#define CION_AST_INTEGER_EXPR_HEADER

#include "cion/ast/expr.hpp"
#include "cion/ast/builtin_type.hpp"

#include <cstdint>

namespace cion {
namespace ast {
	class IntegerExpr : public Expr {
	public:
		using storage_type = int64_t;

		IntegerExpr(storage_type p_value, bool p_signed, IntegerType::Width p_width);
		IntegerExpr(storage_type p_value, IntegerType::Width p_width);
		IntegerExpr(storage_type p_value, bool p_signed);
		explicit IntegerExpr(storage_type p_value);

		storage_type & value();
		storage_type const& value() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		storage_type m_value;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_INTEGER_EXPR_HEADER
