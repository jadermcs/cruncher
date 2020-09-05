%{
#include <math.h>
int col_count = 1, line_count = 1;
%}

PROGRAM     {LEXEME}|{WHITESPACE}
LEXEME      RESERVEDID|VARID|CONID|LITERAL|SPECIAL|RESERVEDOP
LITERAL     INTEGER|FLOAT|CHAR|STRING
SPECIAL     [\(\),;\[\]`\{\}]

WHITESPACE  {WHITESTUFF}+
WHITESTUFF  {WHITECHAR}|{COMMENT}
WHITECHAR   {NEWLINE}|\t|" "
COMMENT     --[^\n]*{NEWLINE}
NEWLINE     \n

DIGIT       [0-9]
INTEGER     [+-]?{DIGIT}+
FLOAT       {INTEGER}"."{DIGIT}*{EXPON}?
EXPON       [eE]?[-+]?{DIGIT}+

LSMALL      [a-z]|_
LLARGE      [A-Z]
SYMBOL      [!#$%&⋆+.\/<=>?@\\^\|-~:]
GRAPHIC     [{LSMALL}{LLARGE}{SYMBOL}]
CHAR        \'{GRAPHIC}\'
STRING      \"{GRAPHIC}*\"

RESERVEDID  case|class|data|default|deriving|do|else|foreign|if|import|in|infix|infixl|infixr|instance|let|module|newtype|of|then|type|where
VARID       {LSMALL}({LSMALL}|{LLARGE}|{DIGIT})*
CONID       {LLARGE}({LSMALL}|{LLARGE}|{DIGIT})*
RESERVEDOP  \.\.|:|::|=|\\|\||<-|->|@|~|=>

%%

{COMMENT} {
    printf("A comment: %s at line %d\n", yytext, line_count);
    col_count = 1;
    line_count++;
}

{WHITESTUFF} {
    col_count = 1;
    line_count++;
}

{INTEGER} {
    printf("An integer: %s at line %d\n", yytext, line_count);
    col_count += yyleng;
}

{FLOAT} {
    printf("A float: %s at line %d\n", yytext, line_count);
    col_count += yyleng;
}

{CHAR} {
    printf("A float: %s at line %d\n", yytext, line_count);
    col_count += yyleng;
}

{STRING} {
    printf("A float: %s at line %d\n", yytext, line_count);
    col_count += yyleng;
}

{SPECIAL} {
    printf("A special: %s at line %d\n", yytext, line_count);
    col_count += yyleng;
}

{SYMBOL} {
    printf("A symbol: %s at line %d\n", yytext, line_count);
    col_count += yyleng;
}

{RESERVEDID} {
    printf("A reserved id: %s at line %d\n", yytext, line_count);
    col_count += yyleng;
}

{RESERVEDOP} {
    printf("A reserved operation: %s at line %d\n", yytext, line_count);
    col_count += yyleng;
}

{VARID} {
    printf("A variable: %s at line %d\n", yytext, line_count);
    col_count += yyleng;
}

. {
    printf("Unrecognized character in line %d, position %d: %s\n", line_count, yyleng, yytext);
    return 1;
}

%%

int main(int argc, char **argv) {
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    yylex();
}
