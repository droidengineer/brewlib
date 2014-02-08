#ifndef _BREW_LIB_BREW_H_
#define _BREW_LIB_BREW_H_

#include "common.h"
#include "types.h"

#define DISABLE 0
#define ENABLE 1
#define LOW 0
#define HIGH 1


// nop macros for library housekeeping purposes
#define BREW_DB_API
#define BREW_VM_API
#define BREW_OS_API

#define __ATTRIBUTE_SRAM__ __attribute__ ((section("extmem")))
#define __ATTRIBUTE_NOR__ __attribute__ ((section("nor")))
#define __ATTRIBUTE_CACHE__ __attribute__ ((section("cache")))
#define __ATTRIBUTE_BIOS__ __attribute__ ((section("atbios")))
#define __ATTRIBUTE_NAND__ __attribute__ ((section("nand")))
#define __ATTRIBUTE_XIP__ __attribute__ ((section("exec")))

#define EXTMEM __ATTRIBUTE_SRAM__ 
#define NOR __ATTRIBUTE_NOR__ 
#define CACHE __ATTRIBUTE_CACHE__ 
#define BIOS __ATTRIBUTE_BIOS__ 
#define NAND __ATTRIBUTE_NAND__ 
#define XIP __ATTRIBUTE_XIP__
#define SDCARD	NAND
#define __DEPRECATED__ __attribute__((__deprecated__))
#define __FORCE_INLINE__	inline __attribute__((__always_inline__))
#define __FORCE_OPTIMIZE__	__attribute__((optimize(3)))

#define SET_OBJECT_PROPERTY(multi)	__attribute__ ((target ("multi")))

#ifdef CDECL
#define BREW_DYN_EXPORT __declspec(dllexport)
#define BREW_DYN_IMPORT __declspec(dllimport)
#define BREW_MODULE_t	extern "C" __declspec(dllexport) ::Brew::Module *
#else
#define BREW_DYN_EXPORT
#define BREW_DYN_IMPORT
#define BREW_MODULE_t	(extern "C" ::Brew::Module *)
#endif

#define isExprConstant(exp)		__builtin_constant_p(exp)




#endif