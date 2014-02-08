#ifndef _BREW_LIB_AST_H_
#define _BREW_LIB_AST_H_

#include "brew.hpp"
#include "types.h"
#include "bobject.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <llvm/CodeGen/ValueTypes.h>


enum class Operator { EQU, LST, GTR, ADD, SUB, MUL, DIV };
typedef std::vector<BrewStatement *> StatementList;
typedef vector<BrewExpression *> ExpressionList;
typedef vector<BrewVariableDecl *> VariableList;

class ASTNode
{
public:
	virtual ~ASTNode() { }

protected:
	virtual llvm::Value *	codeGen(CodeGenContext & ctx) { }
};

class BrewExpression : public ASTNode
{
public:
	virtual ~BrewExpression() { }
};

class BrewStatement : public ASTNode
{
public:
	BrewStatement(const BrewIdentifier & t, const BrewIdentifier & i) 
		: _type(t), _id(i)
	{}
	virtual ~BrewStatement() { }

	const BrewIdentifier & _type;
	const BrewIdentifier & _id;
};

// ZOMG ok can i get rid of *all* those Brew?Int?? below with generics?

class BrewTerminal : public BrewExpression
{
public:
	BrewTerminal(FundamentalStorageType t) : _type(t) { }
	virtual ~BrewTerminal() { }

	virtual const FundamentalStorageType type() const { return _type; }
	virtual llvm::Type * codeGen(/* VMContext & */);


private:
	FundamentalStorageType	_type;

};


class BrewInt8 : public BrewTerminal
{
public:
	BrewInt8(int8_t i) 
		: BrewTerminal(FundamentalStorageType::Int8),  _value(i) { }

	const int8_t value() const { return _value; }
	operator int8_t () { return _value; }

private:
	int8_t		_value;
};

class BrewInt16 : public BrewTerminal
{
public:
	BrewInt16(int16_t i) 
		: BrewTerminal(FundamentalStorageType::Int16), _value(i) 
	{ }

	const int16_t value() const { return _value; }
	operator int16_t () { return _value; }

private:
	int16_t	_value;
};

class BrewInt32 : public BrewTerminal
{
public:
	BrewInt32(int32_t i) 
		: BrewTerminal(FundamentalStorageType::Int32), _value(i) 
	{ }

	const int32_t value() const { return _value; }
	operator int32_t () { return _value; }

private:
	int32_t		_value;
};

class BrewUInt16 : public BrewTerminal
{
public:
	BrewUInt16(uint16_t i) 
		: BrewTerminal(FundamentalStorageType::UInt16), _value(i) 
	{ }

	const uint16_t value() const { return _value; }
	operator uint16_t () { return _value; }

private:
	uint16_t	_value;
};

class BrewUInt8 : public BrewTerminal
{
public:
	BrewUInt8(uint8_t i) 
		: BrewTerminal(FundamentalStorageType::UInt8), _value(i) 
	{ }

	const uint8_t value() const { return _value; }
	operator uint8_t () { return _value; }

private:
	uint8_t		_value;

	virtual llvm::Type * codeGen(/* VMContext & */);
};

class BrewUInt32 : public BrewTerminal
{
public:
	BrewUInt32(uint32_t i) 
		: BrewTerminal(FundamentalStorageType::UInt32), _value(i) 
	{ }

	const uint32_t value() const { return _value; }
	operator uint32_t () { return _value; }

private:
	uint32_t	_value;
};

class BrewDouble : public BrewTerminal
{
public:
	BrewDouble(double i) 
		: BrewTerminal(FundamentalStorageType::Double), _value(i) 
	{ }

	const double value() const { return _value; }
	operator double () { return _value; }

private:
	double	_value;
};

class BrewArray : public BrewTerminal
{
public:
	BrewArray(BrewTerminal * array[])
		: BrewTerminal(FundamentalStorageType::Array)
	{

	}

private:
	

};

class BrewString : public BrewTerminal
{
public:
	BrewString(std::string & s)
		: BrewTerminal(FundamentalStorageType::String), _value(s)
	{

	}

private:
	std::string _value;
};

class BrewOpaque : public BrewTerminal
{
public:
	BrewOpaque(void * o)
		: BrewTerminal(FundamentalStorageType::VoidPtr), _value(o)
	{

	}

private:
	void * _value;
};

class BrewIdentifier : public BrewTerminal
{
public:
	BrewIdentifier(const char * n) 
		: BrewTerminal(FundamentalStorageType::String), _name(n) 
	{ }
	BrewIdentifier(const string & s) 
		: BrewTerminal(FundamentalStorageType::String), _name(s) { }

	const string value() const { return _name; }
private:
	string _name;
};

class BrewMethodCall : public BrewExpression
{
public:
	BrewMethodCall(const BrewIdentifier & i, ExpressionList & a)
		: _id(i), _args(a) { }
	BrewMethodCall(const BrewIdentifier & i) 
		: _id(i) { }
private:
	const BrewIdentifier & _id;
	ExpressionList	 _args;
};

class BrewBlock : public BrewExpression
{
private:
	ExpressionList		_statements;
};

class BrewAssignment : public BrewExpression
{
private:
	BrewIdentifier & _lhs;
	BrewExpression & _rhs;
};

class BrewBinaryOperator : public BrewExpression
{
private:
	int _op;
	BrewExpression & _lhs;
	BrewExpression & _rhs;
};


///////////////////////////////[ BrewStatement...


class BrewFunctionDecl : public BrewStatement
{
public:
	BrewFunctionDecl(const BrewBlock & b, const BrewIdentifier & t, const BrewIdentifier i)
		: BrewStatement(t,i), _block(b)
	{

	}
private:

	VariableList	_args;
	BrewBlock &		_block;
};

class BrewVariableDecl : public BrewStatement
{
private:
	BrewExpression *	_assignExpr;
};

class BrewExpressionStatement : public BrewStatement
{
public:
	BrewExpressionStatement(BrewExpression & e, const BrewIdentifier & t, const BrewIdentifier & i) 
		: BrewStatement(t,i), _expr(e) { }
	BrewExpression &	_expr;
};



//class Node { virtual value_t * codeGen(); };
//class Expression : public Node { 
//	Operator op;
//
//};
//
//class BinExpr : public Expression
//{
//	Expr * left, * right;
//	BinExpr(Expr * e1, Operator o, Expr * e2) { op = o; left = e1; right = e2; }
//};
//
//class UnaryExpr : public Expression
//{
//	Expr * e;
//	UnaryExpr(Operator x, Expr * y) { op = x; e = y; }
//};
//
//class Ident : public Expression
//{
//	Object * obj;
//	Ident(Object o) { obj = o; }
//};



#endif