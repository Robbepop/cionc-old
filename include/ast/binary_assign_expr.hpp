#ifndef CION_AST_ASSIGNMENT_EXPR_HEADER
#define CION_AST_ASSIGNMENT_EXPR_HEADER

#include "ast/binary_expr.hpp"

#include <cstdint>
#include <memory>

namespace cion {
	class TokenType;

namespace ast {
	class BinaryAssignExpr : public BinaryExpr {
	public:
		using BinaryExpr::BinaryExpr;

		virtual BinaryExpr::Kind kind() const = 0;

		virtual void accept(IASTVisitor & pass) override;
	};

	class AssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class AddAssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class SubtractAssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class MultiplyAssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class DivideAssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class ModuloAssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class LogicalOrAssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class LogicalAndAssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class BitOrAssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class BitXorAssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class BitAndAssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class ShiftLeftAssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};

	class ShiftRightAssignExpr : public BinaryAssignExpr {
	public:
		using BinaryAssignExpr::BinaryAssignExpr;
		virtual BinaryExpr::Kind kind() const override;
		virtual void accept(IASTVisitor & pass) override;
	};
} // namespace ast
} // namespace cion

#endif // CION_AST_ASSIGNMENT_EXPR_HEADER
