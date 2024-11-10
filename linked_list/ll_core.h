#include <stdlib.h>
#include <stdio.h>
#include "ll_definitions.h"

#ifndef LL_CORE_H
#define LL_CORE_H

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

void display(struct LinkedList *ll) {
    struct Node *tmp = ll->head;
    while (tmp != NULL ){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void swap_nodes(struct LinkedList *ll, struct Node *a, struct Node *b) {
    if (a == NULL || b == NULL) return;

    struct Node *p, *q, *r, *s;

    p = a->prev;
    q = a->next;
    r = b->prev;
    s = b->next;

    b->next = q;
    b->prev = p;
    if (a == ll->head) ll->head = b;

    if (p != NULL) p->next = b;
    if (q != NULL) q->prev = b;

    a->next = s;
    a->prev = r;

    if (r != NULL) r->next = a;
    if (s != NULL) s->prev = a;
}

#endif
