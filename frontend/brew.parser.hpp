/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_BREW_PARSER_HPP_INCLUDED
# define YY_YY_BREW_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MINUS = 258,
     MINUSMINUS = 259,
     EXCLAM = 260,
     EXCLAMEQ = 261,
     EXCLAMEQEQ = 262,
     PERCENT = 263,
     PERCENTEQ = 264,
     AMP = 265,
     AMPAMP = 266,
     AMPEQ = 267,
     LPAREN = 268,
     RPAREN = 269,
     TIMES = 270,
     TIMESEQ = 271,
     COMMA = 272,
     DOT = 273,
     DIV = 274,
     DIVEQ = 275,
     COLON = 276,
     SEMI = 277,
     QUESTION = 278,
     LBRACKET = 279,
     RBRACKET = 280,
     CARET = 281,
     CARETEQ = 282,
     LBRACE = 283,
     PIPE = 284,
     PIPEPIPE = 285,
     PIPEEQ = 286,
     RBRACE = 287,
     TILDE = 288,
     PLUS = 289,
     PLUSPLUS = 290,
     PLUSEQ = 291,
     LT = 292,
     LTLT = 293,
     LTLTEQ = 294,
     LTEQ = 295,
     EQ = 296,
     MINUSEQ = 297,
     EQEQ = 298,
     EQEQEQ = 299,
     GT = 300,
     GTEQ = 301,
     GTGT = 302,
     GTGTEQ = 303,
     GTGTGT = 304,
     GTGTGTEQ = 305,
     ARRAY = 306,
     BOOLEAN = 307,
     BREAK = 308,
     CASE = 309,
     CATCH = 310,
     CONTINUE = 311,
     DECIMALLITERAL = 312,
     DEFAULT = 313,
     DELETE = 314,
     DO = 315,
     ELSE = 316,
     FALSE = 317,
     FINALLY = 318,
     FOR = 319,
     FUNCTION = 320,
     HEXINTEGERLITERAL = 321,
     IDENTIFIER = 322,
     IMPORT = 323,
     IF = 324,
     IN = 325,
     INSTANCEOF = 326,
     NEW = 327,
     NULL = 328,
     PACKAGE = 329,
     PROVIDES = 330,
     REGEXP = 331,
     REQUIRES = 332,
     RETURN = 333,
     STRING = 334,
     STRINGLITERAL = 335,
     SWITCH = 336,
     THIS = 337,
     THROW = 338,
     TRUE = 339,
     TRY = 340,
     TYPEOF = 341,
     VAR = 342,
     VOID = 343,
     WHILE = 344,
     WITH = 345,
     PRIVATE = 346,
     AUTO = 347,
     INTERFACE = 348,
     COMPONENT = 349,
     ENTITY = 350,
     OBJECT = 351,
     MATH = 352,
     PROTOTYPE = 353,
     SYSTEM = 354,
     SYS = 355,
     UNDEFINED = 356,
     JSON = 357,
     ERROR = 358,
     ALIAS = 359,
     IMMUTABLE = 360,
     IMPLEMENTS = 361,
     ENUM = 362,
     EXPORT = 363,
     EXTENDS = 364,
     BININTEGERLITERAL = 365,
     DATE = 366,
     DOLLAR = 367,
     BLUEPRINT = 368,
     COLONCOLON = 369,
     ASM = 370
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 29 "brew.y"

	int ival;
	char * str;


/* Line 2053 of yacc.c  */
#line 178 "brew.parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_BREW_PARSER_HPP_INCLUDED  */
