#ifndef CION_AST_COMPILATION_UNIT_DECL_HEADER
#define CION_AST_COMPILATION_UNIT_DECL_HEADER

#include "ast/decl.hpp"

#include <vector>
#include <memory>

namespace cion {
namespace ast {
	class CompilationUnitDecl : public Decl {
	public:
		CompilationUnitDecl(
			std::vector<std::unique_ptr<Decl>> top_level_decls);

		std::vector<std::unique_ptr<Decl>> & decls();
		std::vector<std::unique_ptr<Decl>> const& decls() const;

		virtual void accept(CompilerPass & pass) override;

	private:
		std::vector<std::unique_ptr<Decl>> m_decls;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_COMPILATION_UNIT_DECL_HEADER
