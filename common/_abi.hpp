#ifndef _BREW_LIB_ABI_H_
#define _BREW_LIB_ABI_H_

#include "brew.hpp"

// some or all of the below may or may not be completed or working properly.
// the brewlib adaptation of the ABI must not constrain the users of the ABI
BEGIN_NAMESPACE(brew)
BEGIN_NAMESPACE(abi)

#if !defined(byte)
typedef unsigned char byte;
#endif

////////////////[ Runtime ABI

////////////////[ Binary Object ABI



///////////////////[ BROWNIE File Format
// Binary Object OWN Executable Format (BROWNIE)
enum class BrownieTypeCode : uint8_t {
	Header = 0x00,
	StringID = 0x01,
	TypeID = 0x02,
	ProtoID = 0x03,
	FieldID = 0x04,
	MethodID = 0x05,
	ClassDef = 0x06,
	MapList = 0x07,
	TypeList = 0x08,
	//
	AnnotationRefList = 0x09,
	AnnotationSetItem = 0x0A,
	ClassDataItem = 0x0B,
	CodeItem = 0x0C,
	StringDataItem = 0x0D,
	DebugInfoItem = 0x0E,
	AnnotationItem = 0x0F,
	EncodedArrayItem = 0x10,
	AnnotationsDirectoryItem = 0x11,
	ConstantsPool = 0x12,
	ConstantPoolItem = 0x13,
	CtorID = 0x14,
	CtorList = 0x15
};

	/**
	  * Overall biary object file layout
	  *  <url>http://wiki.opendesignstrategies.org:8090/display/MUNIX/Binary+Object+ABI</url>
	  * 
	  */


///////[ map_list stuff
struct brownie_map_item
{
	uint8_t	type;
	size_t	size;	// count of number of items to be found at offset
	size_t	offset;	// offset from start of file to item(s) in question
};

struct brownie_map_list
{
	size_t	size;
	brownie_map_item * items;
};

struct brownie_header
{
	uint8_t		magic;
	uint8_t		vermaj;
	uint8_t		vermin;
	uint32_t	chksum;
};

typedef size_t brownie_string_id_item;
typedef size_t brownie_type_id_item;


struct brownie_string_data_item
{
	brownie_string_data_item(size_t s) { size = s; data = new byte[s+1]; }

	size_t	size;
	byte * data;
};

struct brownie_proto_id_item
{
	size_t	index;
	brownie_type_id_item return_type_index;

};

struct brownie_field_id_item
{
	brownie_type_id_item	class_index;	// idx into the type_ids_list for definer of this field
	brownie_type_id_item	type_index;		// idx into type_ids_list for the type of this field
	brownie_string_id_item	name_index;		// idx into string_ids_list for the name of this field
};

struct brownie_method_id_item
{
	brownie_type_id_item	class_index;
	brownie_proto_id_item	proto_index;
	brownie_string_id_item	name_index;
};

struct brownie_class_def_item
{
	brownie_type_id_item	class_index;
	uint32_t				access_flags;
	brownie_type_id_item	superclass_index;
	size_t					interface_offset;
	brownie_string_id_item	source_index;	// string_ids_list for the name of the file containing original source
	size_t					annotations_offset;
	size_t					class_data_offset;
	size_t					static_values_offset;
};

struct brownie_encoded_field
{
	size_t	field_ids_index;
	uint8_t	access_flags;
};

struct brownie_encoded_method
{
	size_t	method_ids_index;
	uint8_t	access_flags;
	size_t	code_offset;
};



struct brownie_class_data_item
{
	brownie_class_data_item(uint8_t ssz = 0, uint8_t isz = 0, uint8_t dsz = 0, uint8_t vsz = 0) {
		static_fields_size = ssz;
		instance_fields_size = isz;
		direct_methods_size = dsz;
		virtual_methods_size = vsz;

		if (static_fields_size) { static_fields = new brownie_encoded_field[static_fields_size]; }
		if (instance_fields_size) { instance_fields = new brownie_encoded_field[instance_fields_size]; }
		if (direct_methods_size) { direct_methods = new brownie_encoded_method[direct_methods_size]; }
		if (virtual_methods_size) { virtual_methods = new brownie_encoded_method[virtual_methods_size]; }

	}

	void initStaticFields(uint8_t sz) { static_fields_size = sz; static_fields = new brownie_encoded_field[sz]; }
	void initInstanceFields(uint8_t sz) { instance_fields_size = sz; instance_fields = new brownie_encoded_field[sz]; }


	uint8_t		static_fields_size;	// # static fields defined in this item
	uint8_t		instance_fields_size;
	uint8_t		direct_methods_size;
	uint8_t		virtual_methods_size;
	//
	brownie_encoded_field	* static_fields;
	brownie_encoded_field	* instance_fields;
	brownie_encoded_method	* direct_methods;
	brownie_encoded_method	* virtual_methods;
};





////////////////[ BrewScript ABI

////////////////[ BrewASM ABI

/////////////////[ exoKernel System Invocation ABI

/////////////////[ Library Interface ABI


///////////////////////[ Source Level ABI



END_NAMESPACE(abi)
END_NAMESPACE(brew)
#endif