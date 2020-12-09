#ifndef CRUNCH_H
#define CRUNCH_H

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <uthash.h>
#include <utstack.h>
#include <utlist.h>
#include <utstring.h>
#include <cruncher_syntax.tab.h>

#define printlexeme(type, mod) \
        printf(((mod)==0)?"A %s at line %d: \"%s\"\n":"A %s at line %d: %s", \
        (type), yylineno, yytext);

#define gen_macro(fmt, ...) \
        tacCode *instruction = (tacCode *)malloc(sizeof *instruction); \
        utstring_new(instruction->code); \
        utstring_printf(instruction->code, fmt, ##__VA_ARGS__); \
        DL_APPEND(tac_code, instruction);

typedef struct {
    char id[64];
    char type;
    char dtype;
    UT_hash_handle hh;
} symbolTable;

typedef struct addrStack {
    char id[64];
    char type;
    char dtype;
    symbolTable *st;
    struct addrStack *prev, *next;
} addrStack;

typedef struct tacCode {
    UT_string *code;
    struct tacCode *prev, *next;
} tacCode;

int fileno(FILE *);

void add_symbol(char *, char, char);
void add_table(char *, char, char);
void print_table();
void free_table();
int type_match(char, char);
void error_type(char, char);
void error_scope();

const char *yytokenstring(enum yytokentype);

symbolTable *find_symbol(char *);
extern char *strdup(const char*);

void gen0(char *);
void gen1(char *, char *);
void gen2(char *, char *, char *);
void gen3(char *, char *, char *, char *);
void gen_label(char *);

void print_tac();
#endif