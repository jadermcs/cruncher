/* Scanner for the     _
*  ___ ___ _ _ ___ ___| |_ ___ ___
* |  _|  _| | |   |  _|   | -_|  _|
* |___|_| |___|_|_|___|_|_|___|_|
*                              language.
* Authored by jadermcs, 21-09-2020.
* Details at: https://github.com/jadermcs/cruncher
*/
%option yylineno
%option nounput
%option noinput
%option outfile="src/cruncher_lex.yy.c"

%{
#include <cruncher.h>
extern char* strdup(const char*);
lexErrors errors;
int col_count = 1;
enum yytokentype current_type=1;
int current_addr=0;
%}

%x          COMMENTLINE
%x          COMMENTBLOCK

DIGIT       [0-9]
INTEGER     [+-]?{DIGIT}+
EXPON       [eE]{INTEGER}
FLOAT       [+-]?({DIGIT}*\.{DIGIT}+|{DIGIT}+\.){EXPON}

LETTER      [a-zA-Z]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT}|_)*
WHITESPACE  [\n\t ]+
SYMBOL      [!#$%&*+\.\\\/;<=>?@^\|-~:\,\(\)\[\]\{\}]
CHAR        '(\\.|[^\\'])+'
PATH        (\.|_)\"({LETTER}|{SYMBOL}|{DIGIT})*\"
STRING      \"(\\.|[^\\"])*\"
CRUNCH_OP   ${SYMBOL}

%%

"/*" { col_count += yyleng; BEGIN(COMMENTBLOCK); }
<COMMENTBLOCK>"*/" { col_count += yyleng; BEGIN(INITIAL); }
<COMMENTBLOCK>. { col_count += yyleng; }
<COMMENTBLOCK><<EOF>> {
    int error_num = errors.error_count;
    strcpy(errors.error_msg[error_num], "Unexpected end of file while in comment.");
    errors.at_line[error_num] = yylineno;
    errors.at_column[error_num] = col_count;
    errors.error_count++;
    BEGIN(INITIAL);
    yyterminate();
}

    /* keywords */
"while" { col_count += yyleng; return WHILE; }
"for" { col_count += yyleng; return FOR; }
"if" { col_count += yyleng; return IF; }
"in" { col_count += yyleng; return IN; }
"else" { col_count += yyleng; return ELSE; }
"return" { col_count += yyleng; return RETURN; }
"crunch" { col_count += yyleng; return CRUNCH; }

    /* types */
char|path|string|int|float|void {
    yylval.str = (char *)strdup(yytext);
    col_count += yyleng;
    return TYPE;
}

        /* definition */
"<=" { col_count += yyleng; return LESSEQUAL_OP; }
">=" { col_count += yyleng; return GREATEREQUAl_OP; }
"!=" { col_count += yyleng; return NOTEQUAL_OP; }
"==" { col_count += yyleng; return COMPARISON_OP; }
"||" { col_count += yyleng; return OR_OP; }
"&&" { col_count += yyleng; return AND_OP; }

 /* consts */
{INTEGER} { yylval.str = (char *)strdup(yytext); col_count += yyleng; return INTCONST; }
{FLOAT} { yylval.str = (char *)strdup(yytext); col_count += yyleng; return FLOATCONST; }
{CHAR} { yylval.str = (char *)strdup(yytext); col_count += yyleng; return CHARCONST; }
{PATH} { yylval.str = (char *)strdup(yytext); col_count += yyleng; return PATHCONST; }
{STRING} { yylval.str = (char *)strdup(yytext); col_count += yyleng; return STRINGCONST; }
{CRUNCH_OP} { yylval.op = yytext[1]; col_count += yyleng; return CRUNCH_OP; }
{SYMBOL} { yylval.str = (char *)strdup(yytext); col_count += yyleng; return yytext[0]; }
{IDENTIFIER} { yylval.str = (char *)strdup(yytext); col_count += yyleng; return IDENTIFIER; }
{WHITESPACE}* { col_count += yyleng; }

 /*non matching*/
. {
    col_count += yyleng;
    int error_num = errors.error_count;
    strcpy(errors.error_msg[error_num], yytext);
    errors.at_line[error_num] = yylineno;
    errors.at_column[error_num] = col_count;
    errors.error_count++;
}

%%

int has_error = 0;

int yywrap(void) {
    return 1;
}

void yyerror(const char *s){
  fprintf(stderr, "%d: %s\n", yylineno, s);
  has_error = 1;
}

/* int main(int argc, char **argv) { */
/*     ++argv, --argc;  /1* skip over program name *1/ */
/*     if ( argc > 0 ) */
/*             yyin = fopen( argv[0], "r" ); */
/*     else */
/*             yyin = stdin; */
/*     int tok; */
/*     errors.error_count = 0; */
/*     while((tok = yylex())) { */
/*         printf("%s\n", yytokenstring(tok)); */
/*         if (tok == INTCONST) */
/*             printf(" = %s\n", yylval.str); */
/*         else if (tok == FLOATCONST) */
/*             printf(" = %s\n", yylval.str); */
/*         else if (tok == PATHCONST) */
/*             printf(" = %s\n", yylval.str); */
/*         else if (tok == STRINGCONST) */
/*             printf(" = %s\n", yylval.str); */
/*         else if (tok == CHARCONST) */
/*             printf(" = %s\n", yylval.str); */
/*         else if (tok == IDENTIFIER) */
/*             printf(" = %s\n", yylval.str); */
/*         else if (tok == SYMBOL) */
/*             printf(" = %s\n", yylval.str); */
/*         else if (tok == TYPE) */
/*             printf(" = %s\n", yylval.str); */
/*     } */
/*     for (int i = 0; i < errors.error_count; i++) { */
/*         printf("Error: Unrecognized character in line %d, position %d: %s\n", */
/*             errors.at_line[i], errors.at_column[i], errors.error_msg[i]); */
/*     } */
/*     print_table(); */
/*     fclose(yyin); */
/*     yylex_destroy(); */
/*     free_table(); */
/* } */
