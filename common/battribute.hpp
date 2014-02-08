#ifndef _BREW_LIB_BATTR_H_
#define _BREW_LIB_BATTR_H_
/**
*
*/
#include "bobject.hpp"

BREW_DYN_LIB class BAttribute : public BObject
{
public:
		bool operation == (BAttribute &);

		brew::string	toString();
protected:
	value_t		_value;
	location_t	_loc;
};





#endif