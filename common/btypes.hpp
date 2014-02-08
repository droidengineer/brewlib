#ifndef _BREW_LIB_TYPES_H_
#define _BREW_LIB_TYPES_H_

#include <iostream>
#include <string>

#include "brew.hpp"
class SymTabNode;
class SymTab;

BEGIN_NAMESPACE(brew)

// VM-related stuff
enum class VMDataType { Undefined, Integer, Real, Array, Object, Enumeration };

class VMType
{
public:

private:
	VMDataType	__dataType;

};
typedef VMType vmType;					 

BEGIN_NAMESPACE(type)
enum class FundamentalStorageType { Undefined, Scalar, Vector, Object, 
	Int8, Int16, Int32, Int64, UInt8, UInt16, UInt32, UInt64,
	Double, Float, Pointer, Boolean, VoidPtr, String, Array
	//Array, Function, Method, Member
};
typedef FundamentalStorageType storage;
extern const char * FundamentalStorageTypeStrings[];
END_NAMESPACE(type)

#include "ast.hpp"
template <typename T, FundamentalStorageType StorageType>
class __fundamental_type : public BrewExpression
{
protected:
	__fundamental_type() { __storageType = StorageType; }
	__fundamental_type(T i) : __value(i), __storageType(StorageType)
	{

	}
	//__fundamental_type(const T & t, FundamentalStorageType t = FundamentalStorageType::Undefined ) 
	//	: __value(t), __storageType(t) { }

	T	operator () () { return __value; }
	virtual const FundamentalStorageType	type() const { return __storageType; }
	virtual T value() { return __value; }
	// for automatic type conversions and promotions to other integral types
	__fundamental_type & promote(FundamentalStorageType t) {

	}
	virtual string toString() {
	   return FundamentalStorageTypeStrings[__storageType];
	}
	virtual size_t sizeof() { return sizeof(T); }

private:
	T	__value;
	FundamentalStorageType	__storageType;
};

class BrewType
{
public:
	template<class T>
	static __fundamental_type<T> Create(FundamentalStorageType t) {
		switch(t) {
		case brew::type::storage::Int8:
			return BrewVM_i8;
		case brew::type::storage::Int16:
			return __fundamental_type<int16_t>(0,brew::type::storage::Int16);

		}
	}
};



#define __fundamental_type__ (t,a)		(__fundamental_type<t> ##  a)

//__fundamental_type__ (uint8_t, s);
//typedef __fundamental_type__ (uint8_t, FundamentalStorageType::UInt8) BrewVM_u8;
// BrewVM_u16	myflags(0xff2e);
typedef __fundamental_type<uint16_t, FundamentalStorageType::UInt16>	BrewVM_u16, __fundamental_type_u16;
typedef __fundamental_type<uint8_t, FundamentalStorageType::UInt8>		BrewVM_u8, __fundamental_type_u8;
typedef __fundamental_type<uint32_t, FundamentalStorageType::UInt32>	BrewVM_u32, __fundamental_type_u32;
typedef __fundamental_type<int8_t, FundamentalStorageType::Int8>		BrewVM_i8, __fundamental_type_i8;
typedef __fundamental_type<int16_t, FundamentalStorageType::Int16>		BrewVM_i16, __fundamental_type_i16;
typedef __fundamental_type<int32_t, FundamentalStorageType::Int32>		BrewVM_i32, __fundamental_type_i32;
typedef __fundamental_type<char *, FundamentalStorageType::Pointer>		BrewVM_p, __fundamental_type_charptr;
typedef BrewVM_u8	BrewVM_byte, __fundamental_type_byte;
typedef BrewVM_u16	BrewVM_word, __fundamental_type_word;
typedef BrewVM_u32	BrewVM_int, __fundamental_type_int;
typedef __fundamental_type<uint64_t, FundamentalStorageType::UInt64>	BrewVM_u64, __fundamental_type_u64;
typedef __fundamental_type<double, FundamentalStorageType::Double>		BrewVM_double, __fundamental_type_double;
typedef __fundamental_type<BObject, FundamentalStorageType::Object>		BrewVM_object, __fundamental_type_object;
typedef __fundamental_type<string, FundamentalStorageType::String>		BrewVM_string, __fundamental_type_string;
typedef __fundamental_type<BArray, FundamentalStorageType::Array>		BrewVM_array, __fundamental_type_array;
typedef __fundamental_type<bool, FundamentalStorageType::Boolean>		BrewVM_bool, __fundamental_type_bool;
typedef __fundamental_type<void *, FundamentalStorageType::VoidPtr>		BrewVM_opaque, __fundamental_type_opaque;

// SymTab-related stuff
enum class SymTabDataFormat { None, Scalar, Enum, Subrange, Array, Record,
	Object, Function, Vector
};

class BrewSymTabType
{
public:
	union {
		struct {
			SymTabNode * constIds;
			int			max;
		} enumeration;
		struct {
			BrewSymTabType * baseType;
			int min, max;
		} subrange;
		struct {
			BrewSymTabType * indexType;
			BrewSymTabType * elemType;
			int minIndex, maxIndex, elemCount;
		} array;
		struct {
			SymTab * recordFields;
		} record;
		struct {
			SymTab * members;
			SymTab * methods;
			SymTab * prototype;
		} object;
		struct {
			SymTab * enclosingScope;
			SymTab ** params;
			SymTab * localScope;
		} function;

	};
	
protected:
	SymTabDataFormat	_fmt;
	uint16_t	_refCount;
	SymTabNode * _typeIdentifier;
};

END_NAMESPACE(brew)
#endif