#ifndef CION_AST_RETURN_STATEMENT_HEADER
#define CION_AST_RETURN_STATEMENT_HEADER

#include "ast/statement.hpp"
#include "ast/expression.hpp"

#include <memory>

namespace cion {
namespace ast {

	class ReturnStatement : public Statement {
	public:
		ReturnStatement(std::unique_ptr<Expression> expr);
		ReturnStatement();

	private:
		std::unique_ptr<Expression> m_expr;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_RETURN_STATEMENT_HEADER
