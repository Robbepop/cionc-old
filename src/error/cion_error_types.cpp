#include "error/cion_error_types.hpp"

#include <utility>

namespace cion {

	CionErrorTypes const& CionErrorTypes::get_instance() {
		static CionErrorTypes c_instance;
		return c_instance;
	}

	std::vector<ErrorType> CionErrorTypes::get_errors() const {
		return m_errors;
	}

	ErrorType CionErrorTypes::init_error(ErrorType error_type) {
		m_errors.push_back(error_type);
		return std::move(error_type);
	}

	CionErrorTypes::CionErrorTypes():
		m_errors{},
		unknown_token_type{init_error({"unknown token type"})},
		expected_token_type_failure{init_error({"unexpected token type"})}
	{}

} // namespace cion
