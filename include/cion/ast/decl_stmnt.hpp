#ifndef CION_AST_DECL_STMNT_HEADER
#define CION_AST_DECL_STMNT_HEADER

#include "cion/ast/stmnt.hpp"
#include "cion/ast/decl.hpp"

#include <memory>

namespace cion {
namespace ast {

	class DeclStmnt : public Stmnt {
	public:
		DeclStmnt(std::unique_ptr<Decl> decl);

		Decl & decl();
		Decl const& decl() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		std::unique_ptr<Decl> m_decl;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_DECL_STMNT_HEADER
