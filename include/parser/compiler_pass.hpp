#ifndef CION_PARSER_COMPILER_PASS_HEADER
#define CION_PARSER_COMPILER_PASS_HEADER

#include <type_traits>

namespace cion {
	namespace ast {
		class AssignmentExpression;
		class BinaryExpression;
		class BooleanLiteral;
		class BreakStatement;
		class CallExpression;
		class CharLiteral;
		class CompilationUnit;
		class CompoundStatement;
		class ConditionalExpression;
		class ContinueStatement;
		class EmptyStatement;
		class Expression;
		class ExpressionList;
		class ExpressionStatement;
		class FloatLiteral;
		class FunctionDefinitionStatement;
		class IfStatement;
		class IndexExpression;
		class IntegerLiteral;
		class LogicalParameter;
		class LogicalParameterPack;
		class Node;
		class NothingExpression;
		class NothingType;
		class PostfixExpression;
		class PrimitiveTypeBool;
		class PrimitiveTypeChar;
		class PrimitiveTypeFloat;
		class PrimitiveTypeInt;
		class ReturnStatement;
		class Statement;
		class StatementList;
		class StringLiteral;
		class TypeSpecifier;
		class UnaryExpression;
		class VariableDeclarationStatement;
		class VariableExpression;
		class WhileStatement;
	}

	template <bool isMutating>
	class TCompilerPass {
		template <typename T>
		using opt_mutable = typename std::conditional<isMutating, T&, T const&>::type;
	public:
		virtual void visit(opt_mutable<ast::AssignmentExpression>) {}
		virtual void visit(opt_mutable<ast::BinaryExpression>) {}
		virtual void visit(opt_mutable<ast::BooleanLiteral>) {}
		virtual void visit(opt_mutable<ast::BreakStatement>) {}
		virtual void visit(opt_mutable<ast::CallExpression>) {}
		virtual void visit(opt_mutable<ast::CharLiteral>) {}
		virtual void visit(opt_mutable<ast::CompilationUnit>) {}
		virtual void visit(opt_mutable<ast::CompoundStatement>) {}
		virtual void visit(opt_mutable<ast::ConditionalExpression>) {}
		virtual void visit(opt_mutable<ast::ContinueStatement>) {}
		virtual void visit(opt_mutable<ast::EmptyStatement>) {}
		virtual void visit(opt_mutable<ast::Expression>) {}
		virtual void visit(opt_mutable<ast::ExpressionList>) {}
		virtual void visit(opt_mutable<ast::ExpressionStatement>) {}
		virtual void visit(opt_mutable<ast::FloatLiteral>) {}
		virtual void visit(opt_mutable<ast::FunctionDefinitionStatement>) {}
		virtual void visit(opt_mutable<ast::IfStatement>) {}
		virtual void visit(opt_mutable<ast::IndexExpression>) {}
		virtual void visit(opt_mutable<ast::IntegerLiteral>) {}
		virtual void visit(opt_mutable<ast::LogicalParameter>) {}
		virtual void visit(opt_mutable<ast::LogicalParameterPack>) {}
		virtual void visit(opt_mutable<ast::Node>) {}
		virtual void visit(opt_mutable<ast::NothingExpression>) {}
		virtual void visit(opt_mutable<ast::NothingType>) {}
		virtual void visit(opt_mutable<ast::PostfixExpression>) {}
		virtual void visit(opt_mutable<ast::PrimitiveTypeBool>) {}
		virtual void visit(opt_mutable<ast::PrimitiveTypeChar>) {}
		virtual void visit(opt_mutable<ast::PrimitiveTypeFloat>) {}
		virtual void visit(opt_mutable<ast::PrimitiveTypeInt>) {}
		virtual void visit(opt_mutable<ast::ReturnStatement>) {}
		virtual void visit(opt_mutable<ast::Statement>) {}
		virtual void visit(opt_mutable<ast::StatementList>) {}
		virtual void visit(opt_mutable<ast::StringLiteral>) {}
		virtual void visit(opt_mutable<ast::TypeSpecifier>) {}
		virtual void visit(opt_mutable<ast::UnaryExpression>) {}
		virtual void visit(opt_mutable<ast::VariableDeclarationStatement>) {}
		virtual void visit(opt_mutable<ast::VariableExpression>) {}
		virtual void visit(opt_mutable<ast::WhileStatement>) {}
	};

	using MutatingCompilerPass = TCompilerPass<true>;
	using CompilerPass = TCompilerPass<false>;
} // namespace cion

#endif // CION_PARSER_COMPILER_PASS_HEADER
