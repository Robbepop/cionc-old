#include "cion/ast/builtin_type.hpp"

#include <cassert>
#include <stdexcept>

namespace cion {
namespace ast {

//////////////////////////////////////////////////////////////////////////////////////////
/// BuiltinType
//////////////////////////////////////////////////////////////////////////////////////////

	void BuiltinType::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// BuiltinBoolType
//////////////////////////////////////////////////////////////////////////////////////////

	void BoolType::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// BuiltinCharType
//////////////////////////////////////////////////////////////////////////////////////////

	void CharType::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// IntegerType
//////////////////////////////////////////////////////////////////////////////////////////

	void IntegerType::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// FloatingType
//////////////////////////////////////////////////////////////////////////////////////////

	void FloatingType::accept(IASTVisitor & pass) {
		pass.visit(*this);
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// IntegerTypeFabric
//////////////////////////////////////////////////////////////////////////////////////////

	IntegerTypeFabric const& IntegerTypeFabric::instance() {
		static IntegerTypeFabric c_instance;
		return c_instance;
	}

	std::unique_ptr<IntegerType> IntegerTypeFabric::make(
		bool p_is_signed,
		IntegerType::Width p_width
	) const {
		using Width = IntegerType::Width;
		if (p_is_signed) {
			switch (p_width) {
				case Width::unspecified: return {std::make_unique<IntType>()};
				case Width::one_byte   : return {std::make_unique<Int8Type>()};
				case Width::two_bytes  : return {std::make_unique<Int16Type>()};
				case Width::four_bytes : return {std::make_unique<Int32Type>()};
				case Width::eight_bytes: return {std::make_unique<Int64Type>()};
				default: throw std::runtime_error("");
			}
		} else {
			switch (p_width) {
				case Width::unspecified: return {std::make_unique<UIntType>()};
				case Width::one_byte   : return {std::make_unique<UInt8Type>()};
				case Width::two_bytes  : return {std::make_unique<UInt16Type>()};
				case Width::four_bytes : return {std::make_unique<UInt32Type>()};
				case Width::eight_bytes: return {std::make_unique<UInt64Type>()};
				default: throw std::runtime_error("");
			}
		}
	}

//////////////////////////////////////////////////////////////////////////////////////////
/// FloatingTypeFabric
//////////////////////////////////////////////////////////////////////////////////////////

	FloatingTypeFabric const& FloatingTypeFabric::instance() {
		static FloatingTypeFabric c_instance;
		return c_instance;
	}

	std::unique_ptr<FloatingType> FloatingTypeFabric::make(
		FloatingType::Width p_width
	) const {
		using Width = FloatingType::Width;
		switch (p_width) {
			case Width::unspecified: return {std::make_unique<FloatType>()};
			case Width::two_bytes  : return {std::make_unique<Float16Type>()};
			case Width::four_bytes : return {std::make_unique<Float32Type>()};
			case Width::eight_bytes: return {std::make_unique<Float64Type>()};
			default: throw std::runtime_error("");
		}
	}

} // namespace ast
} // namespace cion
