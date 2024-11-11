#include <stdlib.h>

#ifndef LL_CORE_H
#define LL_CORE_H

struct Node {
    struct Node *next;
    struct Node *prev;
    int data;
};

struct LinkedList {
    struct Node *head;
    int size;
};

struct Node * create_node(int data) {
    struct Node *n = (struct Node * ) calloc(1, sizeof(struct Node));
    n->data = data;
    return n;
}

struct LinkedList * create_ll() {
    struct LinkedList *ll = (struct LinkedList *) calloc(1, sizeof(struct LinkedList));
    ll->head = NULL;
    return ll;
}

#endif
