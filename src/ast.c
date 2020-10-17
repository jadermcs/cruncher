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
        astdict(t);
        printast(t->l, depth+1);
        printast(t->r, depth+1);
    }
    return;
}

void astdict(struct ast *t) {
    switch (t->nodetype) {
        case 'D':
            printf("DECLARATIONS\n");
            break;
        case 'V':
            printf("VARIABLE\n");
            break;
        case 'F':
            printf("FUNCTION\n");
            break;
        case 'J':
            printf("JUMP (dtype:%c)\n", t->dtype);
            break;
        case 'E':
            printf("SELECTION (dtype:%c)\n", t->dtype);
            break;
        case 'H':
            printf("EXPRESSION (dtype:%c)\n", t->dtype);
            break;
        case 'C':
            printf("CRUNCHER (dtype:%c options:%s)\n",t->dtype, t->value.str_ ? t->value.str_ : "NONE");
            break;
        case 'L':
            printf("LOOPSTMT (dtype:%c)\n", t->dtype);
            break;
        case 'R':
            printf("RELATIONEXP (dtype:%c)\n", t->dtype);
            break;
        case '=':
            printf("ASSIGNMENT\n");
            break;
        case 'G':
            printf("ARGS\n");
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
        case 'T':
            printf("FCALL\n");
            break;
        case 'I':
            printf("IDENTIFIER (id:%s)\n", t->addr);
            break;
        case 'p':
            printf("PATHCONST (value:%s dtype:%c)\n", t->value.str_, t->dtype);
            break;
        case 'c':
            printf("CHARCONST\n");
            break;
        case 'i':
            printf("INTCONST (value:%d)\n", t->value.int_);
            break;
        case 's':
            printf("STRINGCONST (value:%s)\n", t->value.str_);
            break;
        case 'f':
            printf("FLOATCONST\n");
            break;
        case '+':
            printf("ADDITIVEXP (dtype:%c)\n", t->dtype);
            break;
        case '*':
            printf("MULTIPLICATIVEXP (dtype:%c)\n", t->dtype);
            break;
        default:
            printf("UNDEFINED [%c]\n", t->nodetype);
    }
}
