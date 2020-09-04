%{
/* need this for the call to atof() below */
#include <math.h>
int line_count = 1;
%}

DIGIT   [0-9]
ID      [a-z][a-z0-9\_]*
SPACE   [ \t\n]+
ASSIGN  {ID}{SPACE}<-{SPACE}{ID}|{ID}
BLOCK   ({ASSIGN}{SPACE})+

%%

-?{DIGIT}+ {
    printf("An integer: %s\n", yytext);
    line_count++;
}

-?{DIGIT}+"."{DIGIT}*([eE]-?{DIGIT}+)? {
    printf("A float: %s\n", yytext);
    line_count++;
}

{ID}(" "{ID})*" "*"="{SPACE}?{BLOCK} {
    printf("A function: %s\n", yytext);
    line_count++;
}

let|in|if|otherwise {
    printf("A keyword: %s\n", yytext);
    line_count++;
}

"--"[^\n]*\n    /*eat comments*/

{SPACE}    /*eat spaces*/

.       {
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
