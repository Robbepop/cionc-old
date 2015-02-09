#ifndef CION_CION_TOKEN_TYPES_HEADER
#define CION_CION_TOKEN_TYPES_HEADER

#include "token/token_type.hpp"

#include <vector>

namespace cion {
	class CionTokenTypes final {
	private:
		CionTokenTypes();
		CionTokenTypes(CionTokenTypes const&) = delete;
		CionTokenTypes(CionTokenTypes &&) = delete;

		CionTokenTypes & operator=(CionTokenTypes const&) = delete;
		CionTokenTypes & operator=(CionTokenTypes &&) = delete;

		TokenType init_tt(TokenType token_type, bool skipped = false);

		std::vector<TokenType> m_all_token_types;
		std::vector<TokenType> m_skipped_token_types;

	public:
		static CionTokenTypes const& get_instance();

		std::vector<TokenType> const& get_all() const;
		std::vector<TokenType> const& get_skipped() const;

		TokenType const
			// Comments
			whitespace,
			line_comment,
			comment,

			// Types
			type_void,
			type_bool,
			type_char,
			type_int, type_int8, type_int16, type_int32, type_int64,
			type_uint, type_uint8, type_uint16, type_uint32, type_uint64,
			type_float, type_float16, type_float32, type_float64,

			// Variables
			cmd_var, cmd_val,

			// Control Flows
			cmd_if, cmd_else,
			cmd_try, cmd_catch, cmd_finally,
			cmd_switch, cmd_break, cmd_continue, cmd_return,

			// Loops
			cmd_for,
			cmd_while, cmd_do,

			// Structures
			cmd_module,
			cmd_class,
			cmd_struct,
			cmd_interface,
			cmd_union,

			// Operators
			op_plus, op_minus, op_star, op_slash, op_percent,
			op_pipe, op_and, op_caret, op_tilde, op_left_left, op_right_right,
			op_pipe_pipe, op_and_and,
			op_less_than, op_less_equals, op_greater_than, op_greater_equals,
			op_equals_equals, op_not_equals,
			op_equals, op_plus_equals, op_minus_equals, op_star_equals, op_slash_equals, op_percent_equals,
			op_tilde_equals, op_and_equals, op_and_and_equals, op_pipe_equals, op_pipe_pipe_equals, op_caret_equals,
			op_left_left_equals, op_right_right_equals,
			op_plus_plus, op_minus_minus,
			op_exclam_mark, op_question_mark,
			op_dot, op_arrow, op_colon, op_colon_colon, op_semi_colon, op_comma,

			// Generic Tokens
			identifier,

			// Literals
			lit_bool,
			lit_integral,
			lit_number,
			lit_char,
			lit_string,

			// Functions
			cmd_function,
			cmd_constructor,
			cmd_destructor,

			// Qualifiers
			cmd_mutable,
			cmd_reference,
			cmd_pointer,

			// Access Modifiers
			cmd_private,
			cmd_protected,
			cmd_public,

			// Attributes
			cmd_extends,
			cmd_implements,
			cmd_final,
			cmd_virtual,
			cmd_override,
			cmd_abstract,
			cmd_extern,
			cmd_import,

			// Braces
			opening_brace, opening_paren, opening_brack,
			closing_brace, closing_paren, closing_brack;
	};
}

#endif // CION_CION_TOKEN_TYPES_HEADER
