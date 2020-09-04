%{
/* need this for the call to atof() below */
#include <math.h>
int line_count = 0;
%}

DIGIT   [0-9]
ID      [a-z][a-z0-9]*
INT     [0-9]+

%%

-?{DIGIT}+      {
    printf("An integer: %s\n", yytext);
    line_count++;
}

-?{DIGIT}+"."{DIGIT}*([eE]-?{DIGIT}+)? {
    printf("A float: %s\n", yytext);
    line_count++;
}

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
