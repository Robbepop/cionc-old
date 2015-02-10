#ifndef CION_AST_STRING_EXPR_HEADER
#define CION_AST_STRING_EXPR_HEADER

#include "ast/expr.hpp"

#include <string>

namespace cion {
namespace ast {
	class StringExpr : public Expr {
	public:
		using storage_type = std::string;

		StringExpr(storage_type value);

		storage_type & value();
		storage_type const& value() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		storage_type m_value;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_STRING_EXPR_HEADER
