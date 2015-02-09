#ifndef CION_PARSER_COMPILER_PASS_HEADER
#define CION_PARSER_COMPILER_PASS_HEADER

#include <type_traits>

namespace cion {
	namespace ast {
		class BinaryAssignExpr;
		class BinaryExpr;
		class BooleanExpr;
		class BreakStmnt;
		class CallExpr;
		class CharExpr;
		class CompilationUnitDecl;
		class CompoundStmnt;
		class ConditionalExpr;
		class ContinueStmnt;
		class Decl;
		class EmptyStmnt;
		class Expr;
		class ExprStmnt;
		class FloatExpr;
		class FunctionDecl;
		class IfStmnt;
		class IndexExpr;
		class IntegerExpr;
		class ParamDecl;
		class NothingExpr;
		class NothingType;
		class BuiltinBoolType;
		class BuiltinCharType;
		class BuiltinFloatType;
		class BuiltinIntType;
		class ReturnStmnt;
		class Stmnt;
		class StringExpr;
		class Type;
		class UnaryExpr;
		class VarDecl;
		class VarExpr;
		class WhileStmnt;
	} // namespace ast

	class CompilerPass {
	public:
		// Statements
		virtual void visit(ast::Stmnt &);
		virtual void visit(ast::CompoundStmnt &);
		virtual void visit(ast::EmptyStmnt &);
		virtual void visit(ast::ExprStmnt &);
		virtual void visit(ast::IfStmnt &);
		virtual void visit(ast::WhileStmnt &);
		virtual void visit(ast::BreakStmnt &);
		virtual void visit(ast::ContinueStmnt &);
		virtual void visit(ast::ReturnStmnt &);

		// Declarations
		virtual void visit(ast::Decl &);
		virtual void visit(ast::CompilationUnitDecl &);
		virtual void visit(ast::ParamDecl &);
		virtual void visit(ast::FunctionDecl &);
		virtual void visit(ast::VarDecl &);

		// Expressions
		virtual void visit(ast::Expr &);
		virtual void visit(ast::ConditionalExpr &);
		virtual void visit(ast::BinaryExpr &);
		virtual void visit(ast::BinaryAssignExpr &);
		virtual void visit(ast::BooleanExpr &);
		virtual void visit(ast::CallExpr &);
		virtual void visit(ast::CharExpr &);
		virtual void visit(ast::FloatExpr &);
		virtual void visit(ast::IndexExpr &);
		virtual void visit(ast::IntegerExpr &);
		virtual void visit(ast::NothingExpr &);
		virtual void visit(ast::StringExpr &);
		virtual void visit(ast::UnaryExpr &);
		virtual void visit(ast::VarExpr &);

		// Types
		virtual void visit(ast::Type &);
		virtual void visit(ast::NothingType &);
		virtual void visit(ast::BuiltinBoolType &);
		virtual void visit(ast::BuiltinCharType &);
		virtual void visit(ast::BuiltinFloatType &);
		virtual void visit(ast::BuiltinIntType &);
	};
} // namespace cion

#endif // CION_PARSER_COMPILER_PASS_HEADER
