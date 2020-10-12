struct ast {
    int nodetype;
    struct ast *l;
    struct ast *r;
    char dtype;
    char *addr;
    int string_size;

    union {
        char *string;
        char *func_name;
    };
};

struct ast *newast(int, struct ast *, struct ast *);
