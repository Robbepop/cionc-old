#ifndef CION_ERROR_PARSER_EXCEPTION_HEADER
#define CION_ERROR_PARSER_EXCEPTION_HEADER

#include "cion/error/cion_exception.hpp"

namespace cion {

	class parser_exception final : public cion_exception {
		using cion_exception::cion_exception;
	};

} // namespace cion

#endif // CION_ERROR_PARSER_EXCEPTION_HEADER
