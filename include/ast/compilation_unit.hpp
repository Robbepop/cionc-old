#ifndef CION_AST_COMPILATION_UNIT_HEADER
#define CION_AST_COMPILATION_UNIT_HEADER

#include "ast/node.hpp"
#include "ast/statement.hpp"

#include <vector>
#include <memory>

namespace cion {
namespace ast {
	class CompilationUnit : public Node {
	public:
		CompilationUnit(std::vector<std::unique_ptr<Statement>> top_level_statements);

		std::vector<std::unique_ptr<Statement>> & statements();
		std::vector<std::unique_ptr<Statement>> const& statements() const;

		virtual void accept(MutatingCompilerPass & pass) override;
		virtual void accept(CompilerPass & pass) const override;

	private:
		std::vector<std::unique_ptr<Statement>> m_top_level_statements;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_COMPILATION_UNIT_HEADER
