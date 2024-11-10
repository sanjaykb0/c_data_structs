#include <stdlib.h>
#include <stdio.h>

#ifndef NODE_H
#define NODE_H

union Value {
    int i;
    float f;
    char c;
    char *s;
};

struct Node {
    struct Node *next;
    struct Node *prev;
    union Value value;
};

struct Node *init_node(union Value value) {
    struct Node *root = (struct Node *)calloc(1, sizeof(struct Node));
    root->value = value;
    root->prev = NULL;
    root->next = NULL;
    return root;
}

struct Node *def_node(struct Node *prev, union Value value) {
    if (prev == NULL) {
        return init_node(value);
    }

    struct Node *n = (struct Node *)calloc(1, sizeof(struct Node));
    n->value = value;
    n->prev = prev;
    n->prev->next = n;
    return n;
}

#endif
