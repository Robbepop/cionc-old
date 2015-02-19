#include "cion/error/source_location.hpp"

namespace cion {

	SourceLocation::SourceLocation(loc_type line, loc_type col) :
		m_line{line},
		m_col{col}
	{}

	SourceLocation::loc_type const& SourceLocation::line() const {
		return m_line;
	}

	SourceLocation::loc_type const& SourceLocation::col() const {
		return m_col;
	}

	SourceLocation::loc_type & SourceLocation::line() {
		return m_line;
	}

	SourceLocation::loc_type & SourceLocation::col() {
		return m_col;
	}

	bool SourceLocation::operator< (SourceLocation const& rhs) const {
		if (line() < rhs.line()) {
			return true;
		}
		if (line() == rhs.line() && col() < rhs.col()) {
			return true;
		}
		return false;
	}

	bool SourceLocation::operator> (SourceLocation const& rhs) const {
		return rhs < *this;
	}

	bool SourceLocation::operator<=(SourceLocation const& rhs) const {
		return !(*this > rhs);
	}

	bool SourceLocation::operator>=(SourceLocation const& rhs) const {
		return !(*this < rhs);
	}

	bool SourceLocation::operator==(SourceLocation const& rhs) const {
		return line() == rhs.line() && col() == rhs.col();
	}

	bool SourceLocation::operator!=(SourceLocation const& rhs) const {
		return !(*this == rhs);
	}

} // namespace cion
