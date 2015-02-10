#ifndef CION_TOKEN_TYPE_STORE_HEADER
#define CION_TOKEN_TYPE_STORE_HEADER

#include <cstdint>

namespace cion {
	enum class TokenTypeStore : uint8_t {
		empty,
		boolean_t,
		character_t,
		string_t,
		integral_t,
		number_t
	};
}

#endif // CION_TOKEN_TYPE_STORE_HEADER
