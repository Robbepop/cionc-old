#include "error/error_type.hpp"

namespace cion {

	ErrorType::ErrorType(std::string const& name):
		DebugInfoType{name}
	{}

	bool ErrorType::is_error() const {
		return true;
	}

	bool ErrorType::is_warning() const {
		return !is_error();
	}

	bool ErrorType::is_activ() const {
		return false;
	}

} // namespace cion
