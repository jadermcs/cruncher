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
int yylval;
char* yysval;
%}

%x          COMMENTLINE
%x          COMMENTBLOCK

DIGIT       [0-9]
INTEGER     [+-]?{DIGIT}+
EXPON       [eE]{INTEGER}
FLOAT       {INTEGER}"."({DIGIT})*{EXPON}?

LSMALL      [a-z\_]
LLARGE      [A-Z]
WHITECHAR   [\n\t ]
SYMBOL      [!#$%&*+.\\\/;<=>?@^\|-~:]
GRAPHIC     {LSMALL}|{LLARGE}|{SYMBOL}|{WHITECHAR}|{DIGIT}
CHAR        \'{GRAPHIC}\'
STRING      \"({GRAPHIC})*\"
PATH        ("."|_){STRING}

%%

"/*" {
    col_count += yyleng;
    BEGIN(COMMENTBLOCK);
}

<COMMENTBLOCK>"*/" {
    col_count += yyleng;
    BEGIN(INITIAL);
}

<COMMENTBLOCK>\n {
    col_count += yyleng;
}

<COMMENTBLOCK>. {
    col_count += yyleng;
}

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
"while" {
    col_count += yyleng;
    return WHILE_KW;
}

"for" {
    col_count += yyleng;
    return FOR_KW;
}

"if" {
    col_count += yyleng;
    return IF_KW;
}

"in" {
    col_count += yyleng;
    return IN_KW;
}

"else" {
    col_count += yyleng;
    return ELSE_KW;
}

"return" {
    col_count += yyleng;
    return RETURN_KW;
}

"crunch" {
    col_count += yyleng;
    return CRUNCH_KW;
}

    /* types */
"char" {
    col_count += yyleng;
    return CHAR_TYPE;
}

"path" {
    col_count += yyleng;
    return PATH_TYPE;
}

"string" {
    col_count += yyleng;
    return STRING_TYPE;
}

"int" {
    col_count += yyleng;
    return INT_TYPE;
}

"float" {
    col_count += yyleng;
    return FLOAT_TYPE;
}
"void" {
    col_count += yyleng;
    return VOID_TYPE;
}

        /* definition */
"+" {
col_count += yyleng;
return ADD_OP;
}
"-" {
col_count += yyleng;
return SUB_OP; }
"*" {
col_count += yyleng;
return MULT_OP; }
"/" {
col_count += yyleng;
return DIV_OP; }
"%" {
col_count += yyleng;
return REM_OP; }

"!" {
col_count += yyleng;
return NOT_OP; }

"<" {
    col_count += yyleng;
    return LESSTHAN_OP;
}
"<=" { col_count += yyleng;
return LESSEQUAL_OP; }
">" { col_count += yyleng;
return GREATERTHAN_OP; }
">=" { col_count += yyleng;
return GREATEREQUAl_OP; }
"!=" { col_count += yyleng;
return NOTEQUAL_OP; }
"==" { col_count += yyleng;
return COMPARISON_OP; }

"||" { col_count += yyleng;
return OR_OP; }
"&&" { col_count += yyleng;
return AND_OP; }

"{" { col_count += yyleng;
return LBRACE; }
"}" { col_count += yyleng;
return RBRACE; }
"[" { col_count += yyleng;
return LBRACKET; }
"]" { col_count += yyleng;
return RBRACKET; }
"(" { col_count += yyleng;
return LPARENTHESES; }
")" { col_count += yyleng;
return RPARENTHESES; }
":" { col_count += yyleng;
return COLON; }
";" { col_count += yyleng;
return SEMICOLON; }
"|" { col_count += yyleng;
return PIPE; }

"=" { col_count += yyleng;
return DEF_EQ; }
"," { col_count += yyleng;
return COMMA; }

 /* consts */

{INTEGER} {
    col_count += yyleng;
    yylval = atoi(yytext);
    return INTCONST;
}

{FLOAT} {
    col_count += yyleng;
    yysval = (char*)malloc(sizeof yytext);
    strcpy(yysval, yytext);
    return FLOATCONST;
}

{CHAR} {
    col_count += yyleng;
    yysval = (char*)malloc(sizeof yytext);
    strcpy(yysval, yytext);
    return CHARCONST;
}

{PATH} {
    col_count += yyleng;
    yysval = (char*)malloc(sizeof yytext);
    strcpy(yysval, yytext);
    return PATHCONST;
}

{STRING} {
    col_count += yyleng;
    yysval = (char*)malloc(sizeof yytext);
    strcpy(yysval, yytext);
    return STRINGCONST;
}

{SYMBOL} {
    col_count += yyleng;
    yysval = (char*)malloc(sizeof yytext);
    strcpy(yysval, yytext);
    return SYMBOL;
}

{LSMALL}({LSMALL}|{LLARGE})* {
    col_count += yyleng;
    yysval = (char*)malloc(sizeof yytext);
    strcpy(yysval, yytext);
    return valid_id();
}

{WHITECHAR}* {
    col_count += yyleng;
}

. {
    col_count += yyleng;
    int error_num = errors.error_count;
    strcpy(errors.error_msg[error_num], yytext);
    errors.at_line[error_num] = yylineno;
    errors.at_column[error_num] = col_count;
    errors.error_count++;
}

%%

int yywrap(void) {
    return 1;
}

static enum yytokentype valid_id() {
    if (yyleng <= 32) {
        return IDENTIFIER;
    } else {
        return ERR_INVALID_ID;
    }
}

int main(int argc, char **argv) {
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    int tok;
    errors.error_count = 0;

    while((tok = yylex())) {
        printf("%s", yytokenstring(tok));
        if (tok == INTCONST)
            printf(" = %d\n", yylval);
        else if (tok == FLOATCONST)
            printf(" = %s\n", yysval);
        else if (tok == PATHCONST)
            printf(" = %s\n", yysval);
        else if (tok == STRINGCONST)
            printf(" = %s\n", yysval);
        else if (tok == CHARCONST)
            printf(" = %s\n", yysval);
        else if (tok == IDENTIFIER)
            printf(" = %s\n", yysval);
        else if (tok == SYMBOL)
            printf(" = %s\n", yysval);
        else
            printf("\n");
    }

    for (int i = 0; i < errors.error_count; i++) {
        printf("Error: Unrecognized character in line %d, position %d: %s\n",
            errors.at_line[i], errors.at_column[i], errors.error_msg[i]);
    }
    print_table();
    fclose(yyin);
    yylex_destroy();
    free_table();
}
