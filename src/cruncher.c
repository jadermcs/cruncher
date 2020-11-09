#include <cruncher.h>

symbolTable *s, *tmp, *symbol_table = NULL;
addr_stack *a_stack = NULL;
extern int yylineno;
extern int yyleng;
extern int has_error;
st_stack *s_stack = NULL;

void add_table(char *id, char type, char dtype, char *scope) {
    s = (symbolTable *)malloc(sizeof *s);
    strcpy(s->id, id);
    strcpy(s->scope, scope);
    s->type = type;
    s->dtype = dtype;
    HASH_ADD_STR(symbol_table, id, s);
}

void push_addr(char *id) {
    addr_stack *item = malloc(sizeof *item);
    item->id = (char *)strdup(id);
    STACK_PUSH(a_stack, item);
}

char *pop_addr() {
    addr_stack *item = malloc(sizeof *item);
    STACK_POP(a_stack, item);
    return item->id;
}

void push_st() {
    st_stack *item = malloc(sizeof *item);
    item->st = symbol_table;
    STACK_PUSH(s_stack, item);
    symbol_table = NULL;
}

void print_table() {
    printf("\n\tSymbol Table\n==============================\n%-10s\ttype\tdtype\tscope\n", "id");
    printf("------------------------------\n");
    st_stack *item;
    addr_stack *item2;
    int has_main = 0;
    while (!STACK_EMPTY(s_stack)) {
        STACK_POP(s_stack, item);
        STACK_POP(a_stack, item2);
        if (strcmp(item2->id, "main") == 0)
            has_main = 1;
        HASH_ITER(hh, item->st, s, tmp) {
            if (strcmp(item2->id, s->id) == 0)
                printf("%-10s\t%c\t%c\t%s\n", s->id, s->type, s->dtype, "global");
            else
                printf("%-10s\t%c\t%c\t%s\n", s->id, s->type, s->dtype, item2->id);
        }
        // Clean table
        HASH_ITER(hh, item->st, s, tmp) {
            HASH_DEL(item->st, s);
            free(s);
        }
        free(item->st);
        free(item);
        free(item2->id);
        free(item2);
        printf("------------------------------\n");
    }
    printf("has_main: %d\n", has_main);
}

void free_table() {
}

const char* yytokenstring(enum yytokentype tok_type) {
    switch(tok_type) {
        case(IDENTIFIER): return "IDENTIFIER";
        case(INTCONST): return "INTCONST";
        case(FLOATCONST): return "FLOATCONST";
        case(CHARCONST): return "CHARCONST";
        case(STRINGCONST): return "STRINGCONST";
        case(PATHCONST): return "PATHCONST";
        case(WHILE): return "WHILE";
        case(FOR): return "FOR";
        case(IN): return "IN";
        case(IF): return "IF";
        case(ELSE): return "ELSE";
        case(RETURN): return "RETURN";
        case(CRUNCH): return "CRUNCH";
        case(ADD_OP): return "ADD_OP";
        case(SUB_OP): return "SUB_OP";
        case(MULT_OP): return "MULT_OP";
        case(DIV_OP): return "DIV_OP";
        case(REM_OP): return "REM_OP";
        case(NOT_OP): return "NOT_OP";
        case(LESSTHAN_OP): return "LESSTHAN_OP";
        case(LESSEQUAL_OP): return "LESSEQUAL_OP";
        case(GREATERTHAN_OP): return "GREATERTHAN_OP";
        case(GREATEREQUAl_OP): return "GREATEREQUAl_OP";
        case(NOTEQUAL_OP): return "NOTEQUAL_OP";
        case(COMPARISON_OP): return "COMPARISON_OP";
        case(OR_OP): return "OR_OP";
        case(AND_OP): return "AND_OP";
        case(COLON): return "COLON";
        case(DEF_EQ): return "DEF_EQ";
        case(PIPE): return "PIPE";
        case(TYPE): return "TYPE";
        case(CRUNCH_OP): return "CRUNCH_OP";
        default: return "[Err] Unknown Token Type";
    }
}

int type_match(char f_dtype, char s_dtype) {
    switch (f_dtype) {
        case 'i':
            if (s_dtype == 'i' || s_dtype == 'f' || s_dtype == 'c') return 1;
            else return 0;
        case 'f':
            if (s_dtype == 'i' || s_dtype == 'f' || s_dtype == 'c') return 1;
            else return 0;
        default:
            return 0;
    }
}

symbolTable *find_symbol(char *key) {
    symbolTable *s;
    HASH_FIND_STR(symbol_table, key, s);
    return s;
}

void error_type() {
    fprintf(stderr, "[ERROR] type error in line %d.\n", yylineno);
    has_error = 1;
}

void error_scope() {
    fprintf(stderr, "[ERROR] undefined symbol in line %d.\n", yylineno);
    has_error = 1;
}
