#ifndef CION_AST_VAR_DECL_HEADER
#define CION_AST_VAR_DECL_HEADER

#include "ast/decl.hpp"
#include "ast/expr.hpp"
#include "ast/type.hpp"

#include <string>
#include <memory>

namespace cion {
namespace ast {

	class VarDecl : public Decl {
	public:
		VarDecl(VarDecl const& rhs) = delete;
		VarDecl & operator=(VarDecl const& rhs) = delete;

		VarDecl(
			std::string const& name,
			std::unique_ptr<Type> type,
			std::unique_ptr<Expr> expr);

		std::string & name();
		std::string const& name() const;

		Type & type();
		Type const& type() const;

		Expr & expr();
		Expr const& expr() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		std::string m_name;
		std::unique_ptr<Type> m_type;
		std::unique_ptr<Expr> m_expr;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_VAR_DECL_HEADER
