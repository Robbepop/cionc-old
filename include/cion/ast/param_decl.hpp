#ifndef CION_AST_PARAM_DECL_HEADER
#define CION_AST_PARAM_DECL_HEADER

#include "cion/ast/decl.hpp"

#include <string>
#include <memory>

namespace cion {
namespace ast {
	class Type;

	class ParamDecl : public Decl {
	public:
		ParamDecl(
			std::string const& p_name,
			std::unique_ptr<Type> p_type);

		std::string & name();
		std::string const& name() const;

		Type & type();
		Type const& type() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		std::string m_name;
		std::unique_ptr<Type> m_type;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_PARAM_DECL_HEADER
