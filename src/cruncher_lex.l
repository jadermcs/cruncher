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

static enum yytokentype valid_id();

lexErrors errors;
int col_count = 1;
enum yytokentype current_type=INT_TYPE;
int current_addr=0;
char yysval[1024];
%}

%x          COMMENTLINE
%x          COMMENTBLOCK

DIGIT       [0-9]
INTEGER     [+-]?{DIGIT}+
EXPON       [eE]{INTEGER}
FLOAT       [+-]?({DIGIT}*\.{DIGIT}+|{DIGIT}+\.)

LETTER      [a-zA-Z]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT}|_)*
WHITESPACE  [\n\t ]+
SYMBOL      [!#$%&*+\.\\\/;<=>?@^\|-~:]
CHAR        '(\\.|[^\\'])+'
STRING      \"(\\.|[^\\"])*\"
PATH        ("."|_)\"(LETTER|SYMBOL)*\"

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
"char|path|string|int|float|void" { col_count += yyleng; return TYPE; }

        /* definition */
"+" { col_count += yyleng; return ADD_OP; }
"-" { col_count += yyleng; return SUB_OP; }
"*" { col_count += yyleng; return MULT_OP; }
"/" { col_count += yyleng; return DIV_OP; }
"%" { col_count += yyleng; return REM_OP; }
"!" { col_count += yyleng; return NOT_OP; }
"<" { col_count += yyleng; return LESSTHAN_OP; }
"<=" { col_count += yyleng; return LESSEQUAL_OP; }
">" { col_count += yyleng; return GREATERTHAN_OP; }
">=" { col_count += yyleng; return GREATEREQUAl_OP; }
"!=" { col_count += yyleng; return NOTEQUAL_OP; }
"==" { col_count += yyleng; return COMPARISON_OP; }
"||" { col_count += yyleng; return OR_OP; }
"&&" { col_count += yyleng; return AND_OP; }
"{" { col_count += yyleng; return LBRACE; }
"}" { col_count += yyleng; return RBRACE; }
"[" { col_count += yyleng; return LBRACKET; }
"]" { col_count += yyleng; return RBRACKET; }
"(" { col_count += yyleng; return LPARENTHESES; }
")" { col_count += yyleng; return RPARENTHESES; }
":" { col_count += yyleng; return COLON; }
";" { col_count += yyleng; return SEMICOLON; }
"|" { col_count += yyleng; return PIPE; }
"=" { col_count += yyleng; return DEF_EQ; }
"," { col_count += yyleng; return COMMA; }

 /* consts */
{INTEGER} { col_count += yyleng; strcpy(yysval, yytext); return INTCONST; }
{FLOAT} { col_count += yyleng; strcpy(yysval, yytext); return FLOATCONST; }
{CHAR} { col_count += yyleng; strcpy(yysval, yytext); return CHARCONST; }
{PATH} { col_count += yyleng; strcpy(yysval, yytext); return PATHCONST; }
{STRING} { col_count += yyleng; strcpy(yysval, yytext); return STRINGCONST; }
{SYMBOL} { col_count += yyleng; strcpy(yysval, yytext); return SYMBOL; }
{IDENTIFIER} { col_count += yyleng; strcpy(yysval, yytext); return valid_id(); }
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
