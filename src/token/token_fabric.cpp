#include "cion/token/token_fabric.hpp"

#include <memory>
#include <stdexcept>

//#define DEBUG
#ifdef DEBUG
#include <iostream>
#define DEBUG_STDOUT(x) (std::cout << x)
#define DEBUG_STDERR(x) (std::cerr << x)
#undef DEBUG
#else
#define DEBUG_STDOUT(x)
#define DEBUG_STDERR(x)
#endif

namespace cion {
	std::unique_ptr<Token> TokenFabric::make_token(
		TokenType const& token_type,
		SourceLocation const& start_loc,
		SourceLocation const& end_loc,
		std::string const& value
	) {
		using tts = TokenTypeStore;
		switch (token_type.get_store_type())
		{
			case tts::empty:
				DEBUG_STDERR("token_fabric: create empty_token()\n");
				return std::make_unique<Token>(
					token_type, start_loc, end_loc);
			case tts::boolean_t:
				DEBUG_STDERR("token_fabric: create boolean_token()\n");
				return {std::make_unique<BoolToken>(
						token_type, start_loc, end_loc, value)};
			case tts::character_t:
				DEBUG_STDERR("token_fabric: create char_token()\n");
				return {std::make_unique<CharToken>(
						token_type, start_loc, end_loc, value)};
			case tts::integral_t:
				DEBUG_STDERR("token_fabric: create integral_token()\n");
				return {std::make_unique<IntegralToken>(
						token_type, start_loc, end_loc, value)};
			case tts::number_t:
				DEBUG_STDERR("token_fabric: create number_token()\n");
				return {std::make_unique<NumberToken>(
						token_type, start_loc, end_loc, value)};
			case tts::string_t:
				DEBUG_STDERR("token_fabric: create string_token()\n");
				return {std::make_unique<StringToken>(
						token_type, start_loc, end_loc, value)};
			default:
				throw std::invalid_argument{"unknown type store"};
		}
	}
} // namespace cion
