#include "cion/error/report_type.hpp"

namespace cion {

//////////////////////////////////////////////////////////////////////////////////////////
/// Report Type
//////////////////////////////////////////////////////////////////////////////////////////

	ReportType::ReportType(std::string const& name) :
		m_name{name}
	{}

	bool ReportType::operator==(ReportType const& other) const {
		return m_name == other.get_name();	
	}

	bool ReportType::operator!=(ReportType const& other) const {
		return m_name != other.get_name();
	}

	std::string const& ReportType::get_name() const {
		return m_name;
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// Error Type
//////////////////////////////////////////////////////////////////////////////////////////

	ErrorType::ErrorType(std::string const& name):
		ReportType{name}
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

//////////////////////////////////////////////////////////////////////////////////////////
/// Warning Type
//////////////////////////////////////////////////////////////////////////////////////////

	WarningType::WarningType(std::string const& name, bool default_activ):
		ReportType{name},
		m_activ{default_activ}
	{}

	bool WarningType::is_error() const {
		return false;
	}

	bool WarningType::is_warning() const {
		return !is_error();
	}

	bool WarningType::is_activ() const {
		return m_activ;
	}

} // namespace cion
