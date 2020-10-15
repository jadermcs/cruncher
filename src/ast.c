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
    if (t == NULL) return;
    else {
        for (int i = 0; i < depth; ++i) printf("--");
        astdict(t->nodetype);
        printast(t->l, depth+1);
        printast(t->r, depth+1);
    }
    return;
}

void astdict(char c) {
    switch (c) {
        case 'D':
            printf("DECLARATIONS\n");
            break;
        case 'V':
            printf("VARIABLE\n");
            break;
        case 'F':
            printf("FUNCTION\n");
            break;
        case 'P':
            printf("PARAMLIST\n");
            break;
        case 'A':
            printf("PARAM\n");
            break;
        case 'S':
            printf("INNER_DECLARATIONS\n");
            break;
        case 'I':
            printf("IDENTIFIER\n");
            break;
        case 'p':
            printf("PATHCONST\n");
            break;
        case 'c':
            printf("CHARCONST\n");
            break;
        case 'i':
            printf("INTCONST\n");
            break;
        case 's':
            printf("STRINGCONST\n");
            break;
        case 'f':
            printf("FLOATCONST\n");
            break;
        default:
            printf("UNDEFINED [%c]\n", c);
    }
}
