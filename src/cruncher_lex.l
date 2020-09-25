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

lexErrors errors;
int col_count = 1;
enum types current_type=INT;
int current_addr=0;
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
SYMBOL      [!#$%&⋆+.\\\/<=>?@^\|-~:]
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
    errors.at_line[error_num] = yylineno;
    errors.at_column[error_num] = col_count;
    errors.error_count++;
    BEGIN(INITIAL);
}

<STRING>\\\n {
    yylineno++;
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
    errors.at_line[error_num] = yylineno;
    errors.at_column[error_num] = col_count;
    errors.error_count++;
    BEGIN(INITIAL);
    yyterminate();
}
<STRINGBREAK><<EOF>> {
    int error_num = errors.error_count;
    strcpy(errors.error_msg[error_num], "Unexpected end of file while in string.");
    errors.at_line[error_num] = yylineno;
    errors.at_column[error_num] = col_count;
    errors.error_count++;
    BEGIN(INITIAL);
}

{COMMENT} {
    int size = strlen(yytext);
    yytext[size-1] = '\0';
    printlexeme("comment", 0);
    col_count = 1;
    yylineno++;
}

{NEWLINE} {
    col_count = 1;
    yylineno++;
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
    printlexeme("SPECIAL", 0);
    col_count += yyleng;
}

{SYMBOL} {
    printlexeme("SYMBOL", 0);
    col_count += yyleng;
}

{RESERVEDID} {
    printlexeme("RESERVED ID", 0);
    col_count += yyleng;
}

{RESERVEDOP} {
    printlexeme("RESERVED OP", 0);
    col_count += yyleng;
}

{VARID} {
    printlexeme("VARIABLE", 0);
    col_count += yyleng;
    add_table(yytext, current_addr, current_type);
    current_addr++;
}

{CONID} {
    printlexeme("CONSTRUCTOR", 0);
    col_count += yyleng;
}

{WHITESTUFF} {
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
    print_table();
    fclose(yyin);
    yylex_destroy();
    free_table();
}
