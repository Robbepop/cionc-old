#include "cion/error/error_types.hpp"

#include <utility>

namespace cion {

	ErrorTypes const& ErrorTypes::instance() {
		static ErrorTypes c_instance;
		return c_instance;
	}

	std::vector<ErrorType> ErrorTypes::get_errors() const {
		return m_errors;
	}

	ErrorType ErrorTypes::init_error(ErrorType error_type) {
		m_errors.push_back(error_type);
		return std::move(error_type);
	}

	ErrorTypes::ErrorTypes():
		m_errors{},
		unknown_token_type{init_error({"unknown token type"})},
		broken_char_literal{init_error({"broken character literal"})},
		broken_string_literal{init_error({"broken string literal"})},
		broken_number_literal{init_error({"broken number literal"})},
		expected_token_type_failure{init_error({"unexpected token type"})}
	{}

} // namespace cion
