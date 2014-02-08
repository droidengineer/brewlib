#ifndef _ODS_SYMTAB_HPP_
#define _ODS_SYMTAB_HPP_
/*******************************************************************************
 ** Name: symtab.hpp                                                     **
 ** Description:                                    **
 **                                                                           **
 ** Open Source Initiative (OSI) Approved License: CDDL                       **
 **                                                                           **
 ** The contents of this file are subject to the terms of the                 **
 ** Common Development and Distribution License, Version 1.0 only             **
 ** (the "License").  You may not use this file except in compliance          **
 ** with the License.                                                         **
 **                                                                           **
 ** You can find a copy of the license in the LICENSE file within             **
 ** this distribution or at http://opensource.org/licenses/CDDL-1.0.          **
 ** Software distributed under the License is distributed on an "AS IS"       **
 ** basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.           **
 ** See the License for the specific language governing permissions           **
 ** and limitations under the License.                                        **
 **                                                                           **
 ** When distributing Covered Code, include this CDDL header in each          **
 ** file and include the License file at $GAME_DIR/LICENSE.                   **
 ** If applicable, add the following below this header, with the indicated    **
 ** fields enclosed by brackets "[]" replaced with your own identifying       **
 ** information: Portions Copyright [yyyy] [name of copyright owner]          **
 **                                                                           **
 ** Copyright (c) 2009-2011  Barry Gian James <gian@gamingods.net>            **
 ** All rights reserved.                                                      **
 ******************************************************************************/
// Portions Copyright 2012-13 Open Design Strategies, LLC
// All Rights Reserved.
// Created Jan 16, 2014 by bjames

#include <string>
#include <map>
#include "brew.hpp"

const int SymTabIDLen = 15;	// max len of identifiers

class IScope
{
protected:
	 virtual const string getScopeName() const;
	 virtual IScope *  getEnclosingScope();
	 virtual void define(BSymbol);
	 virtual BSymbol resolve(string);
};

/**
 *	class T { ... };
 *	T f() { ... }
 *	int x;
 *
 * Type c = new ClassSymbol"T");
 * MethodSymbol = new MethodSymbol("f",c);
 * Type intType = new BuiltInTypeSymbol("int");
 * VariableSymbol v = new VariableSymbol("x", intType);
 */



enum class SymTabIDClass {
	Undefined,
	Const,
	Variable,
	Prog,
	Proc,
	Func,
	Interface,
	Component,
	BuiltIn,
	Block,
	Scope,
	Expression,
	Statement,
	Entity,
	Object,
	Prototype,
	Constructor,
	Member,
	//
	Opcode,
	Operand,
	Register,
	Memory
};

struct BSymbol
{
	BSymbol() : type(SymTabIDClass::Undefined), scope(0)
	{

	}
	BSymbol(const char * n)
		: type(SymTabIDClass::Undefined), scope(0) 
	{
		name = n;
	}
	BSymbol(const char * n, SymTabIDClass t)
		: type(t), scope(0) 
	{
		name = n;
	}

	string		name;
	//char name[SymTabIDLen+1];
	SymTabIDClass type;
	IScope *	scope;

	virtual string toString() {
		if (type != SymTabIDClass::Undefined) {
			return string::Format("<%s:%d>", name, type);
		}
		return name;
	}
};

struct VariableSymbol : public BSymbol
{
	VariableSymbol(const char * n)
		: BSymbol(n,SymTabIDClass::Variable) { }
};

struct BuiltInTypeSymbol : public BSymbol
{
	BuiltInTypeSymbol(const char * n)
		: BSymbol(n,SymTabIDClass::BuiltIn) { }

};

struct ObjectSymbol : public BSymbol, IScope
{
	ObjectSymbol(const char * n)
		: BSymbol(n,SymTabIDClass::Object) { }
	ObjectSymbol(const char * n, SymTabIDClass t)
		: BSymbol(n,t) { }

	IScope * getParentScope() { return constructor; }
	IScope * getPrototypeScope() { return prototype; }

	void	addMember(const string & n, const BSymbol * s) {
		members[n] = s;
	}


	ObjectSymbol * constructor;
	ObjectSymbol * prototype;
	map<string, BSymbol *> members;

};

struct MethodSymbol : public ObjectSymbol
{
	MethodSymbol(const char * n, const ObjectSymbol & o)
		: ObjectSymbol(n,SymTabIDClass::Func), _this(o) { }

	ObjectSymbol & _this;
};

struct ScopedSymbol : public BSymbol, IScope
{
	ScopedSymbol(const char * n, SymTabIDClass c)
		: BSymbol(n,c)
	{

	}

	const string getScopeName() const;
	IScope *  getEnclosingScope();
	void define(BSymbol);
	BSymbol resolve(string);

	IScope * getParentScope() { return getEnclosingScope(); }
};

struct FunctionSymbol : public ObjectSymbol
{
	FunctionSymbol(const char * n)
		: ObjectSymbol(n, SymTabIDClass::Func) { }
};

struct MemberSymbol : public ScopedSymbol
{
	MemberSymbol(const char * n, const ObjectSymbol & o)
		: ScopedSymbol(n,SymTabIDClass::Member), _this(o) { }

	const ObjectSymbol & _this;
};


struct SymTabEntry
{
	//char name[SymTabIDLen+1];
	int level;
	//SymTabIDClass idclass;
	const BSymbol & symbol;

//	SymTabEntry(string & s, SymTabIDClass id = SymTabIDClass::Undefined) {
	SymTabEntry(const BSymbol & sym, int lvl = 0) 
		: symbol(sym)
	{
		int level = lvl;
	}

	union {
		struct {
			int val;
		} c;
		struct {
			int sz, offset;
			bool ref, scalar;
		} v;
		struct {
			int params, paramsz;
			SymTabNode * firstParam;
		} p;
	};

	const string toString() const { return symbol.toString(); }


};

struct SymTabNode
{
	SymTabEntry entry;
	SymTabNode * next;
};

struct SymTabScopeNode
{
	SymTabScopeNode(SymTabScopeNode * n) : down(n), first(0) { }
	SymTabScopeNode * down;
	SymTabNode * first;

	SymTabScopeNode * getEnclosingScope();
};


class SymTab : public IScope
{
public:
	SymTab() { _initTypeSystem(); }

	void	openScope();
	void	closeScope();
	SymTabScopeNode * getCurrentScope();
	SymTabScopeNode * getEnclosingScope();

	void	enter(string & s, SymTabIDClass);
	void	enter(SymTabEntry &, SymTabNode *&);
	SymTabEntry * resolve(string & s);
	void	search(char *, SymTabEntry &, bool &);
	void	update(SymTabEntry &, SymTabNode * pos);
	void	print(std::ostream &);

private:
	SymTabNode *	_sentinel;
	SymTabNode *	_head;
	SymTabScopeNode * _topScope;

	int	_currLevel;

	void _initTypeSystem() {
		enter("int", SymTabIDClass::BuiltIn);
		enter("float", SymTabIDClass::BuiltIn);
	}

};



#endif /* _ODS_SYMTAB_HPP_ */
