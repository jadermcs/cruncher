#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <uthash.h>

#define printlexeme(type, mod) printf(((mod)==0)?"A %s at line %d: \"%s\"\n":"A %s at line %d: %s",\
                                (type), yylineno, yytext);

enum types {INT=0, FLOAT, CHAR, STRING, PATH};

typedef struct {
    char error_msg[64][128];
    int error_count;
    int at_line[64];
    int at_column[64];
} lexErrors;

typedef struct {
    char id[64];
    int address;
    enum types type;
    UT_hash_handle hh;
} symbolTable;

int fileno(FILE *);

void add_table(char *, int, enum types);
void print_table();
void free_table();
