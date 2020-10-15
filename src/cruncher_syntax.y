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
#include <string.h>
#include "uthash.h"
#include "ast.h"
extern int yylineno;
extern int yylex();
extern int yyparse();
extern FILE* yyin;

extern void yyerror(const char* s);
struct ast* syntax_tree = NULL;
%}

%union {
  char *id;
  char *type;
  char op;
  char *str;
  struct ast *node;
}

%start program
%type <node> program declarations declaration
%type <node> inner_declarations inner_declaration
%type <node> func_definition var_definition
%type <node> crunch_statement return_statement while_statement
%type <node> params param term expression
%type <node> eq_expression relational_expression and_expression assignment_expression
%type <node> conditional_expression mul_expression add_expression
%type <node> file

%type <op> crunch_op
%type <str> options

%token WHILE FOR IN IF ELSE CRUNCH RETURN PARAMS
%right ADD_OP SUB_OP MULT_OP DIV_OP REM_OP
%right NOT_OP LESSTHAN_OP LESSEQUAL_OP GREATERTHAN_OP GREATEREQUAl_OP
%right NOTEQUAL_OP COMPARISON_OP OR_OP AND_OP
%left COLON DEF_EQ PIPE

%token <id> IDENTIFIER
%token <str> INTCONST FLOATCONST CHARCONST STRINGCONST PATHCONST
%token <type> TYPE
%token <op> SYMBOL

%%

program:
  declarations { syntax_tree = $1; }
;

declarations:
  declarations declaration { $$ = newast('D', $1, $2);}
| declaration {$$ = $1;}
;

declaration:
  var_definition {$$ = $1;}
| func_definition {$$ = $1;}
;

var_definition:
  TYPE IDENTIFIER ';' { $$ = newast('V', NULL, NULL); }
| TYPE IDENTIFIER DEF_EQ term ';' { $$ = newast('V', NULL, NULL); }
;

func_definition:
  TYPE IDENTIFIER '(' params ')' '{' inner_declarations '}' { $$ = newast('F', $4, $7); }
;

params:
  params ',' param { $$ = newast('P', $1, $3);}
| param { $$ = $1; }
| { $$ = NULL; }
;

param:
  TYPE IDENTIFIER { $$ = newast('A', NULL, NULL); }
;

inner_declarations:
  inner_declarations inner_declaration { $$ = newast('S', $1, $2); }
| inner_declaration {$$ = $1;}
;

inner_declaration:
  return_statement { $$ = $1; }
| while_statement { $$ = $1; }
| crunch_statement { $$ = $1; }
| var_definition {$$ = $1;}
| func_definition {$$ = $1;}
;

return_statement:
  RETURN term ';' { $$ = $2; }
| RETURN ';' { $$ = NULL; }
;

crunch_statement:
  CRUNCH '(' file crunch_op options file ')' ';' {
    $$ = newast('C', $3, $6);
    $$->dtype = $4;
    $$->prop.str = $5;
}
;

file:
  PATHCONST {$$ = newast('p', NULL, NULL); }
| IDENTIFIER {$$ = newast('I', NULL, NULL); }
;

crunch_op:
  '$' SYMBOL { $$ = yylval.op; }
;

options:
  '(' STRINGCONST ')' { $$ = $2; }
| { $$ = NULL; }
;

term:
  INTCONST {$$ = newast('i', NULL, NULL);}
| FLOATCONST {$$ = newast('f', NULL, NULL);}
| CHARCONST {$$ = newast('c', NULL, NULL);}
| STRINGCONST {$$ = newast('s', NULL, NULL);}
| PATHCONST {$$ = newast('p', NULL, NULL);}
;

while_statement:
  WHILE '(' expression ')' '{' inner_declarations '}' { $$ = newast('L', $3, $6); }
;

expression:
  expression ',' assignment_expression { $$ = newast('E', $1, $3); }
| assignment_expression {$$ = $1; }
;

assignment_expression:
  conditional_expression { $$ = $1; }
| IDENTIFIER DEF_EQ assignment_expression { $$ = newast('A', NULL, $3); }
;

conditional_expression:
  and_expression { $$ = $1; }
| conditional_expression OR_OP conditional_expression {$$ = newast('|', $1, $3);}
;

and_expression:
  eq_expression { $$ = $1; }
| and_expression AND_OP and_expression { $$ = newast('&', $1, $3); }
;

eq_expression:
  relational_expression { $$ = $1; }
| eq_expression COMPARISON_OP relational_expression { $$ = newast('=', $1, $3); }
| eq_expression NOTEQUAL_OP relational_expression { $$ = newast('=', $1, $3); }
;

relational_expression:
  add_expression {$$ = $1;}
| relational_expression LESSTHAN_OP add_expression { $$ = newast('R', $1, $3); }
| relational_expression LESSEQUAL_OP add_expression { $$ = newast('R', $1, $3); }
| relational_expression GREATERTHAN_OP add_expression { $$ = newast('R', $1, $3); }
| relational_expression GREATEREQUAl_OP add_expression { $$ = newast('R', $1, $3); }
;

add_expression:
  mul_expression { $$ = $1; }
| add_expression ADD_OP mul_expression { $$ = newast('+', $1, $3); }
| add_expression SUB_OP mul_expression { $$ = newast('+', $1, $3); }
;

mul_expression:
  term { $$ = $1; }
| mul_expression MULT_OP term { $$ = newast('*', $1, $3); }
| mul_expression DIV_OP term { $$ = newast('*', $1, $3); }
| mul_expression REM_OP term { $$ = newast('*', $1, $3); }
;

%%

int main(int argc, char **argv) {
    ++argv, --argc;
    if ( argc > 0 )
            yyin = fopen(argv[0], "r");
    else
            yyin = stdin;
    yyparse();
    printast(syntax_tree, 0);
    return 0;
}
