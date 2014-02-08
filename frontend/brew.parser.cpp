/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 4 "brew.y"

#include "symtab.hpp"
#include "codestream.hpp"

extern int lineno;

enum seg { text, data, exec, overlay, const_pool };
enum fmt { ihex, bin };

int yylex(void);
void yyerror(char *);

void error(const char *, ...);

void emitString();
void emit8(uint8_t);
void emit16(uint16_t);
void emit32(uint32_t);

void setsym(char *, uint16_t);
uint16_t getsym(const char *);


/* Line 371 of yacc.c  */
#line 92 "brew.parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "brew.parser.hpp".  */
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
/* Line 387 of yacc.c  */
#line 29 "brew.y"

	int ival;
	char * str;


/* Line 387 of yacc.c  */
#line 256 "brew.parser.cpp"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 284 "brew.parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  225
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1778

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  117
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  234
/* YYNRULES -- Number of states.  */
#define YYNSTATES  457

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   370

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   116,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    49,    51,    53,    55,    57,
      59,    63,    65,    68,    72,    76,    82,    84,    87,    90,
      95,    99,   101,   105,   109,   115,   117,   119,   121,   123,
     125,   127,   129,   131,   133,   135,   140,   144,   148,   150,
     152,   155,   158,   161,   166,   170,   173,   177,   181,   186,
     190,   192,   196,   198,   200,   202,   205,   208,   210,   213,
     216,   219,   222,   225,   228,   231,   234,   237,   239,   243,
     247,   251,   255,   259,   261,   265,   269,   273,   275,   277,
     281,   285,   289,   293,   297,   299,   303,   307,   311,   315,
     317,   321,   323,   327,   329,   333,   335,   339,   341,   345,
     347,   353,   355,   359,   361,   363,   365,   367,   369,   371,
     373,   375,   377,   379,   381,   383,   385,   389,   391,   393,
     395,   397,   399,   401,   403,   405,   407,   409,   411,   413,
     415,   417,   419,   421,   423,   425,   427,   430,   434,   437,
     441,   444,   448,   450,   453,   457,   461,   463,   467,   469,
     472,   475,   477,   483,   491,   499,   505,   515,   526,   534,
     543,   546,   550,   553,   557,   560,   564,   571,   577,   580,
     584,   589,   595,   600,   604,   606,   609,   614,   618,   621,
     625,   629,   632,   636,   640,   645,   651,   654,   663,   671,
     678,   686,   695,   703,   710,   718,   727,   735,   742,   750,
     759,   767,   774,   782,   784,   788,   790,   791,   793,   795,
     798,   800,   802,   804,   806
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     194,     0,    -1,   119,    -1,   121,    -1,   122,    -1,    80,
      -1,   120,    -1,    73,    -1,   101,    -1,    84,    -1,    62,
      -1,    57,    -1,    66,    -1,   110,    -1,    76,    -1,    82,
      -1,    98,    -1,    67,    -1,    96,    -1,    65,    -1,    51,
      -1,    79,    -1,    52,    -1,   111,    -1,    76,    -1,   102,
      -1,   103,    -1,   118,    -1,   125,    -1,   128,    -1,    13,
     154,    14,    -1,   123,    -1,    24,    25,    -1,    24,   126,
      25,    -1,    24,   127,    25,    -1,    24,   127,    17,   126,
      25,    -1,    17,    -1,   126,    17,    -1,   126,   152,    -1,
     127,    17,   126,   152,    -1,   127,    17,   152,    -1,   152,
      -1,    28,   129,    32,    -1,   130,    21,   152,    -1,   129,
      17,   130,    21,   152,    -1,    67,    -1,    80,    -1,   122,
      -1,   124,    -1,   185,    -1,   132,    -1,   187,    -1,   189,
      -1,   191,    -1,   136,    -1,   131,    24,   154,    25,    -1,
     131,    18,    67,    -1,    72,   131,   135,    -1,   131,    -1,
     131,    -1,    72,   133,    -1,   131,   135,    -1,   134,   135,
      -1,   134,    24,   154,    25,    -1,   134,    18,    67,    -1,
      13,    14,    -1,    13,   137,    14,    -1,    97,   116,    67,
      -1,    97,   116,    67,   135,    -1,    99,   116,    67,    -1,
     152,    -1,   137,    17,   152,    -1,   133,    -1,   134,    -1,
     138,    -1,   139,    35,    -1,   139,     4,    -1,   139,    -1,
      59,   140,    -1,    88,   140,    -1,    86,   140,    -1,    35,
     140,    -1,     4,   140,    -1,    34,   140,    -1,     3,   140,
      -1,    33,   140,    -1,     5,   140,    -1,   140,    -1,   140,
      15,   141,    -1,   140,    19,   141,    -1,   140,     8,   141,
      -1,   142,    34,   141,    -1,   142,     3,   141,    -1,   141,
      -1,   143,    38,   142,    -1,   143,    47,   142,    -1,   143,
      49,   142,    -1,   142,    -1,   143,    -1,   144,    37,   143,
      -1,   144,    45,   143,    -1,   144,    40,   143,    -1,   144,
      46,   143,    -1,   144,    71,   143,    -1,   144,    -1,   145,
      43,   144,    -1,   145,     6,   144,    -1,   145,    44,   144,
      -1,   145,     7,   144,    -1,   145,    -1,   146,    10,   145,
      -1,   146,    -1,   147,    26,   146,    -1,   147,    -1,   148,
      29,   147,    -1,   148,    -1,   149,    11,   148,    -1,   149,
      -1,   150,    30,   149,    -1,   150,    -1,   150,    23,   152,
      21,   152,    -1,   151,    -1,   138,   153,   152,    -1,    41,
      -1,    16,    -1,    20,    -1,     9,    -1,    36,    -1,    42,
      -1,    39,    -1,    48,    -1,    50,    -1,    12,    -1,    27,
      -1,    31,    -1,   152,    -1,   154,    17,   152,    -1,   159,
      -1,   161,    -1,   162,    -1,   166,    -1,   167,    -1,   168,
      -1,   169,    -1,   170,    -1,   171,    -1,   172,    -1,   173,
      -1,   179,    -1,   174,    -1,   180,    -1,   181,    -1,   154,
      -1,   156,    -1,   157,    -1,   158,    -1,    74,    67,    -1,
      74,    67,   116,    -1,    68,    67,    -1,    68,    67,   116,
      -1,    28,    32,    -1,    28,   160,    32,    -1,   155,    -1,
     160,   155,    -1,    87,   163,    22,    -1,    92,   163,    22,
      -1,   164,    -1,   163,    17,   164,    -1,    67,    -1,    67,
     165,    -1,    41,   152,    -1,    22,    -1,    69,    13,   154,
      14,   155,    -1,    69,    13,   154,    14,   155,    61,   155,
      -1,    60,   155,    89,    13,   154,    14,    22,    -1,    89,
      13,   154,    14,   155,    -1,    64,    13,   154,    22,   154,
      22,   154,    14,   155,    -1,    64,    13,    87,   163,    22,
     154,    22,   154,    14,   155,    -1,    64,    13,   138,    70,
     154,    14,   155,    -1,    64,    13,    87,   164,    70,   154,
      14,   155,    -1,    56,    22,    -1,    56,    67,    22,    -1,
      53,    22,    -1,    53,    67,    22,    -1,    78,    22,    -1,
      78,   154,    22,    -1,    90,    13,   154,    14,   155,    22,
      -1,    81,    13,   154,    14,   175,    -1,    28,    32,    -1,
      28,   176,    32,    -1,    28,   176,   178,    32,    -1,    28,
     176,   178,   176,    32,    -1,    28,   178,   176,    32,    -1,
      28,   178,    32,    -1,   177,    -1,   176,   177,    -1,    54,
     154,    21,   160,    -1,    54,   154,    21,    -1,    58,    21,
      -1,    58,    21,   160,    -1,    67,    21,   155,    -1,    83,
     154,    -1,    85,   159,   182,    -1,    85,   159,   183,    -1,
      85,   159,   182,   183,    -1,    55,    13,    67,    14,   159,
      -1,    63,   159,    -1,    65,    67,    13,   192,    14,    28,
     193,    32,    -1,    65,    67,    13,    14,    28,   193,    32,
      -1,    65,    13,    14,    28,   193,    32,    -1,    65,    13,
     192,    14,    28,   193,    32,    -1,    93,    67,    13,   192,
      14,    28,   193,    32,    -1,    93,    67,    13,    14,    28,
     193,    32,    -1,    93,    13,    14,    28,   193,    32,    -1,
      93,    13,   192,    14,    28,   193,    32,    -1,    94,    67,
      13,   192,    14,    28,   193,    32,    -1,    94,    67,    13,
      14,    28,   193,    32,    -1,    94,    13,    14,    28,   193,
      32,    -1,    94,    13,   192,    14,    28,   193,    32,    -1,
      95,    67,    13,   192,    14,    28,   193,    32,    -1,    94,
      67,    13,    14,    28,   193,    32,    -1,    95,    13,    14,
      28,   193,    32,    -1,    95,    13,   192,    14,    28,   193,
      32,    -1,    67,    -1,   192,    17,    67,    -1,   195,    -1,
      -1,   195,    -1,   196,    -1,   195,   196,    -1,   155,    -1,
     184,    -1,   186,    -1,   188,    -1,   190,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   158,   158,   159,   160,   161,   162,   165,   168,   171,
     172,   175,   176,   177,   180,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   202,   203,   204,   205,   208,   209,   212,   213,
     214,   215,   218,   221,   222,   225,   226,   227,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   242,   245,
     246,   249,   250,   251,   252,   255,   256,   259,   260,   261,
     264,   265,   268,   269,   272,   273,   274,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   289,   290,   291,
     292,   295,   296,   297,   300,   301,   302,   303,   306,   307,
     308,   309,   310,   311,   314,   315,   316,   317,   318,   321,
     322,   325,   326,   329,   330,   333,   334,   337,   338,   341,
     342,   345,   346,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   363,   364,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   386,   387,   390,   391,   394,   395,
     398,   399,   402,   403,   406,   409,   412,   413,   416,   417,
     420,   423,   426,   429,   432,   433,   434,   435,   436,   437,
     440,   441,   444,   445,   448,   449,   452,   455,   458,   459,
     460,   461,   462,   463,   466,   467,   470,   471,   474,   475,
     478,   481,   484,   485,   486,   489,   492,   495,   496,   499,
     500,   503,   504,   506,   507,   510,   511,   514,   515,   518,
     519,   522,   523,   526,   527,   530,   531,   534,   537,   538,
     541,   542,   543,   544,   545
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MINUS", "MINUSMINUS", "EXCLAM",
  "EXCLAMEQ", "EXCLAMEQEQ", "PERCENT", "PERCENTEQ", "AMP", "AMPAMP",
  "AMPEQ", "LPAREN", "RPAREN", "TIMES", "TIMESEQ", "COMMA", "DOT", "DIV",
  "DIVEQ", "COLON", "SEMI", "QUESTION", "LBRACKET", "RBRACKET", "CARET",
  "CARETEQ", "LBRACE", "PIPE", "PIPEPIPE", "PIPEEQ", "RBRACE", "TILDE",
  "PLUS", "PLUSPLUS", "PLUSEQ", "LT", "LTLT", "LTLTEQ", "LTEQ", "EQ",
  "MINUSEQ", "EQEQ", "EQEQEQ", "GT", "GTEQ", "GTGT", "GTGTEQ", "GTGTGT",
  "GTGTGTEQ", "ARRAY", "BOOLEAN", "BREAK", "CASE", "CATCH", "CONTINUE",
  "DECIMALLITERAL", "DEFAULT", "DELETE", "DO", "ELSE", "FALSE", "FINALLY",
  "FOR", "FUNCTION", "HEXINTEGERLITERAL", "IDENTIFIER", "IMPORT", "IF",
  "IN", "INSTANCEOF", "NEW", "NULL", "PACKAGE", "PROVIDES", "REGEXP",
  "REQUIRES", "RETURN", "STRING", "STRINGLITERAL", "SWITCH", "THIS",
  "THROW", "TRUE", "TRY", "TYPEOF", "VAR", "VOID", "WHILE", "WITH",
  "PRIVATE", "AUTO", "INTERFACE", "COMPONENT", "ENTITY", "OBJECT", "MATH",
  "PROTOTYPE", "SYSTEM", "SYS", "UNDEFINED", "JSON", "ERROR", "ALIAS",
  "IMMUTABLE", "IMPLEMENTS", "ENUM", "EXPORT", "EXTENDS",
  "BININTEGERLITERAL", "DATE", "DOLLAR", "BLUEPRINT", "COLONCOLON", "ASM",
  "'.'", "$accept", "literal", "null_literal", "undefined_literal",
  "boolean_literal", "numeric_literal", "regular_expression_literal",
  "primary_expression", "array_literal", "elision", "element_list",
  "object_literal", "property_name_and_value_list", "property_name",
  "member_expression", "object_expression", "new_expression",
  "call_expression", "arguments", "builtin_expression", "argument_list",
  "left_hand_side_expression", "postfix_expression", "unary_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "bitwise_and_expression",
  "bitwise_xor_expression", "bitwise_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "statement", "directives", "package_statement",
  "import_statement", "block", "statement_list", "variable_statement",
  "auto_statement", "variable_declaration_list", "variable_declaration",
  "initializer", "empty_statement", "if_statement", "if_else_statement",
  "iteration_statement", "continue_statement", "break_statement",
  "return_statement", "with_statement", "switch_statement", "case_block",
  "case_clauses", "case_clause", "default_clause", "labelled_statement",
  "throw_statement", "try_statement", "catch", "finally",
  "function_declaration", "function_expression", "interface_declaration",
  "interface_expression", "component_declaration", "component_expression",
  "entity_declaration", "entity_expression", "formal_parameter_list",
  "function_body", "program", "source_elements", "source_element", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   117,   118,   118,   118,   118,   118,   119,   120,   121,
     121,   122,   122,   122,   123,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   125,   125,   126,   126,   127,   127,
     127,   127,   128,   129,   129,   130,   130,   130,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   132,   133,
     133,   134,   134,   134,   134,   135,   135,   136,   136,   136,
     137,   137,   138,   138,   139,   139,   139,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   141,   141,   141,
     141,   142,   142,   142,   143,   143,   143,   143,   144,   144,
     144,   144,   144,   144,   145,   145,   145,   145,   145,   146,
     146,   147,   147,   148,   148,   149,   149,   150,   150,   151,
     151,   152,   152,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   154,   154,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   156,   156,   157,   157,   158,   158,
     159,   159,   160,   160,   161,   162,   163,   163,   164,   164,
     165,   166,   167,   168,   169,   169,   169,   169,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   174,   175,   175,
     175,   175,   175,   175,   176,   176,   177,   177,   178,   178,
     179,   180,   181,   181,   181,   182,   183,   184,   184,   185,
     185,   186,   186,   187,   187,   188,   188,   189,   189,   190,
     190,   191,   191,   192,   192,   193,   193,   194,   195,   195,
     196,   196,   196,   196,   196
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     3,     5,     1,     2,     2,     4,
       3,     1,     3,     3,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     1,     1,
       2,     2,     2,     4,     3,     2,     3,     3,     4,     3,
       1,     3,     1,     1,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     2,     3,
       2,     3,     1,     2,     3,     3,     1,     3,     1,     2,
       2,     1,     5,     7,     7,     5,     9,    10,     7,     8,
       2,     3,     2,     3,     2,     3,     6,     5,     2,     3,
       4,     5,     4,     3,     1,     2,     4,     3,     2,     3,
       3,     2,     3,     3,     4,     5,     2,     8,     7,     6,
       7,     8,     7,     6,     7,     8,     7,     6,     7,     8,
       7,     6,     7,     1,     3,     1,     0,     1,     1,     2,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,   171,     0,     0,     0,     0,
       0,    20,    22,     0,     0,    11,     0,     0,    10,     0,
      19,    12,    17,     0,     0,     0,     7,     0,    14,     0,
      21,     5,     0,    15,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,    16,     0,
       8,    25,    26,    13,    23,    27,     2,     6,     3,     4,
      31,    48,    28,    29,    58,    50,    72,    73,    54,    74,
      77,    87,    93,    97,    98,   104,   109,   111,   113,   115,
     117,   119,   121,   135,   152,   230,   153,   154,   155,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     149,   148,   150,   151,   231,    49,   232,    51,   233,    52,
     234,    53,     0,   227,   228,     0,    19,    17,     0,     0,
       0,    74,    84,    82,    86,     0,    36,    32,     0,     0,
      41,   160,    17,     5,     4,     0,     0,   162,     0,    85,
      83,    81,   182,     0,   180,     0,    78,     0,     0,     0,
       0,     0,   158,     0,    58,    60,   156,   184,     0,     0,
     201,     0,     0,    80,   168,     0,   166,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     0,     0,    62,   126,   132,   124,   125,
     133,   134,   127,   129,   123,   128,   130,   131,     0,    76,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,   229,    45,    46,    47,
      30,    37,    33,    38,     0,    34,     0,    42,     0,   161,
     163,   183,   181,     0,     0,    74,     0,     0,   223,     0,
       0,   200,   159,     0,    57,   157,   185,     0,     0,     0,
     202,   203,     0,   169,     0,   164,     0,     0,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    69,
      65,     0,    70,    56,     0,    64,     0,   122,    90,    88,
      89,    92,    91,    94,    95,    96,    99,   101,   100,   102,
     103,   106,   108,   105,   107,   110,   112,   114,   116,     0,
     118,   136,     0,    40,     0,    43,     0,     0,   166,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,   206,
     204,   170,   167,     0,     0,   226,     0,     0,     0,   226,
       0,     0,     0,   226,     0,     0,    68,    66,     0,    55,
      63,     0,    35,    39,     0,     0,     0,     0,     0,     0,
       0,   225,   226,   224,   226,     0,   172,     0,   187,     0,
     175,     0,     0,   226,   226,     0,     0,   226,   226,     0,
       0,   226,     0,    71,   120,    44,     0,     0,     0,     0,
       0,   209,     0,     0,   226,     0,   188,     0,     0,     0,
     194,     0,     0,   186,   213,     0,     0,   226,   217,     0,
       0,   226,   221,     0,   226,   174,     0,     0,   178,     0,
     210,   208,     0,   173,     0,   198,   189,   195,     0,   193,
       0,   205,   214,   212,     0,   218,   216,     0,   222,     0,
       0,   179,     0,   207,   197,   199,   190,     0,   192,   211,
     215,   219,     0,   176,   196,   191,   177
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    55,    56,    57,    58,    59,    60,    61,    62,   128,
     129,    63,   135,   136,    64,    65,    66,    67,   182,    68,
     281,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,   198,    84,    85,    86,
      87,    88,    89,   138,    90,    91,   165,   166,   263,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   368,   399,
     400,   401,   101,   102,   103,   260,   261,   104,   105,   106,
     107,   108,   109,   110,   111,   249,   360,   112,   361,   114
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -401
static const yytype_int16 yypact[] =
{
     701,  1610,  1610,  1610,  1610,  -401,   903,   398,  1610,  1610,
    1610,  -401,  -401,    12,    31,  -401,  1610,   802,  -401,    42,
       4,  -401,    -6,   -11,    91,  1667,  -401,    65,  -401,  1206,
    -401,  -401,   142,  -401,  1610,  -401,   148,  1610,    67,  1610,
     159,   174,    67,     5,     6,     7,  -401,    64,  -401,    77,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,   146,  -401,  -401,   155,  -401,   121,
      56,   167,  -401,    11,   150,    76,    21,   193,   191,   175,
     207,   144,  -401,  -401,   206,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,   224,   701,  -401,   -28,   220,  -401,   246,   289,
     294,  -401,  -401,  -401,  -401,   217,  -401,  -401,  1004,    32,
    -401,  -401,    -6,   287,   288,   106,   290,  -401,   499,  -401,
    -401,  -401,  -401,   226,  -401,   292,  -401,   223,  1307,     8,
     302,   802,   202,  1610,   146,  -401,   204,  -401,    84,  1610,
     206,   600,     3,  -401,   281,   129,  -401,  -401,  1610,  1610,
     172,    10,   308,    16,   310,    19,   311,   258,   261,  1408,
     262,  1610,  -401,   263,  1610,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  1610,  -401,
    -401,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,  1610,
    1610,  1610,  1610,  1610,  1610,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  1509,  -401,   -28,  -401,  1610,  -401,
    -401,  -401,  -401,   318,    67,    69,   178,   304,  -401,   227,
      26,  -401,  -401,   228,  -401,  -401,  -401,   229,   320,   148,
     271,  -401,  1610,  -401,    67,  -401,   233,   235,  -401,   307,
     239,    27,   309,   240,    28,   312,   241,   269,   325,  -401,
    -401,   268,  -401,  -401,   118,  -401,   136,  -401,  -401,  -401,
    -401,  -401,  -401,    11,    11,    11,   150,   150,   150,   150,
     150,    76,    76,    76,    76,    21,   193,   191,   175,   321,
     207,  -401,  1105,  -401,   322,  -401,  1610,   184,   275,  1610,
    1610,   701,   313,   277,   319,   270,   802,   323,   283,  -401,
    -401,  -401,  -401,   802,   802,   701,   327,   328,   272,   701,
     329,   330,   274,   701,   331,   276,  -401,  -401,  1610,  -401,
    -401,  1610,  -401,  -401,  1610,   278,  1610,  1610,   280,   185,
     316,   701,   701,  -401,   701,   332,   300,    70,  -401,   348,
    -401,   317,   333,   701,   701,   335,   334,   701,   701,   336,
     337,   701,   339,  -401,  -401,  -401,   349,   188,   282,   802,
    1610,  -401,   338,   340,   701,   802,  -401,  1610,   352,    71,
    -401,    86,   148,  -401,  -401,   342,   343,   701,  -401,   344,
     345,   701,  -401,   346,   701,  -401,  1610,   802,  -401,   284,
    -401,  -401,   347,  -401,    15,   802,  -401,  -401,    88,  -401,
      95,  -401,  -401,  -401,   351,  -401,  -401,   353,  -401,   354,
     286,  -401,   802,  -401,   802,   802,  -401,   104,  -401,  -401,
    -401,  -401,   802,  -401,   802,  -401,  -401
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -401,  -401,  -401,  -401,  -401,    -1,  -401,  -401,  -401,   147,
    -401,  -401,  -401,   153,   355,  -401,   359,  -401,   -62,  -401,
    -401,    60,  -401,   182,    25,    98,     2,    23,   173,   171,
     176,   177,   169,  -401,  -401,    -2,  -401,    -3,    -7,  -401,
    -401,  -401,   -34,  -400,  -401,  -401,   -35,  -221,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -380,
    -340,    -4,  -401,  -401,  -401,  -401,   133,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -162,  -327,  -401,   397,  -110
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -48
static const yytype_int16 yytable[] =
{
     137,   125,   162,   226,   130,   185,   134,   170,   372,   270,
     147,   273,   376,   276,   204,   151,   380,   149,   171,   173,
     175,   430,   247,   318,   269,   445,   158,   214,   215,    15,
     272,   160,   224,   275,   142,   392,   444,   393,    21,   227,
     324,   337,   341,   332,   454,   205,   405,   406,   447,   234,
     409,   410,   228,   144,   413,   148,   152,   235,   258,   427,
     199,   121,   121,   121,   216,   217,   259,   422,   121,   121,
     121,   150,   172,   174,   176,   248,   121,   248,   186,   143,
     434,   187,    53,   248,   437,   188,   248,   439,   325,   189,
     427,   200,   254,   248,   248,   248,   190,   121,   145,   121,
     191,   224,   396,   426,   153,   192,   256,   427,   193,   338,
     194,   195,   342,   209,   229,   345,   210,   196,   429,   197,
     446,   211,   212,   236,   397,   397,   233,   448,   398,   398,
     186,   240,   156,   187,   164,   224,   455,   188,   237,   319,
     397,   189,   397,   349,   251,   246,   264,   213,   190,   397,
     253,   265,   191,   224,   137,   159,   257,   192,   397,   179,
     193,   350,   194,   195,   180,   266,   267,   222,   179,   196,
     181,   197,   168,   183,   223,   201,   161,   282,   284,   184,
     177,   286,   202,   122,   123,   124,   203,   169,   206,   264,
     139,   140,   141,   178,   268,   224,   287,   207,   146,   208,
     320,   264,   224,   218,   220,   224,   356,   390,   245,   317,
     416,   296,   297,   298,   299,   300,   346,   219,   221,   163,
     309,   167,   311,   224,   225,   329,   288,   289,   290,   291,
     292,   230,   313,   149,   224,   229,   315,   301,   302,   303,
     304,   322,   326,   327,   323,   224,   224,   333,   241,   334,
     224,   226,   224,   336,   340,   344,   323,   323,   323,   171,
     331,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   347,   121,   365,   348,   375,   323,   379,   323,
     382,   323,   386,   323,   389,   224,   417,   224,   442,   224,
     452,   224,   173,   224,   293,   294,   295,   175,   -46,   -47,
     353,   238,   243,   355,   242,   250,   358,   359,   252,   366,
     255,   271,   262,   274,   277,   278,   370,   371,   279,   283,
     285,   316,   321,   328,   259,   335,   248,   339,   179,   403,
     343,   362,   351,   354,   363,   357,   383,   364,   391,   384,
     369,   367,   385,   387,   388,   373,   374,   377,   378,   381,
     394,   395,   402,   407,   411,   404,   408,   414,   431,   412,
     420,   415,   421,   425,   432,   433,   435,   436,   438,   443,
     154,   312,   418,   449,   155,   450,   451,   419,   423,   314,
     306,   305,   310,   330,   424,   428,   307,   113,   308,     0,
       0,     1,     2,     3,     0,     0,     0,     0,     0,     0,
     441,     4,     0,   440,     0,     0,     0,     0,   137,     0,
       5,     0,     6,     0,     0,     0,     7,     0,     0,     0,
     131,     8,     9,    10,     0,   453,     0,   137,   240,     0,
       0,     0,     0,     0,     0,   456,     0,   240,     0,    11,
      12,    13,     0,     0,    14,    15,     0,    16,    17,     0,
      18,     0,    19,   116,    21,   132,    23,    24,     0,     0,
      25,    26,    27,     0,    28,     0,    29,    30,   133,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,   118,   119,   120,    46,    47,    48,    49,     0,    50,
      51,    52,     1,     2,     3,     0,     0,     0,    53,    54,
       0,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     6,     0,     0,     0,     7,     0,     0,
       0,   239,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,     0,     0,    14,    15,     0,    16,    17,
       0,    18,     0,    19,   116,    21,    22,    23,    24,     0,
       0,    25,    26,    27,     0,    28,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,   118,   119,   120,    46,    47,    48,    49,     0,
      50,    51,    52,     1,     2,     3,     0,     0,     0,    53,
      54,     0,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     6,     0,     0,     0,     7,     0,
       0,     0,   131,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,    13,     0,     0,    14,    15,     0,    16,
      17,     0,    18,     0,    19,   116,    21,    22,    23,    24,
       0,     0,    25,    26,    27,     0,    28,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,   118,   119,   120,    46,    47,    48,    49,
       0,    50,    51,    52,     1,     2,     3,     0,     0,     0,
      53,    54,     0,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     6,     0,     0,     0,     7,
       0,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,    13,     0,     0,    14,    15,     0,
      16,    17,     0,    18,     0,    19,    20,    21,    22,    23,
      24,     0,     0,    25,    26,    27,     0,    28,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,    47,    48,
      49,     0,    50,    51,    52,     1,     2,     3,     0,     0,
       0,    53,    54,     0,     0,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     6,     0,     0,     0,
       7,     0,     0,     0,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,    13,     0,     0,    14,    15,
       0,    16,    17,     0,    18,     0,    19,   116,    21,    22,
      23,    24,     0,     0,    25,    26,    27,     0,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,    42,   118,   119,   120,    46,    47,
      48,    49,     0,    50,    51,    52,     1,     2,     3,     0,
       0,     0,    53,    54,     0,     0,     4,     0,     0,     0,
     126,     0,     0,     0,     0,     0,     0,     6,   127,     0,
       0,   115,     0,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,     0,     0,     0,     0,
      15,     0,    16,     0,     0,    18,     0,     0,   116,    21,
     117,     0,     0,     0,     0,    25,    26,     0,     0,    28,
       0,     0,    30,    31,     0,    33,     0,    35,     0,    37,
       0,    39,     0,     0,     0,     0,   118,   119,   120,    46,
      47,    48,    49,     0,    50,    51,    52,     1,     2,     3,
       0,     0,     0,    53,    54,     0,     0,     4,     0,     0,
       0,   231,     0,     0,     0,     0,     0,     0,     6,   232,
       0,     0,   115,     0,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    12,     0,     0,     0,
       0,    15,     0,    16,     0,     0,    18,     0,     0,   116,
      21,   117,     0,     0,     0,     0,    25,    26,     0,     0,
      28,     0,     0,    30,    31,     0,    33,     0,    35,     0,
      37,     0,    39,     0,     0,     0,     0,   118,   119,   120,
      46,    47,    48,    49,     0,    50,    51,    52,     1,     2,
       3,     0,     0,     0,    53,    54,     0,     0,     4,     0,
       0,     0,   231,     0,     0,     0,     0,     0,     0,     6,
     352,     0,     0,   115,     0,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,    15,     0,    16,     0,     0,    18,     0,     0,
     116,    21,   117,     0,     0,     0,     0,    25,    26,     0,
       0,    28,     0,     0,    30,    31,     0,    33,     0,    35,
       0,    37,     0,    39,     0,     0,     0,     0,   118,   119,
     120,    46,    47,    48,    49,     0,    50,    51,    52,     1,
       2,     3,     0,     0,     0,    53,    54,     0,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     0,   157,     0,
       6,     0,     0,     0,   115,     0,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,     0,
       0,     0,     0,    15,     0,    16,     0,     0,    18,     0,
       0,   116,    21,   117,     0,     0,     0,     0,    25,    26,
       0,     0,    28,     0,     0,    30,    31,     0,    33,     0,
      35,     0,    37,     0,    39,     0,     0,     0,     0,   118,
     119,   120,    46,    47,    48,    49,     0,    50,    51,    52,
       1,     2,     3,     0,     0,     0,    53,    54,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,   115,     0,     0,     0,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,     0,     0,     0,    15,     0,    16,     0,     0,    18,
       0,     0,   116,    21,   117,     0,     0,     0,     0,    25,
      26,     0,     0,    28,     0,     0,    30,    31,     0,    33,
       0,    35,     0,    37,   244,    39,     0,     0,     0,     0,
     118,   119,   120,    46,    47,    48,    49,     0,    50,    51,
      52,     1,     2,     3,     0,     0,     0,    53,    54,     0,
       0,     4,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,     0,     0,   115,     0,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,     0,     0,     0,     0,    15,     0,    16,     0,     0,
      18,     0,     0,   116,    21,   117,     0,     0,     0,     0,
      25,    26,     0,     0,    28,     0,     0,    30,    31,     0,
      33,     0,    35,     0,    37,     0,    39,     0,     0,     0,
       0,   118,   119,   120,    46,    47,    48,    49,     0,    50,
      51,    52,     1,     2,     3,     0,     0,     0,    53,    54,
       0,     0,     4,     0,     0,     0,   126,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     0,   115,     0,     0,
       0,     0,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,     0,     0,     0,     0,    15,     0,    16,     0,
       0,    18,     0,     0,   116,    21,   117,     0,     0,     0,
       0,    25,    26,     0,     0,    28,     0,     0,    30,    31,
       0,    33,     0,    35,     0,    37,     0,    39,     0,     0,
       0,     0,   118,   119,   120,    46,    47,    48,    49,     0,
      50,    51,    52,     1,     2,     3,     0,     0,     0,    53,
      54,     0,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,   115,     0,
       0,     0,     0,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,     0,     0,     0,     0,    15,     0,    16,
       0,     0,    18,     0,     0,   116,    21,   117,     0,     0,
       4,     0,    25,    26,     0,     0,    28,     0,     0,    30,
      31,     6,    33,     0,    35,   115,    37,     0,    39,     0,
       0,     0,     0,   118,   119,   120,    46,    47,    48,    49,
       0,    50,    51,    52,     0,     0,     0,     0,    11,    12,
      53,    54,     0,     0,    15,     0,     0,     0,     0,    18,
       0,     0,   116,    21,   117,     0,     0,     0,     0,    25,
      26,     0,     0,    28,     0,     0,    30,    31,     0,    33,
       0,    35,     0,     0,     0,     0,     0,     0,     0,     0,
     118,   119,   120,    46,    47,    48,    49,     0,    50,    51,
      52,     0,     0,     0,     0,     0,     0,    53,    54
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-401)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       7,     4,    36,   113,     6,    67,     7,    42,   335,   171,
      17,   173,   339,   175,     3,    21,   343,    13,    13,    13,
      13,   401,    14,   244,    14,   425,    29,     6,     7,    57,
      14,    34,    17,    14,    22,   362,    21,   364,    66,    67,
      14,    14,    14,   264,   444,    34,   373,   374,   428,    17,
     377,   378,    80,    22,   381,    13,    67,    25,    55,   399,
       4,     1,     2,     3,    43,    44,    63,   394,     8,     9,
      10,    67,    67,    67,    67,    67,    16,    67,     9,    67,
     407,    12,   110,    67,   411,    16,    67,   414,   250,    20,
     430,    35,   154,    67,    67,    67,    27,    37,    67,    39,
      31,    17,    32,    32,    13,    36,    22,   447,    39,   271,
      41,    42,   274,    37,   115,   277,    40,    48,    32,    50,
      32,    45,    46,    17,    54,    54,   128,    32,    58,    58,
       9,   138,    67,    12,    67,    17,    32,    16,    32,    70,
      54,    20,    54,    25,   151,   148,    17,    71,    27,    54,
     153,    22,    31,    17,   161,    13,   159,    36,    54,    13,
      39,    25,    41,    42,    18,   168,   169,    23,    13,    48,
      24,    50,    13,    18,    30,     8,    28,   179,   181,    24,
     116,   184,    15,     1,     2,     3,    19,    13,    38,    17,
       8,     9,    10,   116,    22,    17,   198,    47,    16,    49,
      22,    17,    17,    10,    29,    17,    22,    22,   148,   244,
      22,   209,   210,   211,   212,   213,   278,    26,    11,    37,
     222,    39,   224,    17,     0,   259,   201,   202,   203,   204,
     205,    14,   234,    13,    17,   236,   238,   214,   215,   216,
     217,    14,    14,    14,    17,    17,    17,    14,    22,    14,
      17,   361,    17,    14,    14,    14,    17,    17,    17,    13,
     262,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    14,   223,    14,    17,    14,    17,    14,    17,
      14,    17,    14,    17,    14,    17,    14,    17,    14,    17,
      14,    17,    13,    17,   206,   207,   208,    13,    21,    21,
     312,    21,    89,   316,    22,    13,   319,   320,   116,   326,
     116,    13,    41,    13,    13,    67,   333,   334,    67,    67,
      67,    13,    28,    13,    63,    28,    67,    28,    13,    22,
      28,    28,    21,    21,    67,    70,   348,    28,    32,   351,
      67,    28,   354,   356,   357,    28,    28,    28,    28,    28,
      28,    61,    14,    28,    28,    32,    32,    28,   402,    32,
      32,    22,    32,    21,    32,    32,    32,    32,    32,    32,
      25,   234,   389,    32,    25,    32,    32,   390,   395,   236,
     219,   218,   223,   260,   397,   399,   220,     0,   221,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
     417,    13,    -1,   416,    -1,    -1,    -1,    -1,   425,    -1,
      22,    -1,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      32,    33,    34,    35,    -1,   442,    -1,   444,   445,    -1,
      -1,    -1,    -1,    -1,    -1,   452,    -1,   454,    -1,    51,
      52,    53,    -1,    -1,    56,    57,    -1,    59,    60,    -1,
      62,    -1,    64,    65,    66,    67,    68,    69,    -1,    -1,
      72,    73,    74,    -1,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,     3,     4,     5,    -1,    -1,    -1,   110,   111,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    24,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    56,    57,    -1,    59,    60,
      -1,    62,    -1,    64,    65,    66,    67,    68,    69,    -1,
      -1,    72,    73,    74,    -1,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,     3,     4,     5,    -1,    -1,    -1,   110,
     111,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    24,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    56,    57,    -1,    59,
      60,    -1,    62,    -1,    64,    65,    66,    67,    68,    69,
      -1,    -1,    72,    73,    74,    -1,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,     3,     4,     5,    -1,    -1,    -1,
     110,   111,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    24,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    56,    57,    -1,
      59,    60,    -1,    62,    -1,    64,    65,    66,    67,    68,
      69,    -1,    -1,    72,    73,    74,    -1,    76,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,     3,     4,     5,    -1,    -1,
      -1,   110,   111,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    24,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    -1,    56,    57,
      -1,    59,    60,    -1,    62,    -1,    64,    65,    66,    67,
      68,    69,    -1,    -1,    72,    73,    74,    -1,    76,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,     3,     4,     5,    -1,
      -1,    -1,   110,   111,    -1,    -1,    13,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      57,    -1,    59,    -1,    -1,    62,    -1,    -1,    65,    66,
      67,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,
      -1,    -1,    79,    80,    -1,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,     3,     4,     5,
      -1,    -1,    -1,   110,   111,    -1,    -1,    13,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    57,    -1,    59,    -1,    -1,    62,    -1,    -1,    65,
      66,    67,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,
      76,    -1,    -1,    79,    80,    -1,    82,    -1,    84,    -1,
      86,    -1,    88,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,     3,     4,
       5,    -1,    -1,    -1,   110,   111,    -1,    -1,    13,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    57,    -1,    59,    -1,    -1,    62,    -1,    -1,
      65,    66,    67,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,    84,
      -1,    86,    -1,    88,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,     3,
       4,     5,    -1,    -1,    -1,   110,   111,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    62,    -1,
      -1,    65,    66,    67,    -1,    -1,    -1,    -1,    72,    73,
      -1,    -1,    76,    -1,    -1,    79,    80,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
       3,     4,     5,    -1,    -1,    -1,   110,   111,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    62,
      -1,    -1,    65,    66,    67,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,    -1,    -1,    79,    80,    -1,    82,
      -1,    84,    -1,    86,    87,    88,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,     3,     4,     5,    -1,    -1,    -1,   110,   111,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,    -1,
      62,    -1,    -1,    65,    66,    67,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    76,    -1,    -1,    79,    80,    -1,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,     3,     4,     5,    -1,    -1,    -1,   110,   111,
      -1,    -1,    13,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,
      -1,    62,    -1,    -1,    65,    66,    67,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    79,    80,
      -1,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,     3,     4,     5,    -1,    -1,    -1,   110,
     111,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    57,    -1,    59,
      -1,    -1,    62,    -1,    -1,    65,    66,    67,    -1,    -1,
      13,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,    79,
      80,    24,    82,    -1,    84,    28,    86,    -1,    88,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,    -1,    -1,    51,    52,
     110,   111,    -1,    -1,    57,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    65,    66,    67,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,    -1,    -1,    79,    80,    -1,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    13,    22,    24,    28,    33,    34,
      35,    51,    52,    53,    56,    57,    59,    60,    62,    64,
      65,    66,    67,    68,    69,    72,    73,    74,    76,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    92,    93,    94,    95,    96,    97,    98,    99,
     101,   102,   103,   110,   111,   118,   119,   120,   121,   122,
     123,   124,   125,   128,   131,   132,   133,   134,   136,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   154,   155,   156,   157,   158,   159,
     161,   162,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   179,   180,   181,   184,   185,   186,   187,   188,   189,
     190,   191,   194,   195,   196,    28,    65,    67,    93,    94,
      95,   138,   140,   140,   140,   154,    17,    25,   126,   127,
     152,    32,    67,    80,   122,   129,   130,   155,   160,   140,
     140,   140,    22,    67,    22,    67,   140,   155,    13,    13,
      67,    21,    67,    13,   131,   133,    67,    22,   154,    13,
     154,    28,   159,   140,    67,   163,   164,   140,    13,    13,
     163,    13,    67,    13,    67,    13,    67,   116,   116,    13,
      18,    24,   135,    18,    24,   135,     9,    12,    16,    20,
      27,    31,    36,    39,    41,    42,    48,    50,   153,     4,
      35,     8,    15,    19,     3,    34,    38,    47,    49,    37,
      40,    45,    46,    71,     6,     7,    43,    44,    10,    26,
      29,    11,    23,    30,    17,     0,   196,    67,    80,   122,
      14,    17,    25,   152,    17,    25,    17,    32,    21,    32,
     155,    22,    22,    89,    87,   138,   154,    14,    67,   192,
      13,   155,   116,   154,   135,   116,    22,   154,    55,    63,
     182,   183,    41,   165,    17,    22,   154,   154,    22,    14,
     192,    13,    14,   192,    13,    14,   192,    13,    67,    67,
      14,   137,   152,    67,   154,    67,   154,   152,   141,   141,
     141,   141,   141,   142,   142,   142,   143,   143,   143,   143,
     143,   144,   144,   144,   144,   145,   146,   147,   148,   152,
     149,   152,   126,   152,   130,   152,    13,   163,   164,    70,
      22,    28,    14,    17,    14,   192,    14,    14,    13,   159,
     183,   152,   164,    14,    14,    28,    14,    14,   192,    28,
      14,    14,   192,    28,    14,   192,   135,    14,    17,    25,
      25,    21,    25,   152,    21,   154,    22,    70,   154,   154,
     193,   195,    28,    67,    28,    14,   155,    28,   175,    67,
     155,   155,   193,    28,    28,    14,   193,    28,    28,    14,
     193,    28,    14,   152,   152,   152,    14,   154,   154,    14,
      22,    32,   193,   193,    28,    61,    32,    54,    58,   176,
     177,   178,    14,    22,    32,   193,   193,    28,    32,   193,
     193,    28,    32,   193,    28,    22,    22,    14,   155,   154,
      32,    32,   193,   155,   154,    21,    32,   177,   178,    32,
     176,   159,    32,    32,   193,    32,    32,   193,    32,   193,
     154,   155,    14,    32,    21,   160,    32,   176,    32,    32,
      32,    32,    14,   155,   160,    32,   155
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
/* Line 1787 of yacc.c  */
#line 2196 "brew.parser.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


