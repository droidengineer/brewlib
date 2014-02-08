#ifndef _BREW_LIB_SHARED_H_
#define _BREW_LIB_SHARED_H_

#define __prototype__(obj)	class B ## obj ## Prototype : public obj \
	{	\
		B ## obj ## Prototype(VMContext * vmc)	\
		{	\
			obj(vmc);	\
			static NativeFctData _nfd[] =	\
			{	\
				{ &TEXT_toString, &B ## obj ## PrototypeToString, 0 },	\
			};	\
		}	\
	}


#endif
