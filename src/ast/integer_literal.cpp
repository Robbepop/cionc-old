#include "ast/integer_literal.hpp"

namespace cion {
namespace ast {

	IntegerLiteral::IntegerLiteral(IntegerLiteral::storage_type value) :
		m_value{value}
	{}

	IntegerLiteral::storage_type & IntegerLiteral::value() {
		return m_value;
	}

	IntegerLiteral::storage_type const& IntegerLiteral::value() const {
		return m_value;
	}

	void IntegerLiteral::accept(MutatingCompilerPass & pass) {
		pass.visit(*this);
	}

	void IntegerLiteral::accept(CompilerPass & pass) const {
		pass.visit(*this);
	}

} // namespace ast
} // namespace cion
