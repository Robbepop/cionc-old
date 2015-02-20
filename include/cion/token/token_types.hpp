#ifndef CION_TOKEN_TYPES_HEADER
#define CION_TOKEN_TYPES_HEADER

#include "cion/token/token_type.hpp"

namespace cion {
	class TokenTypes final {
	private:
		TokenTypes();
		TokenTypes(TokenTypes const&) = delete;
		TokenTypes(TokenTypes &&) = delete;

		TokenTypes & operator=(TokenTypes const&) = delete;
		TokenTypes & operator=(TokenTypes &&) = delete;

	public:
		static TokenTypes const& instance();

		TokenType const
			// Types
			type_void,
			type_bool,
			type_char,
			type_int  , type_int8   , type_int16  , type_int32  , type_int64,
			type_uint , type_uint8  , type_uint16 , type_uint32 , type_uint64,
			type_float, type_float16, type_float32, type_float64,

			// Declarations
			cmd_var,
			cmd_function,

			// Control Flow & Loops
			cmd_if,
			cmd_else,
			cmd_for,
			cmd_while,

			// Advanced Control Flow
			cmd_break,
			cmd_continue,
			cmd_return,

			// Braces
			opening_brace, opening_paren, opening_brack,
			closing_brace, closing_paren, closing_brack,

			// Arithemical Operators
			op_plus, op_minus,
			op_star, op_slash, op_percent,

			// Bit Operators
			op_pipe, op_and, op_caret, op_tilde, op_left_left, op_right_right,

			// Logical Operators
			op_pipe_pipe, op_and_and,

			// Relational Operators
			op_less_than, op_less_equals, op_greater_than, op_greater_equals,
			op_equals_equals, op_not_equals,

			// Assign Operators
			op_equals,
			op_plus_equals, op_minus_equals,
			op_star_equals, op_slash_equals, op_percent_equals,
			op_tilde_equals,
			op_and_equals, op_and_and_equals,
			op_pipe_equals, op_pipe_pipe_equals,
			op_caret_equals,
			op_left_left_equals, op_right_right_equals,

			// Incremenet/Decrement Operators
			op_plus_plus, op_minus_minus,

			// Special Operators
			op_exclam_mark, op_question_mark,
			op_dot, op_arrow,
			op_colon, op_colon_colon, op_semi_colon, op_comma,

			// Generic Tokens
			identifier,

			// Literals
			lit_bool,
			lit_integral,
			lit_number,
			lit_char,
			lit_string;
	};
}

#endif // CION_TOKEN_TYPES_HEADER
