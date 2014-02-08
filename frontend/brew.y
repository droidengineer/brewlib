/*

*/
%{
#include "symtab.hpp"
#include "codestream.hpp"

extern ByteCodeStream * codestream;
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

%}

%union
{
	int token;
	int ival;
	float fval;
	char * carray;
	ASTNode * node;
	BrewStatement * stmt;
	BrewExpression * expr;
	BrewIdentifier * ident;
	BrewVariableDecl * varDecl;
	std::vector<BrewVariableDecl*> * varList;
	std::vector<BrewExpression *> * exprList;
	std::string * string;
}

%type <ival> Expression

%token MINUS
%token MINUSMINUS
%token EXCLAM
%token EXCLAMEQ
%token EXCLAMEQEQ
%token PERCENT
%token PERCENTEQ
%token AMP
%token AMPAMP
%token AMPEQ
%token LPAREN
%token RPAREN
%token TIMES
%token TIMESEQ
%token COMMA
%token DOT
%token DIV
%token DIVEQ
%token COLON
%token SEMI
%token QUESTION
%token LBRACKET
%token RBRACKET
%token CARET
%token CARETEQ
%token LBRACE
%token PIPE
%token PIPEPIPE
%token PIPEEQ
%token RBRACE
%token TILDE
%token PLUS
%token PLUSPLUS
%token PLUSEQ
%token LT
%token LTLT
%token LTLTEQ
%token LTEQ
%token EQ
%token MINUSEQ
%token EQEQ
%token EQEQEQ
%token GT
%token GTEQ
%token GTGT
%token GTGTEQ
%token GTGTGT
%token GTGTGTEQ
%token ARRAY
%token <ival> BOOLEAN
%token BREAK
%token CASE
%token CATCH
%token CONTINUE
%token <ival> DECIMALLITERAL
%token DEFAULT
%token DELETE
%token DO
%token ELSE
%token FALSE
%token FINALLY
%token FOR
%token FUNCTION
%token <ival> HEXINTEGERLITERAL
%token <string> IDENTIFIER
%token IMPORT
%token IF
%token IN
%token INSTANCEOF
%token NEW
%token NULL
%token PACKAGE
%token PROVIDES
%token REGEXP
%token REQUIRES
%token RETURN
%token <str> STRING
%token <str> STRINGLITERAL
%token SWITCH
%token THIS
%token THROW
%token TRUE
%token TRY
%token TYPEOF
%token VAR
%token VOID
%token WHILE
%token WITH


%token PRIVATE	/* -gian */
%token AUTO
%token INTERFACE
%token COMPONENT
%token ENTITY
%token OBJECT
%token MATH
%token PROTOTYPE
%token SYSTEM
%token SYS
%token UNDEFINED
%token JSON
%token ERROR
%token ALIAS
%token IMMUTABLE
%token IMPLEMENTS
%token ENUM
%token EXPORT
%token EXTENDS
/* %token UNDEFINED */
%token UNDEFINED
%token <ival> BININTEGERLITERAL
%token DATE
%token DOLLAR
%token DOLLARDOLLAR
%token BLUEPRINT
%token COLONCOLON
%token ASM
%token <ival> VALUE



%start program

%%

literal : null_literal 
        | boolean_literal 
        | numeric_literal 
        | STRINGLITERAL
        | undefined_literal
        ;

null_literal : NULL 
             ;

undefined_literal : UNDEFINED
			;

boolean_literal : TRUE 
                | FALSE 
                ;

numeric_literal : DECIMALLITERAL 
                | HEXINTEGERLITERAL 
                | BININTEGERLITERAL
				| INTEGERLITERAL
                ;

regular_expression_literal : REGEXP 
                           ;

primary_expression : THIS 
					| PROTOTYPE
                   | IDENTIFIER 
                   | OBJECT
                   | FUNCTION
                   | ARRAY
                   | STRING
                   | BOOLEAN
                   | DATE
                   | REGEXP
                   | JSON
                   | ERROR
                   | literal 
                   | array_literal 
                   | object_literal 
                   | LPAREN expression RPAREN 
                   | regular_expression_literal 
                   ;

array_literal : LBRACKET RBRACKET 
              | LBRACKET elision RBRACKET 
              | LBRACKET element_list RBRACKET 
              | LBRACKET element_list COMMA elision RBRACKET 
              ;

elision : COMMA 
        | elision COMMA 
        ;

element_list : elision assignment_expression 
             | element_list COMMA elision assignment_expression 
             | element_list COMMA assignment_expression 
             | assignment_expression 
             ;

object_literal : LBRACE property_name_and_value_list RBRACE 
               ;

property_name_and_value_list : property_name COLON assignment_expression 
                             | property_name_and_value_list COMMA property_name COLON assignment_expression 
                             ;

property_name : IDENTIFIER 
              | STRINGLITERAL 
              | numeric_literal 
              ;

member_expression : primary_expression 
                  | function_expression 
                  | object_expression
                  | interface_expression
                  | component_expression
                  | entity_expression
                  | builtin_expression
                  | member_expression LBRACKET expression RBRACKET 
                  | member_expression DOT IDENTIFIER 
                  | NEW member_expression arguments 
                  ;

object_expression : member_expression
				;

new_expression : member_expression 
               | NEW new_expression 
               ;

call_expression : member_expression arguments 
                | call_expression arguments 
                | call_expression LBRACKET expression RBRACKET 
                | call_expression DOT IDENTIFIER 
                ;

arguments : LPAREN RPAREN 
          | LPAREN argument_list RPAREN 
          ;

builtin_expression : MATH '.' IDENTIFIER
				| MATH '.' IDENTIFIER arguments
				| SYSTEM '.' IDENTIFIER
				;

argument_list : assignment_expression 
              | argument_list COMMA assignment_expression 
              ;

left_hand_side_expression : new_expression 
                          | call_expression 
                          ;

postfix_expression : left_hand_side_expression 
                   | postfix_expression PLUSPLUS 
                   | postfix_expression MINUSMINUS 
                   ;

unary_expression : postfix_expression 
                 | DELETE unary_expression 
                 | VOID unary_expression 
                 | TYPEOF unary_expression 
                 | PLUSPLUS unary_expression 
                 | MINUSMINUS unary_expression 
                 | PLUS unary_expression 
                 | MINUS unary_expression 
                 | TILDE unary_expression 
                 | EXCLAM unary_expression 
                 ;

multiplicative_expression : unary_expression 
                          | unary_expression TIMES multiplicative_expression 
							{
								$$ = reduceTimes($1,$3,&@3);
							}
                          | unary_expression DIV multiplicative_expression
							{
								$$ = reduceDiv($1,$3,&@3);
							}
                          | unary_expression PERCENT multiplicative_expression
							{
								$$ = reduceModulo($1,$3,&@3);
							}
                          ;

additive_expression : additive_expression PLUS multiplicative_expression 
                    | additive_expression MINUS multiplicative_expression 
                    | multiplicative_expression 
                    ;

shift_expression : shift_expression LTLT additive_expression 
                 | shift_expression GTGT additive_expression 
                 | shift_expression GTGTGT additive_expression 
                 | additive_expression 
                 ;

relational_expression : shift_expression 
                      | relational_expression LT shift_expression 
                      | relational_expression GT shift_expression 
                      | relational_expression LTEQ shift_expression 
                      | relational_expression GTEQ shift_expression 
                      | relational_expression INSTANCEOF shift_expression 
                      ;

equality_expression : relational_expression 
                    | equality_expression EQEQ relational_expression 
                    | equality_expression EXCLAMEQ relational_expression 
                    | equality_expression EQEQEQ relational_expression 
                    | equality_expression EXCLAMEQEQ relational_expression 
                    ;

bitwise_and_expression : equality_expression 
                       | bitwise_and_expression AMP equality_expression 
                       ;

bitwise_xor_expression : bitwise_and_expression 
                       | bitwise_xor_expression CARET bitwise_and_expression 
                       ;

bitwise_or_expression : bitwise_xor_expression 
                      | bitwise_or_expression PIPE bitwise_xor_expression 
                      ;

logical_and_expression : bitwise_or_expression 
                       | logical_and_expression AMPAMP bitwise_or_expression 
                       ;

logical_or_expression : logical_and_expression 
                      | logical_or_expression PIPEPIPE logical_and_expression 
                      ;

conditional_expression : logical_or_expression 
                       | logical_or_expression QUESTION assignment_expression COLON assignment_expression 
                       ;

assignment_expression : conditional_expression 
                      | left_hand_side_expression assignment_operator assignment_expression 
                      ;

assignment_operator : EQ 
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

expression : assignment_expression 
           | expression COMMA assignment_expression 
           ;

statement : block 
          | variable_statement 
          | auto_statement
          | empty_statement 
          | if_statement 
          | if_else_statement 
          | iteration_statement 
          | continue_statement 
          | break_statement 
          | return_statement 
          | with_statement 
          | labelled_statement 
          | switch_statement 
          | throw_statement 
          | try_statement 
          | expression
          | directives
          ;

directives : package_statement
			| import_statement
			;

package_statement : PACKAGE IDENTIFIER
		;

import_statement : IMPORT IDENTIFIER
		| IMPORT IDENTIFIER '.*'
		;

block : LBRACE RBRACE 
      | LBRACE statement_list RBRACE 
      ;

statement_list : statement 
               | statement_list statement 
               ;

variable_statement : VAR variable_declaration_list SEMI 
                   ;

auto_statement : AUTO variable_declaration_list SEMI
	       ;

variable_declaration_list : variable_declaration 
                          | variable_declaration_list COMMA variable_declaration 
                          ;

variable_declaration : IDENTIFIER 
                     | IDENTIFIER initializer 
                     ;

initializer : EQ assignment_expression 
            ;

empty_statement : SEMI 
                ;

if_statement : IF LPAREN expression RPAREN statement 
             ;

if_else_statement : IF LPAREN expression RPAREN statement ELSE statement 
                  ;

iteration_statement : DO statement WHILE LPAREN expression RPAREN SEMI 
                    | WHILE LPAREN expression RPAREN statement 
                    | FOR LPAREN expression SEMI expression SEMI expression RPAREN statement 
                    | FOR LPAREN VAR variable_declaration_list SEMI expression SEMI expression RPAREN statement 
                    | FOR LPAREN left_hand_side_expression IN expression RPAREN statement 
                    | FOR LPAREN VAR variable_declaration IN expression RPAREN statement 
                    ;

continue_statement : CONTINUE SEMI 
                   | CONTINUE IDENTIFIER SEMI 
                   ;

break_statement : BREAK SEMI 
                | BREAK IDENTIFIER SEMI 
                ;

return_statement : RETURN SEMI 
                 | RETURN expression SEMI 
                 ;

with_statement : WITH LPAREN expression RPAREN statement SEMI 
               ;

switch_statement : SWITCH LPAREN expression RPAREN case_block 
                 ;

case_block : LBRACE RBRACE 
           | LBRACE case_clauses RBRACE 
           | LBRACE case_clauses default_clause RBRACE 
           | LBRACE case_clauses default_clause case_clauses RBRACE 
           | LBRACE default_clause case_clauses RBRACE 
           | LBRACE default_clause RBRACE 
           ;

case_clauses : case_clause 
             | case_clauses case_clause 
             ;

case_clause : CASE expression COLON statement_list 
            | CASE expression COLON 
            ;

default_clause : DEFAULT COLON 
               | DEFAULT COLON statement_list 
               ;

labelled_statement : IDENTIFIER COLON statement 
                   ;

throw_statement : THROW expression 
                ;

try_statement : TRY block catch 
              | TRY block finally 
              | TRY block catch finally 
              ;

catch : CATCH LPAREN IDENTIFIER RPAREN block 
      ;

finally : FINALLY block 
        ;

function_declaration : FUNCTION IDENTIFIER LPAREN formal_parameter_list RPAREN LBRACE function_body RBRACE 
                     | FUNCTION IDENTIFIER LPAREN RPAREN LBRACE function_body RBRACE 
                     ;

function_expression : FUNCTION LPAREN RPAREN LBRACE function_body RBRACE 
                    | FUNCTION LPAREN formal_parameter_list RPAREN LBRACE function_body RBRACE 
                    ;

interface_declaration : INTERFACE IDENTIFIER LPAREN formal_parameter_list RPAREN LBRACE function_body RBRACE
		      | INTERFACE IDENTIFIER LPAREN RPAREN LBRACE function_body RBRACE
			;
interface_expression : INTERFACE LPAREN RPAREN LBRACE function_body RBRACE 
				| INTERFACE LPAREN formal_parameter_list RPAREN LBRACE function_body RBRACE 
				;

component_declaration : COMPONENT IDENTIFIER LPAREN formal_parameter_list RPAREN LBRACE function_body RBRACE
		      | COMPONENT IDENTIFIER LPAREN RPAREN LBRACE function_body RBRACE
			;

component_expression : COMPONENT LPAREN RPAREN LBRACE function_body RBRACE 
			| COMPONENT LPAREN formal_parameter_list RPAREN LBRACE function_body RBRACE 
			;

entity_declaration : ENTITY IDENTIFIER LPAREN formal_parameter_list RPAREN LBRACE function_body RBRACE
		      | COMPONENT IDENTIFIER LPAREN RPAREN LBRACE function_body RBRACE
			;

entity_expression : ENTITY LPAREN RPAREN LBRACE function_body RBRACE 
				| ENTITY LPAREN formal_parameter_list RPAREN LBRACE function_body RBRACE 
				;

formal_parameter_list : IDENTIFIER 
                      | formal_parameter_list COMMA IDENTIFIER 
                      ;

function_body : source_elements 
              | 
              ;

program : source_elements 
        ;

source_elements : source_element 
                | source_elements source_element 
                ;

source_element : statement 
               | function_declaration 
               | interface_declaration
               | component_declaration
               | entity_declaration
               ;

 %%

void yyerror (char * s)
 {
	 fprintf(stdout, "line %d: %s\n", lineno, s);
 }