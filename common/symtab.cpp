/*******************************************************************************
 ** Name: symtab.cpp                                                       **
 ** Description:              **
 **                                                                           **
 ** Open Source Initiative (OSI) Approved License                             **
 **                                                                           **
 ** The contents of this file are subject to the terms of the                 **
 ** Common Development and Distribution License, Version 1.0 only             **
 ** (the "License").  You may not use this file except in compliance          **
 ** with the License.                                                         **
 **                                                                           **
 ** You can find a copy of the license in the LICENSE file within             **
 ** this distribution or at $GOVTSANCT_WIKI/License-software.                **
 ** Software distributed under the License is distributed on an "AS IS"       **
 ** basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.           **
 ** See the License for the specific language governing permissions           **
 ** and limitations under the License.                                        **
 **                                                                           **
 ** When distributing Covered Code, include this CDDL header in each          **
 ** file and include the License file at $HOME/LICENSE.                      **
 ** If applicable, add the following below this header, with the indicated    **
 ** fields enclosed by brackets "[]" replaced with your own identifying       **
 ** information: Portions Copyright [yyyy] [name of copyright owner]          **
 **                                                                           **
 ** Copyright 2009-2012  Barry Gian James <jamesbl@research.cs.colorado.edu>  **
 ** All rights reserved.                                                      **
 **                                                                           **
 ** Ref: $HeadURL$
 ******************************************************************************/

// $Id$
// Modified $Date$ by $Author$

#include "symtab.hpp"

SymTab::SymTab() : sentinel(0), topScope(0)
{
	currLevel = 0;
}

void
SymTab::openScope()
{

}

void
SymTab::closeScope()
{

}

void
SymTab::enter(SymTabEntry & e, SymTabNode *& n)
{

}

void
SymTab::search(char * n, SymTabEntry & e, bool & b)
{

}

void
SymTab::update(SymTabEntry & e, SymTabNode * p)
{

}

void
SymTab::print(std::ostream & o)
{

}

