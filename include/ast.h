struct ast {
    int nodetype;
    struct ast *l;
    struct ast *r;
    char dtype;
    char *addr;
    union {
        char *str_;
        float float_;
        int int_;
        char char_;
    } value;
};

struct ast *newast(int, struct ast *, struct ast *);

void printast(struct ast *, int);

void astdict(struct ast *);
