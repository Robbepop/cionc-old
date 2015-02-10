#ifndef CION_AST_BINARY_EXPR_HEADER
#define CION_AST_BINARY_EXPR_HEADER

#include "ast/expr.hpp"

#include <cstdint>
#include <memory>

namespace cion {
	class TokenKind;

namespace ast {
	class BinaryExpr : public Expr {
	public:
		enum class Kind : uint8_t {
			logical_or,
			logical_and,
			bit_or,
			bit_xor,
			bit_and,
			equality,
			inequality,

			less_than,
			less_equals,
			greater_than,
			greater_equals,

			add,
			subtract,
			multiply,
			divide,
			modulo,
			shift_left,
			shift_right,

			assign,
			add_assign,
			subtract_assign,
			multiply_assign,
			divide_assign,
			modulo_assign,
			logical_or_assign,
			logical_and_assign,
			bit_or_assign,
			bit_xor_assign,
			bit_and_assign,
			shift_left_assign,
			shift_right_assign
		};

		BinaryExpr(
			std::unique_ptr<Expr> lhs,
			std::unique_ptr<Expr> rhs);

		virtual Kind kind() const = 0;

		Expr & lhs();
		Expr const& lhs() const;

		Expr & rhs();
		Expr const& rhs() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		std::unique_ptr<Expr> m_lhs;
		std::unique_ptr<Expr> m_rhs;
	};

	class LogicalOrExpr : public BinaryExpr {
	public:
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class LogicalAndExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class BitOrExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class BitXorExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class BitAndExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class AddExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class SubtractExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class MultiplyExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class DivideExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class ModuloExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class ShiftLeftExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class ShiftRightExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class EqualityExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class InequalityExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class LessThanExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class LessEqualsExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class GreaterThanExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class GreaterEqualsExpr : public BinaryExpr {
		using BinaryExpr::BinaryExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_BINARY_EXPR_HEADER
