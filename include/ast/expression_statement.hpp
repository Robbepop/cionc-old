#ifndef CION_AST_EXPRESSION_STATEMENT_HEADER
#define CION_AST_EXPRESSION_STATEMENT_HEADER

#include "ast/statement.hpp"
#include "ast/expression.hpp"

#include <memory>

namespace cion {
namespace ast {

	class ExpressionStatement : public Statement {
	public:
		ExpressionStatement(std::unique_ptr<Expression> expr);

	private:
		std::unique_ptr<Expression> m_expr;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_EXPRESSION_STATEMENT_HEADER