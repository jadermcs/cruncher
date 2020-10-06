#ifndef CRUNCH_H
#define CRUNCH_H

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <uthash.h>

#define printlexeme(type, mod) printf(((mod)==0)?"A %s at line %d: \"%s\"\n":"A %s at line %d: %s",\
                                (type), yylineno, yytext);

enum yytokentype {
    ERR_INVALID_ID        = -1,
    SYMBOL                = 2,
    IDENTIFIER            = 3,
    INTCONST              = 4,
    FLOATCONST            = 5,
    CHARCONST             = 6,
    STRINGCONST           = 7,
    PATHCONST             = 8,
    WHILE_KW              = 9, /* while */
    FOR_KW                = 10, /* for */
    IN_KW                 = 11, /* in */
    IF_KW                 = 12, /* if */
    ELSE_KW               = 13, /* else */
    CRUNCH_KW             = 14, /* table */
    RETURN_KW             = 15, /* return */
    CHAR_TYPE             = 18, /* char */
    INT_TYPE              = 19, /* int */
    FLOAT_TYPE            = 20, /* float */
    STRING_TYPE           = 21, /* string */
    PATH_TYPE             = 22, /* path */
    VOID_TYPE             = 23, /* void */
    ADD_OP                = 24, /* + */
    SUB_OP                = 25, /* - */
    MULT_OP               = 26, /* * */
    DIV_OP                = 27, /* / */
    REM_OP                = 28, /* % */
    NOT_OP                = 29, /* ! */
    LESSTHAN_OP           = 30, /* < */
    LESSEQUAL_OP          = 31, /* <= */
    GREATERTHAN_OP        = 32, /* > */
    GREATEREQUAl_OP       = 33, /* >= */
    NOTEQUAL_OP           = 34, /* != */
    COMPARISON_OP         = 35, /* == */
    OR_OP                 = 36, /* || */
    AND_OP                = 37, /* && */
    LBRACE                = 38, /* { */
    RBRACE                = 39, /* } */
    LBRACKET              = 40, /* [ */
    RBRACKET              = 41, /* ] */
    LPARENTHESES          = 42, /* ( */
    RPARENTHESES          = 43, /* ) */
    COLON                 = 44, /* : */
    SEMICOLON             = 45, /* ; */
    DEF_EQ                = 46, /* = */
    COMMA                 = 47, /* , */
    PIPE                  = 48 /* | */
};

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
