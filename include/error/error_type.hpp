#ifndef CION_ERROR_TYPE_HEADER
#define CION_ERROR_TYPE_HEADER

#include <cstdint>

namespace cion {

	enum class ErrorType : uint8_t {
		unknown_token_type,
		expected_token_type_failure
	};

} // namespace cion

#endif // CION_ERROR_TYPE_HEADER
