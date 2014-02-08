%{
#include "brew.parser.h"

#define SAVE_TOKEN yylval.str = new std::string(yytext,yyleng)
#define TOKEN(t)	(yylval.token = t)
#define YY_INPUT(buf,result,max_size) { \
	result = GetNextChar(buf,max_size); \
	if (result <= 0) \
		result = YY_NULL; \
	}
int lineno = 1;
void	comment();
void	count();
extern "C" int yywrap() { }
%}

%x comment

%%

"-"		{ return MINUS; }
"--"		{ return MINUSMINUS; }
"!"		{ return EXCLAM; }
"!="	{ return EXCLAMEQ; }
"!=="		{ return EXCLAMEQEQ; }
"%"		{ return PERCENT; }
"%="		{ return PERCENTEQ; }
"&"		{ return AMP; }
"&&"		{ return AMPAMP; }
"&="		{ return AMPEQ; }
"("		{ return LPAREN; }
")"		{ return RPAREN; }
"*"		{ return TIMES; }
"*="		{ return TIMESEQ; }
","		{ return COMMA; }
"$"		{ return DOLLAR; }
"$$"	{ return DOLLARDOLLAR; }
"."		{ return DOT; }
"/"		{ return DIV; }
"/="		{ return DIVEQ; }
":"		{ return COLON; }
"::"	{ return COLONCOLON; }
";"		{ return SEMI; }
"?"		{ return QUESTION; }
"["		{ return LBRACKET; }
"]"		{ return RBRACKET; }
"^"		{ return CARET; }
"^="		{ return CARETEQ; }
"{"		{ return LBRACE; }
"|"		{ return PIPE; }
"||"		{ return PIPEPIPE; }
"|="		{ return PIPEEQ; }
"}"		{ return RBRACE; }
"~"		{ return TILDE; }
"+"		{ return PLUS; }
"++"		{ return PLUSPLUS; }
"+="		{ return PLUSEQ; }
"<"		{ return LT; }
"<<"		{ return LTLT; }
"<<="		{ return LTLTEQ; }
"<="		{ return LTEQ; }
"="		{ return EQ; }
"-="		{ return MINUSEQ; }
"=="		{ return EQEQ; }
"==="		{ return EQEQEQ; }
">"		{ return GT; }
">="		{ return GTEQ; }
">>"		{ return GTGT; }
">>="		{ return GTGTEQ; }
">>>"		{ return GTGTGT; }
">>>="		{ return GTGTGTEQ; }
ALIAS		{ return ALIAS; }
ARRAY		{ return ARRAY; }
ASM			{ return ASM; }
AUTO		{ return AUTO; }
BLUEPRINT	{ return BLUEPRINT; }
BOOL		{ return BOOLEAN; }
BOOLEAN		{ return BOOLEAN; }
BREAK		{ return BREAK; }
CASE		{ return CASE; }
CATCH		{ return CATCH; }
COMPONENT	{ return COMPONENT; }
CONTINUE		{ return CONTINUE; }
DATE		{ return DATE; }
DEFAULT		{ return DEFAULT; }
DELETE		{ return DELETE; }
DO		{ return DO; }
ELSE		{ return ELSE; }
ENTITY		{ return ENTITY; }
ENUM		{ return ENUM; }
ERROR		{ return ERROR; }
EXPORT		{ return EXPORT; }
EXTENDS		{ return EXTENDS; }
FALSE		{ return FALSE; }
FINALLY		{ return FINALLY; }
FOR		{ return FOR; }
FUNCTION		{ return FUNCTION; }
IF		{ return IF; }
IMMUTABLE		{ return IMMUTABLE; }
IMPLEMENTS		{ return IMPLEMENTS; }
IMPORT		{ return IMPORT; }
IN		{ return IN; }
INSTANCEOF		{ return INSTANCEOF; }
INTERFACE		{ return INTERFACE; }
JSON			{ return JSON; }
MATH		{ return MATH; }
NEW		{ return NEW; }
OBJECT	{ return OBJECT; }
NULL		{ return NULL; }
PACKAGE		{ return PACKAGE; }
PRIVATE		{ return PRIVATE; }
PROTOTYPE	{ return PROTOTYPE; }
PROVIDES	{ return PROVIDES; }
RETURN		{ return RETURN; }
REQUIRES	{ return REQUIRES; }
STRING		{ return STRING; }
SWITCH		{ return SWITCH; }
SYS			{ return SYSTEM; }
SYSTEM		{ return SYSTEM; }
THIS		{ return THIS; }
THROW		{ return THROW; }
TRUE		{ return TRUE; }
TRY			{ return TRY; }
TYPEOF		{ return TYPEOF; }
UNDEFINED	{ return UNDEFINED; }
VAR			{ return VAR; }
VOID		{ return VOID; }
WHILE		{ return WHILE; }
WITH		{ return WITH; }

[A-Za-z_][A-Za-z0-9_]*	{ yylval.string = strdup(yytext); return IDENTIFIER; }
0[xX][0-9A-Fa-f]+		{ return HEXINTEGERLITERAL; }
0[bB][0-1]+				{ return BININTEGERLITERAL; }
[0-9]+ 		{ yylval.ival = atoi(yytext); return INTEGERLITERAL; }
[0-9]+ "." [0-9]* | "." [0-9]*	{ yylval.fval = atof(yytext); return DECIMALLITERAL; }
[0-9]+[eE]["+""-"]?[0-9]* { yylval.fval = atof(yytext); return DECIMALLITERAL; }
[0-9]+"."[0-9]*[eE]["+""-"]?[0-9]* { yylval.fval = atof(yytext); return DECIMALLITERAL; }

[A-Za-z_]?\"(\\.|[^\\"])*\"	{ return STRINGLITERAL; }
\'(\\.)\'				{ return CHARLITERAL; }

"/(.*)*/"		{ return REGEXP; }

\n		lineno++;
[ \t\r]+	{count();}
"//".*	{;}
"/*"	{BEGIN(comment);}

.	{ }

%%

int yywrap() { return 1; }

void comment()
{
	char c, c1;
loop:
	while((c = input()) != '*' && c != 0)
		putchar(c);
	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}
	if (c != 0)
		putchar(c1);
}

int col = 0;
void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			col = 0;
		else if (yytext[i] == '\t')
			col += TABW - (col % TABW);
		else
			col++;

	ECHO;
}
