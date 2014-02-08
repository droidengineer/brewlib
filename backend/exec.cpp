#include "exec.hpp"
#include "../common/symtab.hpp"

/////////////////////////////////[ BRuntimeStack
/** \param blah
 *  \ret UInt32
 */

void
BRuntimeStack::_alloc(const SymTabNode * n)
{

}

void
BRuntimeStack::_dealloc(const SymTabNode * n)
{

}

BRuntimeStack::BRuntimeStack()
	: _tos(_stack), _frameBase(_stack)
{
	_szInitial = DEFAULT_RUNTIME_STACK_SIZE;
}

BRuntimeStack::BRuntimeStack(uint16_t sz)
	: _tos(_stack), _frameBase(_stack)
{
	_szInitial = sz;
}

