#ifndef AST_H
#define AST_H

struct ast {
    int nodetype;
    struct ast *l;
    struct ast *r;
    char dtype;
    char addr[64];
    int flag;
    union {
        char *str_;
        float float_;
        int int_;
        char char_;
    } value;
};

struct ast *newast(int, struct ast *, struct ast *);

void print_ast(struct ast *, int);

void free_ast(struct ast *);

void astdict(struct ast *);
#endif
