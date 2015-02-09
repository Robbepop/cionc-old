#ifndef CION_AST_INTEGER_EXPR_HEADER
#define CION_AST_INTEGER_EXPR_HEADER

#include "ast/expr.hpp"

#include <cstdint>

namespace cion {
namespace ast {
	class IntegerExpr : public Expr {
	public:
		using storage_type = int64_t;

		IntegerExpr(storage_type value);

		storage_type & value();
		storage_type const& value() const;

		virtual void accept(CompilerPass & pass) override;

	private:
		storage_type m_value;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_INTEGER_EXPR_HEADER
