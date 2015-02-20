#ifndef CION_TOKEN_TYPE_HEADER
#define CION_TOKEN_TYPE_HEADER

#include <cstdint>
#include <functional>
#include <string>
#include <memory>

namespace cion {
	class TokenType final {
	public:
		enum class Storage : uint8_t {
			empty,
			bool_t,
			char_t,
			string_t,
			integer_t,
			float_t
		};

		static uint16_t make_id();

		static const TokenType error;
		static const TokenType eof;

		TokenType(
			std::string const& p_name,
			Storage p_storage);

		TokenType(std::string const& name);

		TokenType() = delete;

		TokenType(TokenType const& other) = default;
		TokenType(TokenType && other) = default;

		TokenType & operator=(TokenType const& other) = default;
		TokenType & operator=(TokenType && other) = default;

		std::string const& name() const;
		Storage storage() const;

		bool operator==(TokenType const& rhs) const;
		bool operator!=(TokenType const& rhs) const;

	private:
		std::string m_name;
		Storage m_storage;
		uint16_t m_id;
	};
}

#endif // CION_TOKEN_TYPE_HEADER
