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
%define parse.error verbose
%define parse.trace
%locations
%{
#include "cruncher.h"
#include "ast.h"
#define utstring_fromint(value) \
    UT_string * tmp; \
    utstring_new(tmp); \
    utstring_printf(tmp, "%d", value);

extern int yylineno;
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylex_destroy();
extern void yyerror(const char* s);
extern labelStack *lhead;
int addr_counter;
int label_counter;
int param_counter;
int var_counter;
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
%type <node> program declarations declaration inner_declarations inner_declaration
%type <node> func_definition var_definition local_var_definition
%type <node> crunch_statement return_statement while_statement exp_statement
%type <node> selection_statement for_statement sub_expression
%type <node> params param term expression for_expression simple_expression
%type <node> eq_expression relational_expression and_expression assignment_expression
%type <node> conditional_expression mul_expression add_expression
%type <node> file args args_list call identifier pathconst

%type <str> options

%token WHILE FOR IN IF ELSE CRUNCH RETURN
%token NOTEQUAL_OP COMPARISON_OP LESSEQUAL_OP GREATEREQUAl_OP
%left OR_OP AND_OP

%token <id> IDENTIFIER
%token <str> INTCONST FLOATCONST CHARCONST STRINGCONST PATHCONST
%token <type> TYPE
%token <op> CRUNCH_OP

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
  TYPE identifier ';' {
    $$ = $2;
    $$->dtype = $1[0];
    add_table($2->addr, 'V', $1[0]);
    free($1);
  }
| TYPE identifier '=' expression ';' {
    $$ = newast('V', $2, $4);
    $$->dtype = $1[0];
    add_table($2->addr, 'V', $1[0]);
    free($1);
  }
;

func_definition:
  TYPE identifier {
    addr_counter = 0;
    label_counter = 0;
    param_counter = 0;
    gen_fmt("\n");
    gen_label($2->addr);
  }
  '(' params ')' {;}
  '{' inner_declarations '}' {
    $$ = newast('F', NULL, $9);
    add_table($2->addr, 'F', $1[0]);
    free($1);
  }
;

params:
  params ',' param { $$ = newast('P', $1, $3);}
| param { $$ = $1; }
| %empty { $$ = NULL; }
;

param:
  TYPE identifier {
    $$ = newast('A', $2, NULL);
    new_addr($$->addr);
    add_symbol($2->addr, 'P', $1[0], $$->addr);
    free($1);
  }
;

inner_declarations:
  inner_declarations inner_declaration { $$ = newast('S', $1, $2); }
| inner_declaration {$$ = $1;}
;

inner_declaration:
  return_statement { $$ = $1; }
| while_statement { $$ = $1; }
| selection_statement { $$ = $1; }
| for_statement { $$ = $1; }
| crunch_statement { $$ = $1; }
| exp_statement { $$ = $1; }
| local_var_definition {$$ = $1;}
;

local_var_definition:
  TYPE identifier ';' {
    $$ = $2;
    $$->dtype = $1[0];
    char tmp[8];
    new_addr(tmp);
    add_symbol($2->addr, 'V', $1[0], tmp);
    free($1);
  }
| TYPE identifier '=' expression ';' {
    $$ = newast('V', $2, $4);
    $$->dtype = $1[0];
    new_addr($$->addr);
    add_symbol($2->addr, 'V', $1[0], $$->addr);
    gen2("mov", $$->addr, $4->addr);
    free($1);
  }
;

selection_statement:
  if_block '(' expression ')' '{' inner_declarations '}' {
    $$ = newast('E', newast('E', $3, $6), NULL);
    
    labelStack *tmp;
    STACK_POP(lhead, tmp);
    gen_label(tmp->label);
  }
| if_block '(' expression ')' '{' inner_declarations '}' {

    char tmp_label[8];
    new_label(tmp_label);
    gen1("jump", tmp_label);

    labelStack *a_tmp;
    STACK_POP(lhead, a_tmp);
    gen_label(a_tmp->label);

    labelStack *ltmp = (labelStack *)malloc(sizeof *ltmp);
    strcpy(ltmp->label, tmp_label);
    STACK_PUSH(lhead, ltmp);
  }
  ELSE '{' inner_declarations '}' {
    $$ = newast('E', newast('E', $3, $6), $11);
    labelStack *tmp;
    STACK_POP(lhead, tmp);
    gen_label(tmp->label);
  }
;

if_block:
  IF {
    char tmp_label[8];
    new_label(tmp_label);
    labelStack *ltmp = (labelStack *)malloc(sizeof *ltmp);
    strcpy(ltmp->label, tmp_label);
    STACK_PUSH(lhead, ltmp);
  };

return_statement:
  RETURN term ';' {
    $$ = newast('J', $2, NULL);
    $$->dtype = $2->dtype;
    gen1("return", $2->addr);
  }
| RETURN ';' {
    $$ = newast('J', NULL, NULL);
    $$->dtype = 'v';
    gen0("return");
  }
;

crunch_statement:
  CRUNCH '(' file CRUNCH_OP options file ')' ';' {
    $$ = newast('C', $3, $6);
    $$->dtype = $4;
    if ($5) $$->value.str_ = (char *)strdup($5);
    else $$->value.str_ = NULL;
    free($5);
    gen0("nop // crunch operation here"); /*TODO: implement when possible*/
}
;

file:
  pathconst {$$ = $1; }
| identifier {$$ = $1; }
;

options:
  '(' STRINGCONST ')' { $$ = $2; }
| %empty { $$ = NULL; }
;

term:
  '(' assignment_expression ')' { $$ = $2; }
| identifier {
    $$ = $1;
    symbolTable *s = find_symbol($1->addr);
    if (s == NULL) error_scope();
    else {
      $$->dtype = s->dtype;
      strcpy($$->addr, s->symbol);
    }
  }
| INTCONST {
    $$ = newast('c', NULL, NULL);
    $$->dtype = 'i';
    $$->value.int_ = atoi($1);
    strcpy($$->addr, $1);
  }
| FLOATCONST {
    $$ = newast('c', NULL, NULL);
    $$->dtype = 'f';
    $$->value.float_ = atof($1);
    strcpy($$->addr, $1);
  }
| CHARCONST {
    $$ = newast('c', NULL, NULL);
    $$->dtype = 'c';
    $$->value.char_ = $1[0];
    new_var($$->addr);
    gen_var("char", $$->addr, $$->value.str_);
    free($1);
  }
| STRINGCONST {
    $$ = newast('c', NULL, NULL);
    $$->dtype = 's';
    $$->value.str_ = strdup($1);
    new_var($$->addr);
    gen_var("char", $$->addr, $$->value.str_);
    free($1);
  }
| pathconst { $$ = $1; }
| call { $$ = $1;}
;

pathconst:
  PATHCONST {
    $$ = newast('c', NULL, NULL);
    $$->value.str_ = strdup($1);
    $$->dtype = 'p';
    $$->flag = $1[0];
    new_var($$->addr);
    gen_var("// path not implemented", "", "");
    free($1);
}
;

while_statement:
  WHILE {
    char tmp_label[8];
    new_label(tmp_label);
    gen_label(tmp_label);
    labelStack *ltmp = (labelStack *)malloc(sizeof *ltmp);
    strcpy(ltmp->label, tmp_label);
    STACK_PUSH(lhead, ltmp);

    new_label(tmp_label);
    labelStack *a_tmp = (labelStack *)malloc(sizeof *a_tmp);
    strcpy(a_tmp->label, tmp_label);
    STACK_PUSH(lhead, a_tmp);
  }
  '(' expression ')' '{' inner_declarations '}' {
    $$ = newast('L', $4, $7);
    labelStack *ltmp = (labelStack *)malloc(sizeof *ltmp);
    STACK_POP(lhead, ltmp);

    labelStack *a_tmp = (labelStack *)malloc(sizeof *a_tmp);
    STACK_POP(lhead, a_tmp);
    gen1("jump", a_tmp->label);

    gen_label(ltmp->label);
    free(a_tmp);
    free(ltmp);
  }
;

for_statement:
  FOR {
    char tmp_label[8];
    new_label(tmp_label);
    labelStack *ltmp = (labelStack *)malloc(sizeof *ltmp);
    strcpy(ltmp->label, tmp_label);
    STACK_PUSH(lhead, ltmp);

    new_label(tmp_label);
    labelStack *a_tmp = (labelStack *)malloc(sizeof *a_tmp);
    strcpy(a_tmp->label, tmp_label);
    STACK_PUSH(lhead, a_tmp);
  }
  '(' for_expression ')' '{' inner_declarations '}' {
    $$ = newast('L', $4, $7);
    labelStack *ltmp = (labelStack *)malloc(sizeof *ltmp);
    STACK_POP(lhead, ltmp);

    labelStack *a_tmp = (labelStack *)malloc(sizeof *a_tmp);
    STACK_POP(lhead, a_tmp);
    gen1("jump", a_tmp->label);

    gen_label(ltmp->label);
    free(a_tmp);
    free(ltmp);
  }
;

for_expression:
  simple_expression ';' expression ';' expression {
    $$ = newast('E', $1, newast('E', $3, $5));
  }
;

simple_expression:
  simple_expression '=' term {
    $$ = newast('H', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    symbolTable *tmp = find_symbol($1->addr);
    gen2("mov", tmp->symbol, $3->addr);
    
    labelStack *a_tmp = (labelStack *)malloc(sizeof *a_tmp);
    a_tmp = STACK_TOP(lhead);
    gen_label(a_tmp->next->label);
  }
| sub_expression { $$ = $1; }
;

sub_expression:
  TYPE identifier {
    $$ = $2;
    char tmp[8];
    new_addr(tmp);
    add_symbol($2->addr, 'E', $1[0], tmp);
    $$->dtype = $1[0];
    free($1);
  }
| identifier {
    $$ = $1;
    symbolTable *s = find_symbol($1->addr);
    if (s == NULL) error_scope();
    else $$->dtype = s->dtype;
  }
;

identifier:
  IDENTIFIER {
    $$ = newast('I', NULL, NULL);
    strcpy($$->addr, $1);
    free($1);
  }
;

expression:
  expression ',' assignment_expression { $$ = newast('H', $1, $3); }
| assignment_expression {$$ = $1; }
;

assignment_expression:
  conditional_expression { $$ = $1; }
| identifier '=' assignment_expression {
    $$ = newast('=', $1, $3);
    symbolTable *s = find_symbol($1->addr);
    if (s == NULL) error_scope();
    else $$->dtype = s->dtype;
    gen2("mov", s->symbol, $3->addr);
  }
;

conditional_expression:
  and_expression { $$ = $1; }
| conditional_expression OR_OP conditional_expression {
    $$ = newast('B', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    gen3("or", $$->addr, $1->addr, $3->addr);
  }
;

and_expression:
  eq_expression { $$ = $1; }
| and_expression AND_OP and_expression {
    $$ = newast('B', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    gen3("and", $$->addr, $1->addr, $3->addr);
  }
;

eq_expression:
  relational_expression { $$ = $1; }
| eq_expression COMPARISON_OP relational_expression {
    $$ = newast('R', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    labelStack *top_label = STACK_TOP(lhead);
    gen3("seq", $$->addr, $1->addr, $3->addr);
    gen2("brz", top_label->label, $$->addr);
  }
| eq_expression NOTEQUAL_OP relational_expression {
    $$ = newast('R', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    labelStack *top_label = STACK_TOP(lhead);
    gen3("seq", $$->addr, $1->addr, $3->addr);
    gen2("brnz", top_label->label, $$->addr);
  }
;

relational_expression:
  add_expression {$$ = $1;}
| relational_expression '<' add_expression {
    $$ = newast('R', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    labelStack *top_label = STACK_TOP(lhead);
    gen3("slt", $$->addr, $1->addr, $3->addr);
    gen2("brz", top_label->label, $$->addr);
  }
| relational_expression LESSEQUAL_OP add_expression {
    $$ = newast('R', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    labelStack *top_label = STACK_TOP(lhead);
    gen3("sleq", $$->addr, $1->addr, $3->addr);
    gen2("brz", top_label->label, $$->addr);
  }
| relational_expression '>' add_expression {
    $$ = newast('R', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    labelStack *top_label = STACK_TOP(lhead);
    gen3("sleq", $$->addr, $1->addr, $3->addr);
    gen2("brnz", top_label->label, $$->addr);
  }
| relational_expression GREATEREQUAl_OP add_expression {
    $$ = newast('R', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    labelStack *top_label = STACK_TOP(lhead);
    gen3("slt", $$->addr, $1->addr, $3->addr);
    gen2("brnz", top_label->label, $$->addr);
  }
;

add_expression:
  mul_expression { $$ = $1; }
| add_expression '+' mul_expression {
    $$ = newast('Z', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    gen3("add", $$->addr, $1->addr, $3->addr);
  }
| add_expression '-' mul_expression {
    $$ = newast('Z', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    gen3("sub", $$->addr, $1->addr, $3->addr);
  }
;

mul_expression:
  term { $$ = $1; }
| mul_expression '*' term {
    $$ = newast('Z', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    gen3("mul", $$->addr, $1->addr, $3->addr);
  }
| mul_expression '/' term {
    $$ = newast('Z', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    gen3("div", $$->addr, $1->addr, $3->addr);
  }
| mul_expression '%' term {
    $$ = newast('Z', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type($1->dtype, $3->dtype);
    else $$->dtype = $1->dtype;
    new_addr($$->addr);
    gen3("mod", $$->addr, $1->addr, $3->addr);
  }
;

exp_statement:
  expression ';' { $$ = $1; }
| error ';' { $$ = NULL; }
;

call:
  identifier '(' args ')' {
    $$ = newast('T', $1, $3);
    symbolTable *s = find_symbol($1->addr);
    $$->dtype = s->dtype;
    if (s == NULL || s->type != 'F') error_scope();
    else if (param_counter > 0) {
      /*utstring_fromint(param_counter);
      gen2("call", $1->addr, utstring_body(tmp));
      utstring_free(tmp);*/
    }
    else gen1("call", $1->addr);
    param_counter = 0;
    new_addr($$->addr);
    if(s->type != 'v') gen1("pop", $$->addr);
  }
;

args:
 args_list {$$ = $1; }
| %empty {$$ = NULL; }
;
args_list:
  args_list ',' term {
    $$ = newast('G', $1, $3);
    param_counter++;
    gen1("param", $3->addr);
  }
| term {
    $$ = $1;
    param_counter++;
    gen1("param", $1->addr);
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
    print_ast(syntax_tree, 0);
    print_table();
    print_tac();
    free_tac();
    free_table();
    free_ast(syntax_tree);
    fclose(yyin);
    yylex_destroy();
    return 0;
}
