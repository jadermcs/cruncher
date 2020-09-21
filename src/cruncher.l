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
%option outfile="src/cruncher_lex.c" header-file="include/cruncher_lex.h"

%{
#include <math.h>
#define printlexeme(type, mod) printf(((mod)==0)?"A %s at line %d: \"%s\"\n":"A %s at line %d: %s",\
                                (type), line_count, yytext);
typedef struct {
    char error_msg[64][128];
    int error_count;
    int at_line[64];
    int at_column[64];
} lexErrors;

lexErrors errors;
int col_count = 1, line_count = 1;
%}

%x          STRING
%x          STRINGBREAK

PROGRAM     ({LEXEME}|{WHITESPACE})*
LEXEME      RESERVEDID|VARID|CONID|LITERAL|SPECIAL|RESERVEDOP
LITERAL     INTEGER|FLOAT|CHAR|STRING
SPECIAL     [(),;\[\]{}]

WHITESPACE  {WHITESTUFF}+
WHITESTUFF  {WHITECHAR}|{COMMENT}
WHITECHAR   {NEWLINE}|\t|" "
COMMENT     --[^\n]*{NEWLINE}
NEWLINE     \n

DIGIT       [0-9]
INTEGER     [+-]?{DIGIT}
FLOAT       {INTEGER}"."{DIGIT}*{EXPON}?
EXPON       [eE]{INTEGER}

LSMALL      [a-z]|_
LLARGE      [A-Z]
SYMBOL      [!#$%&⋆+.\\\/<=>?@^\|-~: ]
GRAPHIC     [{LSMALL}{LLARGE}{SYMBOL}{WHITECHAR}]
CHAR        \'{GRAPHIC}\'
PATH        [\._][{LLARGE}{LSMALL}\/\.]+

RESERVEDID  case|class|data|default|deriving|do|else|foreign|if|import|in|infix|infixl|infixr|instance|let|module|newtype|of|then|type|where|like
VARID       {LSMALL}({LSMALL}|{LLARGE}|{DIGIT})*
CONID       {LLARGE}({LSMALL}|{LLARGE}|{DIGIT})*
RESERVEDOP  \.\.|:|::|=|\\|\||<-|->|@|~|=>

FUNCTION    ({VARID}::{CONID}(->{CONID})+)?{NEWLINE}{VARID}

%%

\" {
    printlexeme("string", 1);
    col_count += yyleng;
    BEGIN(STRING);
}

<STRING>\" {
    printf("%s\n", yytext);
    col_count += yyleng;
    BEGIN(INITIAL);
}

<STRING>[^\\\n] {
    printf("%s", yytext);
    col_count += yyleng;
}

<STRING>\n {
    printf("[ERROR]\n");
    int error_num = errors.error_count;
    strcpy(errors.error_msg[error_num], "Unexpected linebreak while in string.");
    errors.at_line[error_num] = line_count;
    errors.at_column[error_num] = col_count;
    errors.error_count++;
    BEGIN(INITIAL);
}

<STRING>\\\n {
    line_count++;
    col_count += yyleng;
    BEGIN(STRINGBREAK);
}

<STRINGBREAK>{WHITESPACE}*\\ {
    col_count += yyleng;
    BEGIN(STRING);
}

<STRING><<EOF>> {
    int error_num = errors.error_count;
    strcpy(errors.error_msg[error_num], "Unexpected end of file while in string.");
    errors.at_line[error_num] = line_count;
    errors.at_column[error_num] = col_count;
    errors.error_count++;
    BEGIN(INITIAL);
    yyterminate();
}
<STRINGBREAK><<EOF>> {
    int error_num = errors.error_count;
    strcpy(errors.error_msg[error_num], "Unexpected end of file while in string.");
    errors.at_line[error_num] = line_count;
    errors.at_column[error_num] = col_count;
    errors.error_count++;
    BEGIN(INITIAL);
}

{COMMENT} {
    int size = strlen(yytext);
    yytext[size-1] = '\0';
    printlexeme("comment", 0);
    col_count = 1;
    line_count++;
}

{NEWLINE} {
    col_count = 1;
    line_count++;
}

{INTEGER} {
    printlexeme("integer", 0);
    col_count += yyleng;
}

{FLOAT} {
    printlexeme("float", 0);
    col_count += yyleng;
}

{CHAR} {
    printlexeme("char", 0);
    col_count += yyleng;
}

{SPECIAL} {
    printlexeme("special", 0);
    col_count += yyleng;
}

{SYMBOL} {
    printlexeme("symbol", 0);
    col_count += yyleng;
}

{RESERVEDID} {
    printlexeme("reserved id", 0);
    col_count += yyleng;
}

{RESERVEDOP} {
    printlexeme("reserved op", 0);
    col_count += yyleng;
}

{VARID} {
    printlexeme("variable", 0);
    col_count += yyleng;
}

{CONID} {
    printlexeme("constructor", 0);
    col_count += yyleng;
}

{WHITESTUFF} {
    col_count += yyleng;
}

. {
    col_count += yyleng;
    int error_num = errors.error_count;
    strcpy(errors.error_msg[error_num], yytext);
    errors.at_line[error_num] = line_count;
    errors.at_column[error_num] = col_count;
    errors.error_count++;
}

%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    errors.error_count = 0;

    yylex();

    for (int i = 0; i < errors.error_count; i++) {
        printf("Error: Unrecognized character in line %d, position %d: %s\n",
            errors.at_line[i], errors.at_column[i], errors.error_msg[i]);
    }
}
