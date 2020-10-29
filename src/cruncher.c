#include <cruncher.h>

symbolTable *s, *tmp, *symbol_table = NULL;
addr_stack *a_stack = NULL;
st_stack *s_stack = NULL;

void add_table(char *id, char *type) {
    s = (symbolTable *)malloc(sizeof *s);
    strcpy(s->id, id);
    strcpy(s->type, type);
    HASH_ADD_STR(symbol_table, id, s);
}

void push_addr(char *id) {
    addr_stack *item = malloc(sizeof *item);
    item->id = (char *)strdup(id);
    STACK_PUSH(a_stack, item);
}

void push_st() {
    st_stack *item = malloc(sizeof *item);
    item->st = symbol_table;
    STACK_PUSH(s_stack, item);
    symbol_table = NULL;
}

void print_table() {
    printf("\n\tSymbol Table\n==============================\n%-10s\ttype\tscope\n", "id");
    printf("------------------------------\n");
    st_stack *item;
    addr_stack *item2;
    while (!STACK_EMPTY(s_stack)) {
        STACK_POP(s_stack, item);
        STACK_POP(a_stack, item2);
        HASH_ITER(hh, item->st, s, tmp) {
            printf("%-10s\t%s\t%s\n", s->id, s->type, item2->id);
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
    }
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
