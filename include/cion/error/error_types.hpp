#ifndef CION_ERROR_ERROR_TYPES_HEADER
#define CION_ERROR_ERROR_TYPES_HEADER

#include "cion/error/report_type.hpp"

#include <vector>
#include <string>

namespace cion {

	class ErrorTypes {
	public:
		static ErrorTypes const& instance();

		std::vector<ErrorType> get_errors() const;

	private:
		ErrorTypes();
		ErrorTypes(ErrorTypes const&) = delete;
		ErrorTypes(ErrorTypes &&) = delete;

		ErrorTypes & operator=(ErrorTypes const&) = delete;
		ErrorTypes & operator=(ErrorTypes &&) = delete;

		ErrorType init_error(ErrorType error_type);

		std::vector<ErrorType> m_errors;

	public:
		ErrorType const
			unknown_token_type,
			broken_char_literal,
			broken_string_literal,
			broken_number_literal,
			expected_token_type_failure;
	};

} // namespace cion

#endif // CION_ERROR_CION_ERROR_TYPES_HEADER
