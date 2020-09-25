#include <cruncher.h>

symbolTable *s, *tmp, *symbol_table = NULL;

void add_table(char *id, int address, enum types type) {
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
