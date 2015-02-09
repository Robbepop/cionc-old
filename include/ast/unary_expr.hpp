#ifndef CION_AST_UNARY_EXPR_HEADER
#define CION_AST_UNARY_EXPR_HEADER

#include "ast/expr.hpp"

#include <cstdint>
#include <memory>

namespace cion {
	class TokenType;

namespace ast {
	class UnaryExpr : public Expr {
	public:
		enum class Kind : int8_t {
			bit_negate,
			logical_negate,
			plus,
			minus,
			increment,
			decrement,
			post_increment,
			post_decrement
		};

		UnaryExpr(std::unique_ptr<Expr> expr);

		Expr & expr();
		Expr const& expr() const;

		virtual Kind kind() const = 0;

		virtual void accept(CompilerPass & pass) override;

	private:
		std::unique_ptr<Expr> m_expr;
	};

	class BitNegateExpr : public UnaryExpr {
	public:
		using UnaryExpr::UnaryExpr;
		virtual UnaryExpr::Kind kind() const override;
		virtual void accept(CompilerPass & pass) override;
	};

	class LogicalNegateExpr : public UnaryExpr {
	public:
		using UnaryExpr::UnaryExpr;
		virtual UnaryExpr::Kind kind() const override;
		virtual void accept(CompilerPass & pass) override;
	};

	class PlusExpr : public UnaryExpr {
	public:
		using UnaryExpr::UnaryExpr;
		virtual UnaryExpr::Kind kind() const override;
		virtual void accept(CompilerPass & pass) override;
	};

	class MinusExpr : public UnaryExpr {
	public:
		using UnaryExpr::UnaryExpr;
		virtual UnaryExpr::Kind kind() const override;
		virtual void accept(CompilerPass & pass) override;
	};

	class IncrementExpr : public UnaryExpr {
	public:
		using UnaryExpr::UnaryExpr;
		virtual UnaryExpr::Kind kind() const override;
		virtual void accept(CompilerPass & pass) override;
	};

	class DecrementExpr : public UnaryExpr {
	public:
		using UnaryExpr::UnaryExpr;
		virtual UnaryExpr::Kind kind() const override;
		virtual void accept(CompilerPass & pass) override;
	};

	class PostIncrementExpr : public UnaryExpr {
	public:
		using UnaryExpr::UnaryExpr;
		virtual UnaryExpr::Kind kind() const override;
		virtual void accept(CompilerPass & pass) override;
	};

	class PostDecrementExpr : public UnaryExpr {
	public:
		using UnaryExpr::UnaryExpr;
		virtual UnaryExpr::Kind kind() const override;
		virtual void accept(CompilerPass & pass) override;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_UNARY_EXPR_HEADER
