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

void print_ast(struct ast *t, int depth) {
    if (t == NULL) return;
    for (int i = 0; i < depth; ++i) printf("--");
    astdict(t);
    print_ast(t->l, depth+1);
    print_ast(t->r, depth+1);
    return;
}

void free_ast(struct ast *t) {
    if (t == NULL) return;
    free_ast(t->l);
    free_ast(t->r);
    switch (t->nodetype) {
        case 'C':
        case 's':
        case 'p':
            free(t->value.str_);
            break;
        case 'c':
            if (t->dtype == 'p' || t->dtype == 's') free(t->value.str_);
            break;
    }
    free(t);
    return;
}

struct ast *convert_to(struct ast *t, char type) {
    if (t == NULL) return NULL;
    if (t->nodetype == 'c'){
        if (t->dtype == type) return t;
        else {
            struct ast *tmp = newast('K', t, NULL);
            tmp->dtype = type;
            return tmp;
        }
    }
    else {
        t->l = convert_to(t->l, type);
        t->r = convert_to(t->r, type);
        t->dtype = type;
        return t;
    }
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
            if (t->value.str_)
                printf("CRUNCHER (dtype:%c options:%s)\n",t->dtype, t->value.str_);
            else
                printf("CRUNCHER (dtype:%c options:%s)\n",t->dtype, "NONE");
            break;
        case 'L':
            printf("LOOPSTMT (dtype:%c)\n", t->dtype);
            break;
        case 'R':
            printf("RELATIONEXP (dtype:%c)\n", t->dtype);
            break;
        case '=':
            printf("ASSIGNMENT (dtype:%c)\n", t->dtype);
            break;
        case 'B':
            printf("BOOLEXP\n");
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
        case 'c':
            printf("CONST (dtype:%c)\n", t->dtype);
            break;
        case 'Z':
            printf("ARITHMETICEXP (dtype:%c)\n", t->dtype);
            break;
        case 'K':
            printf("CONVERTIONNODE (dtype:%c)\n", t->dtype);
            break;
        default:
            printf("UNDEFINED [%c]\n", t->nodetype);
            break;
    }
    return;
}
