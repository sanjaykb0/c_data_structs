#include <stdlib.h>
#include "ll_core.h"
#include "ll_definitions.h"

#ifndef LL_INSERT_H
#define LL_INSERT_H

void insert_at_front(struct LinkedList *ll, int data) {
    struct Node *n = create_node(data);

    if (ll->head == NULL) {
        ll->head = n;
        ll->size = 1;
        return;
    }

    ll->head->prev = n;
    ll->head->prev->next = ll->head;
    ll->head = n;

    ll->size++;
}

void insert_at_end(struct LinkedList *ll, int data) {
    struct Node *n = create_node(data);
    n->data = data;
    n->next = NULL;

    struct Node *tmp = ll->head;

    if (ll->head == NULL) {
        ll->head = n;
        ll->size = 1;
        return;
    }

    while (tmp->next != NULL) tmp = tmp->next;

    tmp->next = n;
    n->prev = tmp;
    ll->size++;
}

void insert_at_i(struct LinkedList *ll, int data, int i) {

    if (i > ll->size) return;

    if (i == 0) {
        insert_at_front(ll, data);
        return;
    }

    struct Node *n = create_node(data);
    n->data = data;
    struct Node *Nx, *tmp;
    tmp = ll->head;

    while (i - 1 > 0) {
        tmp = tmp->next;
        i--;
    }

    Nx = tmp->next;
    tmp->next = n;
    n->next = Nx;

    ll->size++;
}

struct LinkedList ** split_linked_list(struct LinkedList *ll) {
    struct LinkedList ** split_ll = (struct LinkedList**) calloc(ll->size, sizeof(struct LinkedList));
    struct Node * tmp = ll->head;
    for (int i = 0; i < ll->size; i++) {
        split_ll[i] = create_ll();
        split_ll[i]->head = create_node(tmp->data);
        tmp = tmp->next;
    }

    return split_ll;
}

struct LinkedList * merge_linked_lists(struct LinkedList * ll_1, struct LinkedList *ll_2, int asc) {
    struct LinkedList * res = (struct LinkedList *) calloc(1, sizeof(struct LinkedList));
    struct Node *p1, *p2, *tmp;

    p1 = ll_1->head;
    p2 = ll_2->head;

    while (p1 != NULL && p2 != NULL) {
        if (asc == 1 ? p1->data <= p2->data : p1->data >= p2->data) {
            insert_at_end(res, p1->data);
            p1 = p1->next;
        }
        else {
            insert_at_end(res, p2->data);
            p2 = p2->next;
        }
    }

    tmp = p1 == NULL ? p2 : p1;
    while (tmp != NULL) {
        insert_at_end(res, tmp->data);
        tmp = tmp->next;
    }

    return res;
}

void sort (struct LinkedList ** ll, int size, int asc) {
    struct LinkedList ** ll_split = split_linked_list(*ll);
    struct LinkedList ** cur = ll_split;

    while (size > 1){
        int s = 0;
        int i = 0;

        for (i = 0; i < size - 1; i+=2) {
            ll_split[s] = merge_linked_lists(ll_split[i], ll_split[i + 1], asc);
            s++;
        }

        if (i < size) {
            ll_split[s] = cur[i];
            s++;
        }

        cur = ll_split;
        size = s;
    }

    struct LinkedList *l = create_ll();
    struct Node * tmp = cur[0]->head;

    while (tmp != NULL) {
        insert_at_end(l, tmp->data);
        tmp = tmp->next;
    }

    free(*ll_split);
    free(*ll);
    *ll = l;
}

struct Node * search(struct LinkedList *ll, int key) {
    struct Node *tmp = ll->head;
    while (tmp != NULL) {
        if (tmp->data == key) {
            break;
        }
        tmp = tmp->next;
    }

    return tmp;
}
#endif
