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
        case(WHILE_KW): return "WHILE_KW";
        case(FOR_KW): return "FOR_KW";
        case(IN_KW): return "IN_KW";
        case(IF_KW): return "IF_KW";
        case(ELSE_KW): return "ELSE_KW";
        case(RETURN_KW): return "RETURN_KW";
        case(CRUNCH_KW): return "CRUNCH_KW";
        case(CHAR_TYPE): return "CHAR_TYPE";
        case(INT_TYPE): return "INT_TYPE";
        case(FLOAT_TYPE): return "FLOAT_TYPE";
        case(STRING_TYPE): return "STRING_TYPE";
        case(PATH_TYPE): return "PATH_TYPE";
        case(VOID_TYPE): return "VOID_TYPE";
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
        case(LBRACE): return "LBRACE";
        case(RBRACE): return "RBRACE";
        case(LBRACKET): return "LBRACKET";
        case(RBRACKET): return "RBRACKET";
        case(LPARENTHESES): return "LPARENTHESES";
        case(RPARENTHESES): return "RPARENTHESES";
        case(COLON): return "COLON";
        case(SEMICOLON): return "SEMICOLON";
        case(DEF_EQ): return "DEF_EQ";
        case(COMMA): return "COMMA";
        case(PIPE): return "PIPE";
        default: return "[Err] Unknown Token Type";
    }
}
