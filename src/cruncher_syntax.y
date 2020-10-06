/* Parser for the      _
*  ___ ___ _ _ ___ ___| |_ ___ ___
* |  _|  _| | |   |  _|   | -_|  _|
* |___|_| |___|_|_|___|_|_|___|_|
*                              language.
* Authored by jadermcs, 01-10-2020.
* Details at: https://github.com/jadermcs/cruncher
*/
%output  "src/cruncher_syntax.tab.c"
%defines "include/cruncher_syntax.tab.h"
%{
#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"
extern int yylineno;
extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%token SYMBOL IDENTIFIER
%token INTCONST FLOATCONST CHARCONST STRINGCONST PATHCONST
%token WHILE_KW FOR_KW IN_KW IF_KW ELSE_KW CRUNCH_KW RETURN_KW
%token CHAR_TYPE INT_TYPE FLOAT_TYPE STRING_TYPE PATH_TYPE VOID_TYPE
%token ADD_OP SUB_OP MULT_OP DIV_OP REM_OP
%token NOT_OP LESSTHAN_OP LESSEQUAL_OP GREATERTHAN_OP GREATEREQUAl_OP
%token NOTEQUAL_OP COMPARISON_OP OR_OP AND_OP
%token LBRACE RBRACE LBRACKET RBRACKET LPARENTHESES RPARENTHESES
%token COLON SEMICOLON DEF_EQ COMMA PIPE

%%

calclist:
        | calclist exp PIPE {printf("= %d\n", $1);}

exp: factor
   | exp ADD_OP factor {$$ = $1 + $3;}
   | exp SUB_OP factor {$$ = $1 - $3;}
   ;

factor: term
   | factor MULT_OP term {$$ = $1 * $3;}
   | factor DIV_OP term {$$ = $1 / $3;}
   ;

term: INTCONST;

%%

int main(int argc, char **argv) {
    ++argv, --argc;
    if ( argc > 0 )
            yyin = fopen(argv[0], "r");
    else
            yyin = stdin;
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "error: %s\n", s);
}
