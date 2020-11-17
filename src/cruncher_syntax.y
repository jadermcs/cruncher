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
#include "cruncher.h"
#include "ast.h"
extern int yylineno;
extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylex_destroy();
extern void yyerror(const char* s);
extern void add_symbol(char *, char, char);
extern void add_table(char *, char, char);
extern void print_table();
extern void free_table();
extern symbolTable *find_symbol(char *);
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
%token ADD_OP SUB_OP MULT_OP DIV_OP REM_OP
%token NOT_OP LESSTHAN_OP LESSEQUAL_OP GREATERTHAN_OP GREATEREQUAl_OP
%token NOTEQUAL_OP COMPARISON_OP
%right OR_OP AND_OP
%token COLON DEF_EQ PIPE

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
    add_table($2->addr, 'V', $1[0]);
    free($1);
  }
| TYPE identifier '=' expression ';' {
    $$ = newast('V', $2, $4);
    add_table($2->addr, 'V', $1[0]);
    free($1);
  }
;

func_definition:
  TYPE identifier
  '(' params ')'
  '{' inner_declarations '}' {
    add_table($2->addr, 'F', $1[0]);
    $$ = newast('F', $2, newast('F', $4, $7));
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
    add_symbol($2->addr, 'P', $1[0]);
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
    add_symbol($2->addr, 'V', $1[0]);
    free($1);
  }
| TYPE identifier '=' expression ';' {
    $$ = newast('V', $2, $4);
    add_symbol($2->addr, 'V', $1[0]);
    free($1);
  }
;

selection_statement:
  IF '(' expression ')' '{' inner_declarations '}' {$$ = newast('E', $3, $6); $$->dtype = 'i'; }
| IF '(' expression ')' '{' inner_declarations '}' ELSE '{' inner_declarations '}' {
    struct ast *tmp = newast('E', $3, $6);
    tmp->dtype = 'i';
    $$ = newast('E', tmp, $10);
    $$->dtype = 'e';
  }
;

return_statement:
  RETURN term ';' { $$ = newast('J', $2, NULL); $$->dtype = 'r'; }
| RETURN ';' { $$ = newast('J', NULL, NULL); $$->dtype = 'r'; }
;

crunch_statement:
  CRUNCH '(' file CRUNCH_OP options file ')' ';' {
    $$ = newast('C', $3, $6);
    $$->dtype = $4;
    if ($5) $$->value.str_ = (char *)strdup($5);
    else $$->value.str_ = NULL;
    free($5);
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
  identifier {$$ = $1;}
| INTCONST {
    $$ = newast('c', NULL, NULL);
    $$->dtype = 'i';
    $$->value.int_ = atoi($1);
    free($1);
  }
| FLOATCONST {
    $$ = newast('c', NULL, NULL);
    $$->dtype = 'f';
    $$->value.float_ = atof($1);
    free($1);
  }
| CHARCONST {
    $$ = newast('c', NULL, NULL);
    $$->dtype = 'c';
    $$->value.char_ = $1[0];
    free($1);
  }
| STRINGCONST {
    $$ = newast('c', NULL, NULL);
    $$->dtype = 's';
    $$->value.str_ = strdup($1);
    free($1); }
| pathconst {$$ = $1; }
;

pathconst:
  PATHCONST {
    $$ = newast('c', NULL, NULL);
    $$->value.str_ = strdup($1);
    $$->dtype = 'p';
    $$->flag = $1[0];
    free($1);
}
;

while_statement:
  WHILE '(' expression ')' '{' inner_declarations '}' { $$ = newast('L', $3, $6); $$->dtype = 'w'; }
;

for_statement:
  FOR '(' for_expression ')' '{' inner_declarations '}' { $$ = newast('L', $3, $6); $$->dtype = 'f'; }
;

for_expression:
  simple_expression ';' expression ';' expression {
    $$ = newast('E', $1, newast('E', $3, $5));
    $$->dtype = '3';
  }
| sub_expression IN file { $$ = newast('E', $1, $3);  $$->dtype = 'p'; }
;

simple_expression:
  simple_expression '=' term {
    $$ = newast('H', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
| sub_expression { $$ = $1; }
;

sub_expression:
  TYPE identifier { $$ = $2; add_symbol($2->addr, 'E', $1[0]); free($1);}
| identifier {
    $$ = $1;
    symbolTable *s = find_symbol($1->addr);
    if (s == NULL) error_scope();
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
| identifier '=' assignment_expression { $$ = newast('=', $1, $3); }
;

conditional_expression:
  and_expression { $$ = $1; }
| conditional_expression OR_OP conditional_expression {
    $$ = newast('B', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
;

and_expression:
  eq_expression { $$ = $1; }
| and_expression AND_OP and_expression {
    $$ = newast('B', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
;

eq_expression:
  relational_expression { $$ = $1; }
| eq_expression COMPARISON_OP relational_expression {
    $$ = newast('R', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
| eq_expression NOTEQUAL_OP relational_expression {
    $$ = newast('R', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
;

relational_expression:
  add_expression {$$ = $1;}
| relational_expression '<' add_expression {
    $$ = newast('R', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
| relational_expression LESSEQUAL_OP add_expression {
    $$ = newast('R', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
| relational_expression '>' add_expression {
    $$ = newast('R', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
| relational_expression GREATEREQUAl_OP add_expression {
    $$ = newast('R', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
;

add_expression:
  mul_expression { $$ = $1; }
| add_expression '+' mul_expression {
    $$ = newast('Z', $1, $3);
    if (type_match($1->dtype, $3->dtype) == 0) error_type();
    else $$->dtype = $1->dtype;
  }
| add_expression '-' mul_expression {
    $$ = newast('Z', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
;

mul_expression:
  term { $$ = $1; }
| mul_expression '*' term {
    $$ = newast('Z', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
| mul_expression '/' term {
    $$ = newast('Z', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
| mul_expression '%' term {
    $$ = newast('Z', $1, $3);
    if (type_match($1->dtype, $3->dtype)) error_type();
    else $$->dtype = $1->dtype;
  }
;

exp_statement:
  expression ';' { $$ = $1; }
| call ';' {$$ = $1; }
;

call:
  identifier '(' args ')' {
    $$ = newast('T', $1, $3);
    symbolTable *s = find_symbol($1->addr);
    if (s == NULL) error_scope();
  }
;

args:
 args_list {$$ = $1; }
| %empty {$$ = NULL; }
;
args_list:
  args_list ',' term { $$ = newast('G', $1, $3); }
| term {$$ = $1;}
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
    free_table();
    free_ast(syntax_tree);
    fclose(yyin);
    yylex_destroy();
    return 0;
}