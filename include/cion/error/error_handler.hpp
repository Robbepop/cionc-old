#ifndef CION_ERROR_HANDLER_HEADER
#define CION_ERROR_HANDLER_HEADER

#include <string>

namespace cion {
	class ErrorType;
	class WarningType;
	class SourceLocation;

	class ErrorHandler {
	public:
		ErrorHandler(std::string const& p_file_name);

		std::string const& file_name() const;

		void error(
			ErrorType const& p_type,
			SourceLocation const& p_loc,
			std::string const& p_message = "") const;

		void warning(
			WarningType const& p_type,
			SourceLocation const& p_loc,
			std::string const& p_message = "") const;

	private:
		std::string m_file_name;
	};

} // namespace cion

#endif // CION_ERROR_HANDLER_HEADER
