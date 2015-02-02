#ifndef CION_AST_INTEGER_LITERAL_HEADER
#define CION_AST_INTEGER_LITERAL_HEADER

#include "ast/expr.hpp"

#include <cstdint>

namespace cion {
namespace ast {
	class IntegerLiteral : public Expr {
	public:
		using storage_type = int64_t;

		IntegerLiteral(storage_type value);

		storage_type & value();
		storage_type const& value() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		storage_type m_value;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_INTEGER_LITERAL_HEADER
