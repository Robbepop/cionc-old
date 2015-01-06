#include "error/source_location.hpp"

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

} // namespace cion
