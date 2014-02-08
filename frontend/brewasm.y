/* assembly-level brew asm grammar */
%{
#include "symtab.hpp"
#include "codestream.hpp"

extern int yylineno;
enum seg { text, data };
enum fmt { hex, bin };

extern ByteCodeStream * bytestream;

//typedef struct symtab {
//	char * symbol;
//	uint16_t value;
//	symtab * next;
//} symtab_t;

//symtab_t * symtab_head, * symtab_curr;

int pass;

%}

%union
{
	int ival;
	double fval;
	char * str;
	void * voidptr;
}

%type <ival> expression

%token MINUS MINUSMINUS EXCLAM EXCLAMEQ EXCLAMEQEQ PERCENT PERCENTEQ
%token AMP AMPAMP AMPEQ LPAREN RPAREN TIMES TIMESEQ COMMA DOT
%token DIV DIVEQ COLON SEMI QUESTION LBRACKET RBRACKET CARET
%token CARETEQ LBRACE PIPE PIPEPIPE PIPEEQ RBRACE TILDE PLUS
%token PLUSPLUS PLUSEQ LT LTLT LTLTEQ LTEQ EQ MINUSEQ EQEQ 
%token EQEQEQ GT GTEQ GTGT GTGTEQ GTGTGT GTGTGTEQ
%token <ival> DECIMALLITERAL 
%token <ival> BININTEGERLITERAL
%token FUNCTION IDENTIFIER 
%token <ival> HEXINTEGERLITERAL
%token <ival> CHARLITERAL
%token <fval> REALLITERAL
%token <voidptr> ADDRLITERAL
%token NULL TRUE FALSE UNDEFINED
%token <str> STRINGLITERAL
%token <str> LABEL
%token SEI CLI SBR CBR ADC SUBI CLR SER CP COM
%token ADD SUB MUL INC DEC NEG AND ANDI OR ORI XOR NOT
%token LSL LSR ROL ROR ASR SBI CBI DEVICE DEF EXTMEM
%token EEMEM PROGMEM SRAM INCLUDE ORG LIST NOLIST EQU DB BYTE SET
%token ALIAS ALLOC ASCII CACHE CONST DEBUG DEF ECHO ENDO
%token EXEC IMMUTABLE NAND NATIVE NOR OBJECT GLOBAL
%token RJMP JMP CALL RCALL RET RETI NOP BREAK SLEEP
%token MOV MOVL PUSH POP LDI LD ST LPM IN OUT
%token BREQ BRNE BRLT BRGT SBRS SBRC
%token MDI MDD SNEG CNEG SZRO CZRO HALT MODE
%token INPUT INPUTR LCDMOV ICALL ENTER LEAVE
%token R0 R1 R2 R3 R4 R5 R6 R7 R8 R9 R10 R11 R12 R13 R14 R15 R16 R17
%token R18 R19 R20 R21 R22 R23 R24 R25 R26 R27 R28 R29 R30, R31
%token X XL XH Y YL YH Z ZL ZH SP IR

%left '+' '-'
%left '*'

%start program

%%

program : source_elements
	;

source_elements : DOT directives
	| statements
	;

directive_rhs:
	DECIMALLITERAL | HEXINTEGERLITERAL | BININTEGERLITERAL | IDENTIFIER
	;

directives : LIST | NOLIST | EEMEM | PROGMEM | SRAM
	| ORG HEXINTEGERLITERAL
	| INCLUDE STRINGLITERAL
	| EQU IDENTIFIER EQ directive_rhs
	| BYTE IDENTIFIER EQ directive_rhs
	| DEVICE STRINGLITERAL
	| DB IDENTIFIER EQ directive_rhs
	| DEF register EQ IDENTIFIER
	| EXIT
	;
	
register : R0|R1|R2|R3|R4|R5|R6|R7|R8|R9|R10|R11|R12|R13|R14|R15|R16|R17|R18|R19|R20
	| R21|R22|R23|R24|R25|R26|R27|R28|R29|R30|R31|SP|IR|X|XL|XH|Y|YL|YH|Z|ZL|ZH
	| register_alias
	;

register_alias : IDENTIFIER
					 ;
	
statements : statement
	| statement statements
	;
	
statement : label
	| operation
	;

label : IDENTIFIER COLON
	;
	
operation : zero_operand_ops
	| one_operand_ops
	| two_operand_ops
	;
	
zero_operand_ops : SEI | CLI | SLEEP | RET | RETI
	| NOP | BREAK
	;
	
one_operand_ops : NEG register
	| INC register
	| DEC register
	| CLR register
	| SER register
	| RJMP HEXINTEGERLITERAL | RJMP IDENTIFIER
	| JMP HEXINTEGERLITERAL | JMP IDENTIFIER
	| RCALL HEXINTEGERLITERAL | RCALL IDENTIFIER
	| CALL HEXINTEGERLITERAL | CALL IDENTIFIER
	| BREQ HEXINTEGERLITERAL | BREQ IDENTIFIER
	| BRNE HEXINTEGERLITERAL | BRNE IDENTIFIER
	| BRGT HEXINTEGERLITERAL | BRGT IDENTIFIER
	| BRLT HEXINTEGERLITERAL | BRLT IDENTIFIER
	| PUSH register
	| POP register
	;
	
two_operand_ops : LDI register COMMA expression
	| ADD register COMMA register
	| ADC register COMMA register
	| SUB register COMMA register
	| SUBI register COMMA register
	| AND register COMMA register
	| ANDI register COMMA register
	| OR register COMMA register
	| ORI register COMMA register
	| XOR register COMMA register
	| SBR register COMMA number
	| CBR register COMMA number
	| MUL register COMMA register
	| MOV register COMMA register
	| LDI register COMMA number | LDI register COMMA IDENTIFIER
	| LD register COMMA number
	| ST register COMMA register
	| IN register COMMA IDENTIFIER
	| OUT IDENTIFIER COMMA register
	;
	
assignment_operator :  EQ 
	| TIMESEQ 
	| DIVEQ 
	| PERCENTEQ 
	| PLUSEQ 
	| MINUSEQ 
	| LTLTEQ 
	| GTGTEQ 
	| GTGTGTEQ 
	| AMPEQ 
	| CARETEQ 
	| PIPEEQ 
	;
	

unary_expression : PLUS
	| PLUS unary_expression
	;

multiplicative_expression : unary_expression 
						| unary_expression TIMES multiplicative_expression  { $$ = $1 * $3; }
			            | unary_expression DIV multiplicative_expression 
						| unary_expression PERCENT multiplicative_expression { $$ = $1 % $3; }
                          ;

additive_expression : additive_expression PLUS multiplicative_expression  { $$ = $1 + $3; }
					| additive_expression MINUS multiplicative_expression  { $$ = $1 - $3; }
                    | multiplicative_expression 
                    ;

shift_expression : shift_expression LTLT additive_expression	{ $$ = $1 << $3; } 
					| shift_expression GTGT additive_expression	{ $$ = $1 >> $3; }
					| shift_expression GTGTGT additive_expression 
                 | additive_expression 
                 ;

relational_expression : shift_expression 
							| relational_expression LT shift_expression  { $$ = $1 < $3; }
						| relational_expression GT shift_expression	{ $$ = $1 > $3; }
						| relational_expression LTEQ shift_expression		{ $$ = $1 <= $3; }
						| relational_expression GTEQ shift_expression		{ $$ = $1 >= $3; }
                      | relational_expression INSTANCEOF shift_expression
                      ;

equality_expression : relational_expression 
						  | equality_expression EQEQ relational_expression	{ $$ = $1 == $3; }
					  | equality_expression EXCLAMEQ relational_expression	{ $$ = $1 != $3; }
					  | equality_expression EQEQEQ relational_expression	
                    | equality_expression EXCLAMEQEQ relational_expression 
                    ;

bitwise_and_expression : equality_expression 
		 | bitwise_and_expression AMP equality_expression  { $$ = $1 & $3; }
                       ;

bitwise_xor_expression : bitwise_and_expression 
				| bitwise_xor_expression CARET bitwise_and_expression  { $$ = $1 ^ $3; }
                       ;

bitwise_or_expression : bitwise_xor_expression 
		| bitwise_or_expression PIPE bitwise_xor_expression 	{ $$ = $1 | $3; }
        ;

logical_and_expression : bitwise_or_expression 
		 | logical_and_expression AMPAMP bitwise_or_expression { $$ = $1 && $3; }
         ;

logical_or_expression : logical_and_expression 
		| logical_or_expression PIPEPIPE logical_and_expression { $$ = $1 || $3; }
                      ;

conditional_expression : logical_or_expression 
                       | logical_or_expression QUESTION assignment_expression COLON assignment_expression 
                       ;

assignment_expression : conditional_expression 
                      | left_hand_side_expression assignment_operator assignment_expression 
	
expression : assignment_expression 
   | expression COMMA assignment_expression
   | LABEL { $$ = $1;  }
   | CHARLITERAL { $$ = $1; }
	| BININTEGERLITERAL { $$ = $1; }
	| HEXINTEGERLITERAL { $$ = $1; }
	| DECIMALINTEGERLITERAL { $$ = $1; }
	| LPAREN expression RPAREN { $$ = $2; }
   ;

%%
