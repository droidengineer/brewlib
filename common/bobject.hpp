#ifndef _BREW_LIB_BOBJECT_H_
#define _BREW_LIB_BOBJECT_H_

#include "common.hpp"
#include "types.h"
#include <map>

BEGIN_NAMESPACE(brew)

enum class FundamentalType {
		Undefined, Null, Boolean, String,
		Number, Object, Iterator, Function,
		None
};

enum class FundamentalNumber {
	Integer8, Integer16, Integer32,
	UInteger8, UInteger16, UInteger32,
	Float, Double
};

typedef struct type
{
	int integer;
} type_t;

typedef struct value
{
	FundamentalType _vtype;
	union
	{
		bool boolean;
		uint8_t ui8;
		uint16_t ui16;
		uint32_t ui32;
		int8_t i8, byte;
		int16_t i16;
		int32_t i32;
	};

	static hash_t calcHash(std::string &);

} value_t;

typedef struct YYLTYPE
{
	int first_line, first_column;
	int last_line, last_column;

	//brew::string	file;
	//uint16_t	fline,lline;
	//uint16_t	fcol,lcol;
	//size_t		idx;

} location_t;

struct Property
{
	uint32_t attributes;
	value_t value;
};

class PropertyTable
{
public:

	Property *	getProperty(brew::string & name);
	value_t *		get(value_t * key, hash_t hash);
	value_t *		get(uint32_t idx);

private:
	map<value_t, Property>	_table;
	PropertyTable * _prev;
};

/////////////////////////////[ BObject
BREW_DYN_EXPORT class BObject
{
public:
	BObject(BObject &);

	const uint32_t	signature() const { return _signature; }
	const uint32_t	id() const { return _id; }
	const BObject * prototype() const { return _prototype; }

	virtual void init(VMContext * vmc) = 0;

	// Properties
	

	// Attributes
	
	// Conversions
	virtual BPrimitive	toPrimitive() = 0;
	virtual bool toBoolean() = 0;
	virtual brew::string toString() = 0;
	virtual BNumber toNumber() = 0;
	virtual BObject * toObject() { return this; }
	virtual uint8_t	toUInt8() = 0;
	virtual uint16_t toUInt16() = 0;
	virtual uint32_t toUInt32() = 0;
	virtual int8_t toInt8() = 0;
	virtual uint8_t toByte() { return toUInt8(); }
	virtual int16_t toInt16() = 0;
	virtual int32_t toInt32() = 0;
	virtual float	toFloat() = 0;

protected:
	value_t	_value;

private:
	BObject * 	_prototype;
	uint32_t	_signature;
	uint32_t	_id;
	PropertyTable _properties;


};


////////////////////////////////////////////
// All the primitive types that are encapsulated
// by the concept of 'auto' type

/////////////////////////////[ BString
BREW_DYN_EXPORT class BString : public BObject
{
public:
	BString() : BObject(getPrototype()) {

	}
		


private:

};

__prototype__ (BString);


/////////////////////////////[ BString
BREW_DYN_EXPORT class BUInt8 : public BObject
{
public:
	BUInt8() : BObject(getPrototype()) {

	}
		


private:

};
__prototype__ (BUInt8);

/////////////////////////////[ BString
BREW_DYN_EXPORT class BFloat : public BObject
{
public:
	BString() : BObject(getPrototype()) {

	}
		


private:

};

__prototype__ (BFloat);



/////////////////////////////[ BString
BREW_DYN_EXPORT class BUInt16 : public BObject
{
public:
	BString() : BObject(getPrototype()) {

	}
		


private:

};

__prototype__ (BUInt16);

BREW_DYN_EXPORT class BNumber : public BFloat, BUInt8, BUInt16
{

};


/////////////////////////////[ BString
BREW_DYN_EXPORT class BArray : public BObject
{
public:
	BArray() : BObject(getPrototype()) {

	}
		


private:

};

__prototype__ (BArray);


/////////////////////////////[ BString
BREW_DYN_EXPORT class BBoolean : public BObject
{
public:
	BBoolean() : BObject(getPrototype()) {

	}
		


private:

};

__prototype__ (BBoolean);


/////////////////////////////[ BString
BREW_DYN_EXPORT class BFunction : public BObject
{
public:
	BFunction() : BObject(getPrototype()) {

	}
		


private:

};

__prototype__ (BFunction);




BREW_DYN_EXPORT class BAuto : public BBoolean, BArray, BNumber, BString, BFunction


END_NAMESPACE()

#endif
