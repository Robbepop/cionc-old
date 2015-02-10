#ifndef CION_AST_COMPOUND_STMNT_HEADER
#define CION_AST_COMPOUND_STMNT_HEADER

#include "cion/ast/stmnt.hpp"

#include <vector>
#include <memory>

namespace cion {
namespace ast {

	class CompoundStmnt : public Stmnt {
	public:
		CompoundStmnt(
			std::vector<std::unique_ptr<Stmnt>> statements);

		std::vector<std::unique_ptr<Stmnt>> & statements();
		std::vector<std::unique_ptr<Stmnt>> const& statements() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		std::vector<std::unique_ptr<Stmnt>> m_statements;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_COMPOUND_STMNT_HEADER
