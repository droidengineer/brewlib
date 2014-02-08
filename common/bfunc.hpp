#ifndef _BREW_LIB_FUNCTION_H_
#define _BREW_LIB_FUNCTION_H_

BREW_DYN_EXPORT class BFunction : public BObject
{
public:
	BFunction() : BObject(getPrototype()) {

	}

protected:
	BObject *	_scopeChain;


};

__prototype__ (BFunction);


#endif
