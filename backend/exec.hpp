#ifndef _BREW_LIB_EXEC_H_
#define _BREW_LIB_EXEC_H_

/**
*
*/
#include "../common/brew.hpp"
#include "backend.hpp"

BEGIN_NAMESPACE(brew)

#ifndef DEFAULT_RUNTIME_STACK_SIZE
#ifdef __AVR__
#define DEFAULT_RUNTIME_STACK_SIZE	512
#define DEFAULT_RUNTIME_PORTION 0.10
#define DEFAULT_APP_STACK_SIZE	256
#else
#define DEFAULT_RUNTIME_STACK_SIZE	1024
#define DEFAULT_RUNTIME_PORTION 0.25
#define DEFAULT_APP_STACK_SIZE	512
#endif
#endif

BEGIN_NAMESPACE(vm)

union BStackItem {
	uint8_t		i8;
	uint16_t	i16;
	uint32_t	i32;
	size_t		i;
	float		f;
	double		d;
	char		c;
	void *		addr;
};

class BRuntimeStack
{
public:
	struct FrameHeader {
		BStackItem	fctVal;
		BStackItem	staticLink;
		BStackItem	dynamicLink;

		struct {
			BStackItem icode;
			BStackItem	location;
		} returnAddress;
	};

public:
	BRuntimeStack();
	explicit BRuntimeStack(uint16_t sz);

	void	push(uint8_t v) {
		if (_tos < &_stack[DEFAULT_RUNTIME_STACK_SIZE-1])
			(++_tos)->i8 = v;
		//else RunTimeError(rteStackOverflow);
	}
	void	push(uint16_t v) {
		if (_tos < &_stack[DEFAULT_RUNTIME_STACK_SIZE-1])
			(++_tos)->i16 = v;
	}
	void	push(uint32_t v) {
		if (_tos < &_stack[DEFAULT_RUNTIME_STACK_SIZE-1])
			(++_tos)->i32 = v;
	}
	void	push(float v) {
		if (_tos < &_stack[DEFAULT_RUNTIME_STACK_SIZE-1])
			(++_tos)->f = v;
	}	
	void	push(char v) {
		if (_tos < &_stack[DEFAULT_RUNTIME_STACK_SIZE-1])
			(++_tos)->c = v;
	}
	void	push(void * v) {
		if (_tos < &_stack[DEFAULT_RUNTIME_STACK_SIZE-1])
			(++_tos)->addr = v;
	}

	BStackItem * pop() { return _tos--; }
	const BStackItem * TOS const { return _tos; }

	BStackItem * pushFrameHeader(int oldlvl, int newlvl, BICode * ic);
	void	activateFrame(BStackItem * newframebase, int loc);
	void	popFrame(const SymTabNode * procid, BICode *& ic);


protected:
	BStackItem	_stack[DEFAULT_RUNTIME_STACK_SIZE];
	BStackItem *	_tos;
	BStackItem *	_frameBase;
	uint16_t	_szInitial;

	void	_alloc(const SymTabNode *);
	void	_dealloc(const SymTabNode *);
};

typedef BRuntimeStack stack;

END_NAMESPACE(vm)


////////////////////////////////////[ Interpreter/Executor
class BExecutor : public BrewBackend
{
public:

protected:
	uint32_t	stmtCount;

	// statements
	void	execStatement();
	void	execAssignment(const SymTabNode & n);
	

	// expressions
	type_t *	execExpression();
	type_t *	execSimpleExpression();
	type_t *	execTerm();
	type_t *	execFactor();
	type_t *	execConstant(const SymTabNode &);
};




END_NAMESPACE(brew)

#endif