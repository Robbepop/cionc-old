#ifndef CION_ERROR_CION_ERROR_TYPES_HEADER
#define CION_ERROR_CION_ERROR_TYPES_HEADER

#include "error/error_type.hpp"

#include <vector>
#include <string>

namespace cion {

	class CionErrorTypes {
	public:
		static CionErrorTypes const& get_instance();

		std::vector<ErrorType> get_errors() const;

	private:
		CionErrorTypes();
		CionErrorTypes(CionErrorTypes const&) = delete;
		CionErrorTypes(CionErrorTypes &&) = delete;

		CionErrorTypes & operator=(CionErrorTypes const&) = delete;
		CionErrorTypes & operator=(CionErrorTypes &&) = delete;

		ErrorType init_error(ErrorType error_type);

		std::vector<ErrorType> m_errors;

	public:
		ErrorType const
			unknown_token_type,
			expected_token_type_failure;
	};

} // namespace cion

#endif // CION_ERROR_CION_ERROR_TYPES_HEADER
