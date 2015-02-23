#ifndef CION_AST_BUILTIN_TYPE_HEADER
#define CION_AST_BUILTIN_TYPE_HEADER

#include "cion/ast/type.hpp"

#include <cstdint>
#include <memory>

namespace cion {
namespace ast {

	class BuiltinType : public Type {
	public:
		virtual void accept(IASTVisitor & pass) override;
	};

//////////////////////////////////////////////////////////////////////////////////////////
/// BoolType
//////////////////////////////////////////////////////////////////////////////////////////

	class BoolType : public BuiltinType {
	public:
		BoolType() = default;

		virtual void accept(IASTVisitor & pass) override;
	};

//////////////////////////////////////////////////////////////////////////////////////////
/// CharType
//////////////////////////////////////////////////////////////////////////////////////////

	class CharType : public BuiltinType {
	public:
		CharType() = default;

		virtual void accept(IASTVisitor & pass) override;
	};

//////////////////////////////////////////////////////////////////////////////////////////
/// IntegerTypes
//////////////////////////////////////////////////////////////////////////////////////////

	class IntegerType : public BuiltinType {
	public:
		enum class Width : uint8_t {
			unspecified = 0,
			one_byte    = 8,
			two_bytes   = 16,
			four_bytes  = 32,
			eight_bytes = 64
		};

		virtual bool sig() const = 0;

		virtual Width width() const = 0;

		virtual void accept(IASTVisitor & pass) override;
	};

	template <bool t_is_signed, IntegerType::Width t_width>
	class BasicIntegerType : public IntegerType {
	public:
		BasicIntegerType() = default;

		bool sig() const override {
			return t_is_signed;
		}

		IntegerType::Width width() const override {
			return t_width;
		}

		virtual void accept(IASTVisitor & pass) override {
			pass.visit(*this);
		}
	};

	using IntType    = BasicIntegerType<true , IntegerType::Width::unspecified>;
	using Int8Type   = BasicIntegerType<true , IntegerType::Width::one_byte>;
	using Int16Type  = BasicIntegerType<true , IntegerType::Width::two_bytes>;
	using Int32Type  = BasicIntegerType<true , IntegerType::Width::four_bytes>;
	using Int64Type  = BasicIntegerType<true , IntegerType::Width::eight_bytes>;
	using UIntType   = BasicIntegerType<false, IntegerType::Width::unspecified>;
	using UInt8Type  = BasicIntegerType<false, IntegerType::Width::one_byte>;
	using UInt16Type = BasicIntegerType<false, IntegerType::Width::two_bytes>;
	using UInt32Type = BasicIntegerType<false, IntegerType::Width::four_bytes>;
	using UInt64Type = BasicIntegerType<false, IntegerType::Width::eight_bytes>;

//////////////////////////////////////////////////////////////////////////////////////////
/// FloatingTypes
//////////////////////////////////////////////////////////////////////////////////////////

	class FloatingType : public BuiltinType {
	public:
		enum class Width : uint8_t {
			unspecified = 0,
			two_bytes   = 16,
			four_bytes  = 32,
			eight_bytes = 64
		};

		virtual Width width() const = 0;

		virtual void accept(IASTVisitor & pass) override;
	};

	template <FloatingType::Width t_width>
	class BasicFloatingType : public FloatingType {
	public:
		BasicFloatingType() = default;

		virtual FloatingType::Width width() const override {
			return t_width;
		}

		virtual void accept(IASTVisitor & pass) override {
			pass.visit(*this);
		}
	};

	using FloatType   = BasicFloatingType<FloatingType::Width::unspecified>;
	using Float16Type = BasicFloatingType<FloatingType::Width::two_bytes>;
	using Float32Type = BasicFloatingType<FloatingType::Width::four_bytes>;
	using Float64Type = BasicFloatingType<FloatingType::Width::eight_bytes>;

//////////////////////////////////////////////////////////////////////////////////////////
/// IntegerType & FloatingType Fabrics
//////////////////////////////////////////////////////////////////////////////////////////

	class IntegerTypeFabric {
	public:
		static IntegerTypeFabric const& instance();

		std::unique_ptr<IntegerType> make(
			bool p_is_signed, IntegerType::Width p_width) const;
	};

	class FloatingTypeFabric {
	public:
		static FloatingTypeFabric const& instance();

		std::unique_ptr<FloatingType> make(
			FloatingType::Width p_width) const;
	};

} // namespace ast
} // namespace cion

#endif // CION_AST_BUILTIN_TYPE_HEADER
