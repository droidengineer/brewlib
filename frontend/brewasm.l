/**
*  brewasm.l - lexical specification of the Brew assembler
*/

%{
#include <stdlib.h>
#include "brew_asm.lexer.h"
void yyerror(char *);
int offset;

#define SAVE_TOKEN yylval.str = new std::string(yytext,yyleng)
#define TOKEN(t)	(yylval.token = t)
#define YY_INPUT(buf,result,max_size) { \
	result = GetNextChar(buf,max_size); \
	if (result <= 0) \
		result = YY_NULL; \
	}

%}

digit [0-9]
nonzero_digit [1-9]
bin [0-1]
hex [0-9a-fA-F]
alpha [A-Za-z_]

%x comment

%%

"add"			return ADD;
"and"			return AND;
"break"			return BREAK;
"breq"			return BREQ;
"brgt"			return BRGT;
"brlt"			return BRLT;
"brne"			return BRNE;
"call"			return CALL;
"cbr"			return CBR;
"clr"			return CLR;
"cneg"			return CNEG;
"com"			return COM;
"cp"			return CP;
"czro"			return CZRO;
"dec"			return DEC;
"div"			return DIV;
"enter"			return ENTER;
"halt"			return HALT;
"icall"			return ICALL;
"in"			return IN;
"inc"			return INC;
"input"			return INPUT;
"inputr"		return INPUTR;
"jmp"			return JMP;
"lcd_mov"		return LCDMOV;
"ldi"			return LDI;
"leave"			return LEAVE;
"lsl"			return LSL;
"lsr"			return LSR;
"mdi"			return MDI;
"mdd"			return MDD;
"mode"			return MODE;
"mov"			return MOV;
"mul"			return MUL;
"neg"			return NEG;
"nop"			return NOP;
"or"			return OR;
"out"			return OUT;
"pop"			return POP;
"push"			return PUSH;
"rcall"			return RCALL;
"ret"			return RET;
"reti"			return RETI;
"rjmp"			return RJMP;
"rol"			return ROL;
"ror"			return ROR;
"sbr"			return SBR;
"sbrc"			return SBRC;
"sbrs"			return SBRS;
"sleep"			return SLEEP;
"sneg"			return SNEG;
"sub"			return SUB;
"szro"			return SZRO;
"xor"			return XOR;

"r0"			return R0;
"r1"			return R1;
"r2"			return R2;
"r3"			return R3;
"r4"			return R4;
"r5"			return R5;
"r6"			return R6;
"r7"			return R7;
"r8"			return R8;
"r9"			return R9;
"r10"			return R10;
"r11"			return R11;
"r12"			return R12;
"r13"			return R13;
"r14"			return R14;
"r15"			return R15;
"r16"			return R16;
"r17"			return R17;
"r18"			return R18;
"r19"			return R19;
"r20"			return R20;
"r21"			return R21;
"r22"			return R22;
"r23"			return R23;
"r24"			return R24;
"r25"			return R25;
"r26"			return R26;
"r27"			return R27;
"r28"			return R28;
"r29"			return R29;
"r30"			return R30;
"r31"			return R31;
"x"			return X;
"xl"			return XL;
"xh"			return XH;
"y"			return Y;
"yl"			return YL;
"yh"			return YH;
"z"			return Z;
"zl"			return ZL;
"zh"			return ZH;
"ir"			return IR;
"sp"			return SP;

".alias"		return ALIAS;
".alloc"		return ALLOC;
".ascii"		return ASCII;
".byte"			return BYTE;
".cache"		return CACHE;
".const"		return CONST;
".debug"		return DEBUG;
".def"			return DEF;
".device"		return DEVICE;
".echo"			return ECHO;
".eemem"		return EEMEM;
".endo"			return ENDO;
".equ"			return EQU;
".exec"			return EXEC;
".extmem"		return EXTMEM;
".immutable"	return IMMUTABLE;
".include"		return INCLUDE;
".list"			return LIST;
".nand"			return NAND;
".native"		return NATIVE;
".nolist"		return NOLIST;
".nor"			return NOR;
".object"		return OBJECT;
".org"			return ORG;
".progmem"		return PROGMEM;
".set"			return SET;
".sram"			return SRAM;
".global"		return GLOBAL;


{alpha}({alpha}|{digit})*	{
								yylval.str = strdup(yytext);
								return LABEL;
							}
'(''|[^'])((''|[^']))+'		{
								yylval.str = strdup(yytext);
								return STRINGLITERAL;
							}
'(''|[^'])'					{
								yylval.ival = (char)(*(yytext+1));
								return CHARLITERAL;
							}
0b{bin}{bin}{bin}{bin}{bin}{bin}{bin}{bin}	{
								yylval.ival = (int)strtol(yytext+2,NULL,2);
								return BININTEGERLITERAL;
}
0b{bin}{bin}{bin}{bin}{bin}{bin}{bin}{bin}{bin}{bin}{bin}{bin}{bin}{bin}{bin}{bin}	{
								yylval.ival = (int)strtol(yytext+2,NULL,2);
								return BIN16;
}
0x{hex}{hex}				{
								yylval.ival = (int)strtol(yytext,NULL,16);
								return HEXINTEGERLITERAL;
}
0x{hex}({hex})*				{
								yylval.ival = (int)strtol(yytext,NULL,16);
								return HEX16;
}
[+-/*,():] { return *yytext; }		  */
\n { ++yylineno; }
";"|"#"							BEGIN(comment);
<comment>[^\n]*					;
<comment>\n					{
								++yylineno;
								BEGIN(INITIAL);
							}
<comment><<EOF>>			{
								BEGIN(INITIAL);
								yyterminate();
							}
[ \t\r]+						;
.							{ yyerror("Invalid character"); }

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