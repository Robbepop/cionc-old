#ifndef CION_AST_FUNCTION_DECL_HEADER
#define CION_AST_FUNCTION_DECL_HEADER

#include "cion/ast/decl.hpp"
#include "cion/ast/param_decl.hpp"
#include "cion/ast/compound_stmnt.hpp"

#include <string>
#include <vector>
#include <memory>

namespace cion {
namespace ast {
	class FunctionDecl : public Decl {
	public:
		FunctionDecl(
			std::string const& name,
			std::vector<std::unique_ptr<ParamDecl>> params,
			std::unique_ptr<Type> return_type,
			std::unique_ptr<CompoundStmnt> body);

		std::string & name();
		std::string const& name() const;

		std::vector<std::unique_ptr<ParamDecl>> & params();
		std::vector<std::unique_ptr<ParamDecl>> const& params() const;

		Type & return_type();
		Type const& return_type() const;

		CompoundStmnt & body();
		CompoundStmnt const& body() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		std::string m_name;
		std::vector<std::unique_ptr<ParamDecl>> m_params;
		std::unique_ptr<Type> m_return_type;
		std::unique_ptr<CompoundStmnt> m_body;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_FUNCTION_DECL_HEADER
