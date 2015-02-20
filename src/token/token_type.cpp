#include "cion/token/token_type.hpp"

namespace cion {
	const TokenType TokenType::error = {"error"};
	const TokenType TokenType::eof = {"end of file (eof)"};

	TokenType::TokenType(
		std::string const& p_name,
		TokenType::Storage p_storage
	):
		m_name{p_name},
		m_storage{p_storage},
		m_id{make_id()}
	{}

	TokenType::TokenType(
		std::string const& p_name
	):
		TokenType{p_name, TokenType::Storage::empty}
	{}

	uint16_t TokenType::make_id() {
		static uint16_t c_current_id = 0;
		return ++c_current_id;
	}

	std::string const& TokenType::name() const {
		return m_name;
	}

	TokenType::Storage TokenType::storage() const {
		return m_storage;
	}

	bool TokenType::operator==(TokenType const& rhs) const {
		return m_id == rhs.m_id;
	}

	bool TokenType::operator!=(TokenType const& rhs) const {
		return m_id != rhs.m_id;
	}
} // namespace cion
