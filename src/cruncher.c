#include <cruncher.h>

symbolTable *symbol_table = NULL;
addrStack *head = NULL;
labelStack *lhead = NULL;
tacCode *tac_code = NULL;
tacCode *tac_table = NULL;
extern int yylineno;
extern int yyleng;
extern int has_error;
extern int label_counter;
extern int addr_counter;
extern int var_counter;

void add_symbol(char *id, char type, char dtype, char *symbol) {
    symbolTable *s;
    HASH_FIND_STR(symbol_table, id, s);
    if (s == NULL) {
        s = (symbolTable *)malloc(sizeof *s);
        strcpy(s->id, id);
        s->type = type;
        s->dtype = dtype;
        strcpy(s->symbol, symbol);
        HASH_ADD_STR(symbol_table, id, s);
    }
    else {
        fprintf(stderr, "[ERROR] conflict types %d.\n", yylineno);
        has_error = 1;
    }
}

void add_table(char *id, char type, char dtype) {
    addrStack *a_stack = (addrStack *)malloc(sizeof *a_stack);
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
    symbolTable *s, *tmp;
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
    symbolTable *s, *tmp2;
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
        case(LESSEQUAL_OP): return "LESSEQUAL_OP";
        case(GREATEREQUAl_OP): return "GREATEREQUAl_OP";
        case(NOTEQUAL_OP): return "NOTEQUAL_OP";
        case(COMPARISON_OP): return "COMPARISON_OP";
        case(OR_OP): return "OR_OP";
        case(AND_OP): return "AND_OP";
        case(TYPE): return "TYPE";
        case(CRUNCH_OP): return "CRUNCH_OP";
        default: return "[Err] Unknown Token Type";
    }
}

int type_match(char f_dtype, char s_dtype) {
    if (f_dtype == s_dtype) return 0;
    else return 1;
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

void error_type(char l, char r) {
    fprintf(stderr, "[ERROR] type error in line %d, ltype:%c rtype:%c.\n", yylineno, l, r);
    has_error = 1;
}

void error_scope() {
    fprintf(stderr, "[ERROR] undefined symbol in line %d.\n", yylineno);
    has_error = 1;
}

void gen0(char *op) {
    gen_macro("%s\n", op);
}

void gen1(char *op, char *t1) {
    gen_macro("%s %s\n", op, t1);
}

void gen2(char *op, char *t1, char *t2) {
    gen_macro("%s %s %s\n", op, t1, t2);
}

void gen3(char *op, char *t1, char *t2, char *t3) {
    gen_macro("%s %s %s %s\n", op, t1, t2, t3);
}

void gen_label(char *id) {
    gen_macro("%s:\n", id);
}

void gen_fmt(char *fmt) {
    gen_macro("%s", fmt);
}

void gen_var(char *type, char *id, char *value) {
    tacCode *instruction = (tacCode *)malloc(sizeof *instruction);
    utstring_new(instruction->code);
    int size = strlen(value);
    if (!strcmp(type, "char") && size > 1) {
        utstring_printf(instruction->code, "%s %s[%d] = {", type, id, size-2);
        for (int i = 0; i < size-2; i++)
            utstring_printf(instruction->code, "'%c'%s", value[i+1],
                (size==i+3)?"":", ");
        utstring_printf(instruction->code, "}\n");
        
    }
    else utstring_printf(instruction->code, "%s %s = %s\n", type, id, value);
    DL_APPEND(tac_table, instruction);
}

void new_label(char *dest) {
    UT_string *tmp;
    utstring_new(tmp);
    utstring_printf(tmp, "L%d", label_counter);
    label_counter++;
    strcpy(dest, utstring_body(tmp));
    utstring_free(tmp);
}

void new_var(char *dest) {
    UT_string *tmp;
    utstring_new(tmp);
    utstring_printf(tmp, "var%d", var_counter);
    var_counter++;
    strcpy(dest, utstring_body(tmp));
    utstring_free(tmp);
}

void new_addr(char *dest) {
    UT_string *tmp;
    utstring_new(tmp);
    utstring_printf(tmp, "$%d", addr_counter);
    addr_counter++;
    strcpy(dest, utstring_body(tmp));
    utstring_free(tmp);
}

void print_tac() {
    tacCode *item2, *tmp2;
    FILE *fp = fopen("output.tac", "w");
    if (has_error){
        printf("Can't generate TAC, code has errors.");
        return;
    }
    fprintf(fp, ".table\n");
    DL_FOREACH_SAFE(tac_table, item2, tmp2) {
        fprintf(fp, "%s", utstring_body(item2->code));
    }

    fprintf(fp, "\n.code\n");
    DL_FOREACH_SAFE(tac_code, item2, tmp2) {
        fprintf(fp, "%s", utstring_body(item2->code));
    }
   fclose(fp);
   printf("TAC printed to 'output.tac'.");
}

void free_tac() {
    tacCode *item2, *tmp2;
    DL_FOREACH_SAFE(tac_code, item2, tmp2) {
        DL_DELETE(tac_code, item2);
        utstring_free(item2->code);
        free(item2);
    }
}