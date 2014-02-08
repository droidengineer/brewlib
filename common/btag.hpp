#ifndef _BREW_LIB_TAG_H_
#define _BREW_LIB_TAG_H_

#include "bobject.hpp"

BREW_DYN_LIB class BTag : public BObject
{
public:
	struct Range {
		BTag *	tag;
		brew::string	namespace;

		bool empty();
		BTag *	front();
		void	popFront();
		BTag *	back();
		void	popBack();
		uint16_t length();

		BTag * operator [] (size_t idx);
		uint16_t operator $ () { return length(); }
	};

	BTag *	add(value_t &val);
	BTag *	add(BAttribute &attr);
	BTag *	add(BAttribute * attr[]);
	BTag *	add(BTag &tag);
	BTag *	add(BTag * tag[]);

	BTag *	parent();
	brew::string getNamespace();
	BAttribute::Range	attributes();
	Range	tags();

	bool operation == (BTag &);

	brew::string	toString();

protected:
	location_t	_loc;
	value_t		_val;
};


#endif