#ifndef CION_AST_STATEMENT_LIST_HEADER
#define CION_AST_STATEMENT_LIST_HEADER

#include "ast/node.hpp"
#include "ast/statement.hpp"

#include <vector>
#include <memory>

namespace cion {
namespace ast {

	class StatementList : public Node {
	public:
		StatementList(std::vector<std::unique_ptr<Statement>> statements);

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::vector<std::unique_ptr<Statement>> m_statements;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_STATEMENT_LIST_HEADER
