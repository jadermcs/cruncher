#ifndef CRUNCH_H
#define CRUNCH_H

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <uthash.h>
#include <cruncher_syntax.tab.h>

#define printlexeme(type, mod) printf(((mod)==0)?"A %s at line %d: \"%s\"\n":"A %s at line %d: %s",\
                                (type), yylineno, yytext);

/* enum yytokentype { */
/*     ERR_INVALID_ID        = -1, */
/*     SYMBOL                = 2, */
/*     IDENTIFIER            = 3, */
/*     INTCONST              = 4, */
/*     FLOATCONST            = 5, */
/*     CHARCONST             = 6, */
/*     STRINGCONST           = 7, */
/*     PATHCONST             = 8, */
/*     WHILE_KW              = 9, /1* while *1/ */
/*     FOR_KW                = 10, /1* for *1/ */
/*     IN_KW                 = 11, /1* in *1/ */
/*     IF_KW                 = 12, /1* if *1/ */
/*     ELSE_KW               = 13, /1* else *1/ */
/*     CRUNCH_KW             = 14, /1* table *1/ */
/*     RETURN_KW             = 15, /1* return *1/ */
/*     CHAR_TYPE             = 18, /1* char *1/ */
/*     INT_TYPE              = 19, /1* int *1/ */
/*     FLOAT_TYPE            = 20, /1* float *1/ */
/*     STRING_TYPE           = 21, /1* string *1/ */
/*     PATH_TYPE             = 22, /1* path *1/ */
/*     VOID_TYPE             = 23, /1* void *1/ */
/*     ADD_OP                = 24, /1* + *1/ */
/*     SUB_OP                = 25, /1* - *1/ */
/*     MULT_OP               = 26, /1* * *1/ */
/*     DIV_OP                = 27, /1* / *1/ */
/*     REM_OP                = 28, /1* % *1/ */
/*     NOT_OP                = 29, /1* ! *1/ */
/*     LESSTHAN_OP           = 30, /1* < *1/ */
/*     LESSEQUAL_OP          = 31, /1* <= *1/ */
/*     GREATERTHAN_OP        = 32, /1* > *1/ */
/*     GREATEREQUAl_OP       = 33, /1* >= *1/ */
/*     NOTEQUAL_OP           = 34, /1* != *1/ */
/*     COMPARISON_OP         = 35, /1* == *1/ */
/*     OR_OP                 = 36, /1* || *1/ */
/*     AND_OP                = 37, /1* && *1/ */
/*     LBRACE                = 38, /1* { *1/ */
/*     RBRACE                = 39, /1* } *1/ */
/*     LBRACKET              = 40, /1* [ *1/ */
/*     RBRACKET              = 41, /1* ] *1/ */
/*     LPARENTHESES          = 42, /1* ( *1/ */
/*     RPARENTHESES          = 43, /1* ) *1/ */
/*     COLON                 = 44, /1* : *1/ */
/*     SEMICOLON             = 45, /1* ; *1/ */
/*     DEF_EQ                = 46, /1* = *1/ */
/*     COMMA                 = 47, /1* , *1/ */
/*     PIPE                  = 48 /1* | *1/ */
/* }; */

typedef struct {
    char error_msg[64][128];
    int error_count;
    int at_line[64];
    int at_column[64];
} lexErrors;

typedef struct {
    char id[64];
    int address;
    enum yytokentype type;
    UT_hash_handle hh;
} symbolTable;

int fileno(FILE *);

void add_table(char *, int, enum yytokentype);
void print_table();
void free_table();

const char* yytokenstring(enum yytokentype);

#endif
