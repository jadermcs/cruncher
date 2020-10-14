#include <stdlib.h>
#include "ast.h"
#include "cruncher.h"

extern void yyerror(const char *s);

struct ast *newast(int nodetype, struct ast *l, struct ast *r) {
    struct ast *a = malloc(sizeof(struct ast));

    if(!a) {
        yyerror("out of space");
        exit(0);
    }

    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
    return a;
}

void printast(struct ast *t, int depth) {
    for (int i = 0; i < depth*2; ++i) printf("-");
    if (t == NULL)
        printf(".\n");
    else {
        printf("%c\n", t->nodetype);
        printast(t->l, depth+1);
        printast(t->r, depth+1);
    }
    return;
}
