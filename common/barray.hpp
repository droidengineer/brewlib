#ifndef _BREW_LIB_ARRAY_H_
#define _BREW_LIB_ARRAY_H_

#include "bobject.hpp"

template <typename T>
class BArray : public BObject
{
public:
	BArray() : __index(0) { __size = 0; }
	BArray(const int sz) : BObject() {
		__size = sz;
		__index = new T[sz];
	}

	T * operator [] (size_t idx) { return __index[idx]; }
	T * operator T * () { return _index; }

	const size_t size() const { return __size; }

protected:
	T	* __index;
	size_t __size;
};


#endif