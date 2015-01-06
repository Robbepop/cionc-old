#ifndef CION_ERROR_LEXER_EXCEPTION_HEADER
#define CION_ERROR_LEXER_EXCEPTION_HEADER

#include "error/cion_exception.hpp"

namespace cion {

	class lexer_exception final : public cion_exception {
		using cion_exception::cion_exception;
	};

} // namespace cion

#endif // CION_ERROR_LEXER_EXCEPTION_HEADER
