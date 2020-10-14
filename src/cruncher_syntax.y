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
/* %type <ast> program declarations declaration local_definitions local_var_definition */
%type <node> func_definition var_definition
%type <node> crunch_statement return_statement
/* %type <ast> expression_statement conditional_statement iteration_statement return_statement */
/* %type <ast> expression var simple_expression op_expression term */
/* %type <ast> compound_statement statement_list statement params param */
%type <node> params param term
%type <node> file

%type <op> crunch_op
%type <str> options

%token WHILE FOR IN IF ELSE CRUNCH RETURN PARAMS
%token ADD_OP SUB_OP MULT_OP DIV_OP REM_OP
%token NOT_OP LESSTHAN_OP LESSEQUAL_OP GREATERTHAN_OP GREATEREQUAl_OP
%token NOTEQUAL_OP COMPARISON_OP OR_OP AND_OP
%token COLON DEF_EQ PIPE

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
| TYPE IDENTIFIER DEF_EQ term ';' { $$ = newast('v', NULL, NULL); }
;

func_definition:
  TYPE IDENTIFIER '(' params ')' '{' inner_declarations '}' { $$ = newast('F', $4, $7); }
;

params:
  params ',' param { $$ = newast('A', $1, $3);}
| param { $$ = $1; }
| { $$ = NULL; }
;

param:
  TYPE IDENTIFIER { $$ = newast('P', NULL, NULL); }
;

inner_declarations:
  inner_declarations inner_declaration { $$ = newast('A', $1, $2); }
| inner_declaration {$$ = $1;}
| {$$ = NULL;}

inner_declaration:
  return_statement { $$ = $1; }
| crunch_statement { $$ = $1; }
| var_definition {$$ = $1;}
| func_definition {$$ = $1;}
;

return_statement:
  RETURN term ';' { $$ = $2; }
| RETURN ';' { $$ = NULL; }
;

crunch_statement:
  CRUNCH '(' file crunch_op options file')' ';' {
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
