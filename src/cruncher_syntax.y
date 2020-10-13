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

%union {
  char *id;
  char *type;
  char *op;
  char *str;
  struct ast_node *ast;
}

%start program
%type <ast> program declarations declaration local_definitions local_var_definition
%type <ast> func_definition var_definition
%type <ast> expression_statement conditional_statement iteration_statement return_statement
%type <ast> expression var simple_expression op_expression term
%type <ast> compound_statement statement_list statement params param

%token WHILE FOR IN IF ELSE CRUNCH RETURN PARAMS
%token ADD_OP SUB_OP MULT_OP DIV_OP REM_OP
%token NOT_OP LESSTHAN_OP LESSEQUAL_OP GREATERTHAN_OP GREATEREQUAl_OP
%token NOTEQUAL_OP COMPARISON_OP OR_OP AND_OP
%token COLON DEF_EQ PIPE

%token <id> IDENTIFIER
%token <str> INTCONST FLOATCONST CHARCONST STRINGCONST PATHCONST
%token <type> TYPE

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

expression:
  var DEF_EQ {
    if($1->dtype == 's'){
        string_target *new_string_target = (string_target *)malloc(sizeof *new_string_target);
        new_string_target->temp_name = $1->addr;
        STACK_PUSH(string_target_stack, new_string_target);
    }
  }
  simple_expression {
    if(mismatch($1->dtype, $4->dtype)){ error_type_mismatch($1->dtype, $4->dtype); }
    else {
        $$ = newast('A', $1, $4);
        $$->dtype = $1->dtype;
        if($$->dtype != 's'){
            gen2("mov", $1->addr, $4->addr);
        }
    }
  }
| simple_expression { $$ = $1; }
;

var:
  IDENTIFIER {
    $$ = newast('V', NULL, NULL);
    symbol_node *s = find_symbol($1);
    if(s == NULL){ error_not_declared("variable", $1); }
    else {
        $$->dtype = s->type;
        HASH_FIND_STR(symbol_table, $1, s);
        if(s != NULL && s->symbol_type != 'F'){ $$->addr = (char *) strdup($1); } // global variable
        else { $$->addr = find_simple_symbol($1)->temp_name; }
    }
    free($1);
  }
;

simple_expression:
  op_expression COMPARISON_OP op_expression {
    $$ = newast('A', $1, $3);
    if(mismatch($1->dtype, $3->dtype)){ error_type_mismatch($1->dtype, $3->dtype); }
    else { $$->dtype = $1->dtype; }
    $$->addr = new_temp();
    code_label *top_label = STACK_TOP(label_stack);
    gen3("seq", $$->addr, $1->addr, $3->addr);
    gen2("brz", top_label->name, $$->addr);
  }
| op_expression NOTEQUAL_OP op_expression {
    $$ = newast('A', $1, $3);
    if(mismatch($1->dtype, $3->dtype)){ error_type_mismatch($1->dtype, $3->dtype); }
    else { $$->dtype = $1->dtype; }
    $$->addr = new_temp();
    code_label *top_label = STACK_TOP(label_stack);
    gen3("seq", $$->addr, $1->addr, $3->addr);
    gen2("brnz", top_label->name, $$->addr);
  }
| op_expression LESSTHAN_OP op_expression {
    $$ = newast('A', $1, $3);
    if(mismatch($1->dtype, $3->dtype)){ error_type_mismatch($1->dtype, $3->dtype); }
    else { $$->dtype = $1->dtype; }
    $$->addr = new_temp();
    code_label *top_label = STACK_TOP(label_stack);
    gen3("slt", $$->addr, $1->addr, $3->addr);
    gen2("brz", top_label->name, $$->addr);
  }
| op_expression LESSEQUAL_OP op_expression {
     $$ = newast('A', $1, $3);
     if(mismatch($1->dtype, $3->dtype)){ error_type_mismatch($1->dtype, $3->dtype); }
     else { $$->dtype = $1->dtype; }
     $$->addr = new_temp();
     code_label *top_label = STACK_TOP(label_stack);
     gen3("sleq", $$->addr, $1->addr, $3->addr);
     gen2("brz", top_label->name, $$->addr);
  }
| op_expression GREATERTHAN_OP op_expression {
     $$ = newast('A', $1, $3);
     if(mismatch($1->dtype, $3->dtype)){ error_type_mismatch($1->dtype, $3->dtype); }
     else { $$->dtype = $1->dtype; }
     $$->addr = new_temp();
     code_label *top_label = STACK_TOP(label_stack);
     gen3("sleq", $$->addr, $1->addr, $3->addr);
     gen2("brnz", top_label->name, $$->addr);
  }
| op_expression GREATEREQUAl_OP op_expression {
     $$ = newast('A', $1, $3);
     if(mismatch($1->dtype, $3->dtype)){ error_type_mismatch($1->dtype, $3->dtype); }
     else { $$->dtype = $1->dtype; }
     $$->addr = new_temp();
     code_label *top_label = STACK_TOP(label_stack);
     gen3("slt", $$->addr, $1->addr, $3->addr);
     gen2("brnz", top_label->name, $$->addr);
  }
| op_expression { $$ = $1; }
;

op_expression:
  op_expression '+' term {
     $$ = newast('A', $1, $3);
     if(mismatch($1->dtype, $3->dtype)){error_type_mismatch($1->dtype, $3->dtype); }
     else { $$->dtype = $1->dtype; }
     $$->addr = new_temp();
     gen3("add", $$->addr, $1->addr, $3->addr);
  }
| op_expression '-' term {
     $$ = newast('A', $1, $3);
     if(mismatch($1->dtype, $3->dtype)){ error_type_mismatch($1->dtype, $3->dtype); }
     else { $$->dtype = $1->dtype; }
     $$->addr = new_temp();
     gen3("sub", $$->addr, $1->addr, $3->addr);
  }
| op_expression '*' term {
     $$ = newast('A', $1, $3);
     if(mismatch($1->dtype, $3->dtype)){ error_type_mismatch($1->dtype, $3->dtype); }
     else { $$->dtype = $1->dtype; }
     $$->addr = new_temp();
     gen3("mul", $$->addr, $1->addr, $3->addr);
  }
| op_expression '/' term {
     $$ = newast('A', $1, $3);
     if(mismatch($1->dtype, $3->dtype)){ error_type_mismatch($1->dtype, $3->dtype); }
     else { $$->dtype = $1->dtype; }
     $$->addr = new_temp();
     gen3("div", $$->addr, $1->addr, $3->addr);
  }
| op_expression '%' term {
     $$ = newast('A', $1, $3);
     if(mismatch($1->dtype, $3->dtype)){ error_type_mismatch($1->dtype, $3->dtype); }
     else { $$->dtype = $1->dtype; }
     $$->addr = new_temp();
     gen3("mod", $$->addr, $1->addr, $3->addr);
  }
| term { $$ = $1; }
;

term:
  '(' simple_expression ')' { $$ = $2; }
| var  { $$ = $1; }
| call {
     $$ = $1;
     symbol_node *s = find_symbol($1->func_name);
     if(s != NULL){ $$->dtype = s->type; }
  }
| INTCONST { $$ = newast('I', NULL, NULL); $$->addr = $1; $$->dtype = 'i'; }
| FLOATCONST { $$ = newast('D', NULL, NULL); $$->addr = $1; $$->dtype = 'f'; }
| QUOTES { }
  STRINGCONST QUOTES {
     $$ = $3;
     $$->dtype = 's';
  }
;

conditional_statement:
  startIf '(' simple_expression ')'compound_statement {
     $$ = newast('C', newast('c', $3, $5), NULL);
     remove_scope();

     code_label *after_if_label;
     STACK_POP(label_stack, after_if_label);
     gen_label(after_if_label->name);
     free(after_if_label->name);
     free(after_if_label);
  }
| startIf '(' simple_expression ')' compound_statement {
    remove_scope();

    char * after_else_label = new_label();
    gen1("jump", after_else_label);

    code_label *after_if_label;
    STACK_POP(label_stack, after_if_label);
    gen_label(after_if_label->name);
    free(after_if_label->name);
    free(after_if_label);

    code_label *new_after_else_label = (code_label *)malloc(sizeof *new_after_else_label);
    new_after_else_label->name = after_else_label;
    STACK_PUSH(label_stack, new_after_else_label);
  }
  ELSE { create_internal_scope(); }
  compound_statement {
      $$ = newast('C', newast('c', $3, $5), $9);
      remove_scope();

      code_label *after_else_label;
      STACK_POP(label_stack, after_else_label);
      gen_label(after_else_label->name);
      free(after_else_label->name);
      free(after_else_label);
  }
;

startIf:
  IF {
     create_internal_scope();
     char * after_if_label = new_label();
     code_label *new_after_if_label = (code_label *)malloc(sizeof *new_after_if_label);
     new_after_if_label->name = after_if_label;
     STACK_PUSH(label_stack, new_after_if_label);
  }
;

iteration_statement:
  WHILE {
     create_internal_scope();
     char * while_label = new_label();
     gen_label(while_label);
     code_label *new_while_label = (code_label *)malloc(sizeof *new_while_label);
     new_while_label->name = while_label;
     STACK_PUSH(label_stack, new_while_label);

     char * after_while_label = new_label();
     code_label *new_after_while_label = (code_label *)malloc(sizeof *new_after_while_label);
     new_after_while_label->name = after_while_label;
     STACK_PUSH(label_stack, new_after_while_label);
  }
  '(' simple_expression ')' {;}
  compound_statement {
      $$ = newast('W', $4, $7);
      remove_scope();

      code_label *after_while_label;
      STACK_POP(label_stack, after_while_label);
      code_label *while_label;
      STACK_POP(label_stack, while_label);

      gen1("jump", while_label->name);
      gen_label(after_while_label->name);

      free(after_while_label->name);
      free(after_while_label);
      free(while_label->name);
      free(while_label);
  }
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
