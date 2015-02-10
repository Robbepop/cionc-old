#ifndef CION_AST_BUILTIN_TYPE_HEADER
#define CION_AST_BUILTIN_TYPE_HEADER

#include "cion/ast/type.hpp"

#include <cstdint>

namespace cion {
namespace ast {

	class BuiltinType : public Type {
	public:
		virtual void accept(IASTVisitor & pass) override;
	};

	class BuiltinBoolType : public BuiltinType {
	public:
		BuiltinBoolType() = default;

		virtual void accept(IASTVisitor & pass) override;
	};

	class BuiltinCharType : public BuiltinType {
	public:
		BuiltinCharType() = default;

		virtual void accept(IASTVisitor & pass) override;
	};

	class BuiltinIntType : public BuiltinType {
	public:
		enum class Width : uint8_t {
			unspecified = 0,
			one_byte    = 8,
			two_bytes   = 16,
			four_bytes  = 32,
			eight_bytes = 64
		};

		BuiltinIntType(bool is_signed = true, Width bit_width = Width::unspecified);

		bool & sig();
		bool const& sig() const;

		Width & width();
		Width const& width() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		bool m_signed;
		Width m_width;
	};

	class BuiltinFloatType : public BuiltinType {
	public:
		enum class Width : uint8_t {
			unspecified = 0,
			two_bytes   = 16,
			four_bytes  = 32,
			eight_bytes = 64
		};

		BuiltinFloatType(Width bit_width = Width::unspecified);

		Width & width();
		Width const& width() const;

		virtual void accept(IASTVisitor & pass) override;

	private:
		Width m_width;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_BUILTIN_TYPE_HEADER
