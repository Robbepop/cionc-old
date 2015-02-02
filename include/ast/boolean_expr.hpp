#ifndef CION_AST_BOOLEAN_LITERAL_HEADER
#define CION_AST_BOOLEAN_LITERAL_HEADER

#include "ast/expr.hpp"

namespace cion {
namespace ast {
	class BooleanExpr : public Expr {
	public:
		using storage_type = bool;

		BooleanExpr(storage_type value);

		storage_type & value();
		storage_type const& value() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		storage_type m_value;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_BOOLEAN_LITERAL_HEADER
