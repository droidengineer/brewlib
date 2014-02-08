#ifndef _BREW_LIB_BSTRING_H_
#define _BREW_LIB_BSTRING_H_

#include <string>
#include "brew.hpp"
#include "bobject.hpp"

BEGIN_NAMESPACE(brew)

// I'm just an internal representation of a string object. I don't offer a whole lot
// of options or functionality, but do provide a seemless container for use between
// the different trees (semantic, parse, ast) and the virtual machine.
class BString : public BObject
{
public:
	BString() { }
	BString(char *s) { __data = s; }
	BString(std::string & s) { __data = s; }
	BString(const BString & b) { __data = b.__data; }

	operator char * () { return __data.c_str(); }
	operator std::string () { return __data; }


private:
	std::string	__data;

};
typedef BString string;


END_NAMESPACE(brew)



#endif