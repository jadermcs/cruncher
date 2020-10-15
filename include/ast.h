struct ast {
    int nodetype;
    struct ast *l;
    struct ast *r;
    char dtype;
    char *addr;
    int string_size;

    union prop {
        char *str;
        char *func_name;
    } prop;
};

struct ast *newast(int, struct ast *, struct ast *);

void printast(struct ast *, int);

void astdict(char);
