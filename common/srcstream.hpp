#ifndef _ODS_SRCSTREAM_HPP_
#define _ODS_SRCSTREAM_HPP_
/*******************************************************************************
 ** Name: srcstream.hpp                                                     **
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

#include <iostream>
#include <fstream>

const int SRC_INPUT_LINE_MAX = 256;

class srcstream : public std::iostream
{
public:
	srcstream(char *, char *, char *, bool);
	srcstream();
	~srcstream();

	void	nextch();
	bool	endline();
	void	setListing(bool l) { bListing = l; }
	int		getline();

private:
	bool bListing = false;
	char ch;
	int	currLineNum;
	int charpos;
	char line[SRC_INPUT_LINE_MAX+1];


};



#endif /* _ODS_SRCSTREAM_HPP_ */
