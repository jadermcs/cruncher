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
#include "ast.h"
extern int yylineno;
extern int yylex();
extern int yyparse();
extern FILE* yyin;

extern void yyerror(const char* s);
%}

%start program
%token SYMBOL IDENTIFIER
%token INTCONST FLOATCONST CHARCONST STRINGCONST PATHCONST
%token WHILE FOR IN IF ELSE CRUNCH RETURN
%token TYPE PARAMS
%token ADD_OP SUB_OP MULT_OP DIV_OP REM_OP
%token NOT_OP LESSTHAN_OP LESSEQUAL_OP GREATERTHAN_OP GREATEREQUAl_OP
%token NOTEQUAL_OP COMPARISON_OP OR_OP AND_OP
%token COLON DEF_EQ PIPE

%%

program:
  declarations {syntax_tree = $1;}
;

declarations:
  declarations declaration {$$ = newast('A', $1, $2);}
| declaration {$$ = $1;}
;

declaration:
  var_definition {$$ = $1;}
| func_definition {$$ = $1;}
;

var_definition:
  TYPE IDENTIFIER ';' {
    $$ = NULL;
    add_symbol($2, $1, 'V', NULL);
    gen_table_symbol($1, $2);
    free($1);
    free($2);
}
;

func_definition:
  TYPE IDENTIFIER {
    tmp_gen = 0;
    params_gen = 0;
    add_symbol($2, $1, 'F', NULL);
    gen_label($2);
    scope *new_scope = (scope *)malloc(sizeof *new_scope);
    new_scope->scope_name = (char *) strdup($2);
    new_scope->scope_level = 1;
    STACK_PUSH(scope_stack, new_scope);
}
  '(' params ')' { ; }
  compound_statement {
    $$ = newast('F', NULL, $8);
    $$->dtype = type_to_dtype($1);
    $$->func_name = (char *) strdup($2);
    symbol_node *s = find_symbol($2);
    s->func_fields.func_body = $8;

    remove_scope();
    scope_stack = NULL;
    if(!has_return && strcmp($2, "main") != 0){
        if($$->dtype == 'i') gen1("return", "0");
        else if($$->dtype == 'f') gen1("return", "0.0");
        else gen0("return");
    }

    free($1);
    free($2);
}
;

params:
  params ',' param { $$ = newast('A', $1, $3); }
| param { $$ = $1; }
| { $$ = NULL; }

param:
  TYPE IDENTIFIER {
    $$ = newast('P', NULL, NULL);
    $$->dtype = type_to_dtype($1);
    scope *top = STACK_TOP(scope_stack);
    if(strcmp(top->scope_name, "main") == 0){
         $$->addr = new_temp();
         if ($$->dtype == 'i') gen2("mov", $$->addr, "0");
         else if ($$->dtype == 'f') gen2("mov", $$->addr, "0.0");
    }
    else $$->addr = new_param();

    add_symbol($2, $1, 'P', $$->addr);
    free($1);
    free($2);
}
;

compound_statement:
  '{' local_definitions statement_list '}' { $$ = newast('A', $2, $3); }
;

local_definitions:
  local_definitions local_var_definition { $$ = newast('A', $1, $2); }
| { $$ = NULL; }
;

local_var_definition:
  TYPE IDENTIFIER ';' {
    $$ = newast('V', NULL, NULL);
    $$->dtype = type_to_dtype($1);
    $$->addr = new_temp();
    if ($$->dtype == 'i') gen2("mov", $$->addr, "0");
    else if ($$->dtype == 'f') gen2("mov", $$->addr, "0.0");
    add_symbol($2, $1, 'V', $$->addr);
    free($1);
    free($2);
}

statement_list:
  statement_list statement { $$ = newast('A', $1, $2); }
| { $$ = NULL; }
;

statement:
  expression_statement { $$ = $1; }
| conditional_statement { $$ = $1; }
| iteration_statement { $$ = $1; }
| return_statement { $$ = $1; }
;

expression_statement:
  expression ';'                                { $$ = $1; }
| error ';'                                     { $$ = NULL; }
;

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
