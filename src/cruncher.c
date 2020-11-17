#include <cruncher.h>

symbolTable *s, *symbol_table = NULL;
addrStack *a_stack, *head = NULL;
extern int yylineno;
extern int yyleng;
extern int has_error;

void add_symbol(char *id, char type, char dtype) {
    s = (symbolTable *)malloc(sizeof *s);
    strcpy(s->id, id);
    s->type = type;
    s->dtype = dtype;
    HASH_ADD_STR(symbol_table, id, s);
}

void add_table(char *id, char type, char dtype) {
    a_stack = (addrStack *)malloc(sizeof *a_stack);
    strcpy(a_stack->id, id);
    a_stack->type = type;
    a_stack->dtype = dtype;
    a_stack->st = symbol_table;
    DL_APPEND(head, a_stack);
    symbol_table = NULL;
}

void print_table() {
    printf("\n\tSymbol Table\n==============================\n%-10s\ttype\tdtype\tscope\n", "id");
    printf("------------------------------\n");
    addrStack *item;
    symbolTable *tmp;
    int has_main = 0;
    DL_FOREACH(head, item) {
        if (strcmp(item->id, "main") == 0 && item->type == 'F')
            has_main++;
        printf("%-10s\t%c\t%c\t%s\n", item->id, item->type, item->dtype, "global");
        HASH_ITER(hh, item->st, s, tmp) {
                printf("%-10s\t%c\t%c\t%s\n", s->id, s->type, s->dtype, item->id);
        }
        printf("------------------------------\n");
    }
    if (has_main == 1)
        printf("Has a valid main function.\n");
    else {
        printf("Has an invalid main definition, %s.\n", has_main>1?"multiple mains":"no main definition");
        has_error = 1;
    }
}

void free_table() {
    addrStack *item, *tmp;
    symbolTable *tmp2;
    DL_FOREACH_SAFE(head, item, tmp) {
        HASH_ITER(hh, item->st, s, tmp2) {
            HASH_DEL(item->st, s);
            free(s);
        }
        DL_DELETE(head, item);
        free(item);
    }
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

int compareid(addrStack *a, addrStack *b) {
    return strcmp(a->id, b->id);
}

symbolTable *find_symbol(char *key) {
    symbolTable *tmp;
    addrStack *item, etmp;
    strcpy(etmp.id, key);
    HASH_FIND_STR(symbol_table, key, tmp);
    if (tmp == NULL) {
        DL_SEARCH(head, item, &etmp, compareid);
        if (!item) {
            return NULL;
        }
        else {
            tmp = malloc(sizeof tmp);
            strcpy(tmp->id, item->id);
            tmp->type = item->type;
            tmp->dtype = item->dtype;
        }
    }
    return tmp;
}

void error_type() {
    fprintf(stderr, "[ERROR] type error in line %d.\n", yylineno);
    has_error = 1;
}

void error_scope() {
    fprintf(stderr, "[ERROR] undefined symbol in line %d.\n", yylineno);
    has_error = 1;
}
