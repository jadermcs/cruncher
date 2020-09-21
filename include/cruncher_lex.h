#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define printlexeme(type, mod) printf(((mod)==0)?"A %s at line %d: \"%s\"\n":"A %s at line %d: %s",\
                                (type), yylineno, yytext);
typedef struct {
    char error_msg[64][128];
    int error_count;
    int at_line[64];
    int at_column[64];
} lexErrors;

int fileno(FILE *stream);
