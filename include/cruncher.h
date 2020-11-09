#ifndef CRUNCH_H
#define CRUNCH_H

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <uthash.h>
#include <utstack.h>
#include <cruncher_syntax.tab.h>

#define printlexeme(type, mod) printf(((mod)==0)?"A %s at line %d: \"%s\"\n":"A %s at line %d: %s",\
                                (type), yylineno, yytext);

typedef struct {
    char id[64];
    char type;
    char dtype;
    char scope[64];
    UT_hash_handle hh;
} symbolTable;

typedef struct addr_stack {
    char *id;
    struct addr_stack *next;
} addr_stack;

typedef struct st_stack {
    symbolTable *st;
    struct st_stack *next;
} st_stack;

int fileno(FILE *);

void push_addr(char *);
char *pop_addr();
void push_st();
void add_table(char *, char, char, char *);
void print_table();
void free_table();
int type_match(char, char);
void error_type();
void error_scope();

const char* yytokenstring(enum yytokentype);

symbolTable *find_symbol(char *);
extern char* strdup(const char*);

#endif
