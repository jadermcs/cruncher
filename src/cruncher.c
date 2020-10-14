#include <cruncher.h>

symbolTable *s, *tmp, *symbol_table = NULL;

void add_table(char *id, int address, enum yytokentype type) {
    s = (symbolTable *)malloc(sizeof *s);
    strcpy(s->id, id);
    s->address = address;
    s->type = type;
    HASH_ADD_STR(symbol_table, id, s);
}

void print_table() {
    printf("\n\tSymbol Table\n-------------------------\nid\taddress\ttype\n");
    HASH_ITER(hh, symbol_table, s, tmp) {
        printf("%s\t%d\t%d\n", s->id, s->address, s->type);
    }

}

void free_table() {
    HASH_ITER(hh, symbol_table, s, tmp) {
        HASH_DEL(symbol_table, s);
        free(s);
    }
}

const char* yytokenstring(enum yytokentype tok_type) {
    switch(tok_type) {
        case(SYMBOL): return "SYMBOL";
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
        default: return "[Err] Unknown Token Type";
    }
}
