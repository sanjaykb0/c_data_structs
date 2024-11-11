#include "ll_core.h"

#ifndef LL_INSERT_H
#define LL_INSERT_H

// Insertion Algorithms

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


// Sorting Algorithm (Mergesort)

struct LinkedList ** split_linked_list(struct LinkedList *ll) {
    struct LinkedList ** split_ll = (struct LinkedList**)
        calloc(ll->size, sizeof(struct LinkedList)); // Splitting the linked list into n linked lists containing 1 node.

    struct Node * tmp = ll->head;
    for (int i = 0; i < ll->size; i++) {
        split_ll[i] = create_ll();
        split_ll[i]->head = create_node(tmp->data); // Occiupies n extra space — done this way to avoid pointing
                                            // to nodes that point to additional nodes.
        tmp = tmp->next;
    }

    return split_ll;
}

struct LinkedList * merge_linked_lists(struct LinkedList * ll_1, struct LinkedList *ll_2, int asc) {

    // Takes 2 linked lists and merge them in order.
    // asc = "ascending" flag — if 1, sort by ascending order else descending

    struct LinkedList * res = (struct LinkedList *) calloc(1, sizeof(struct LinkedList));
    struct Node *p1, *p2, *tmp;

    // p1 & p2 are comparison nodes which point to the heads of each linked list respectively.
    p1 = ll_1->head;
    p2 = ll_2->head;

    while (p1 != NULL && p2 != NULL) {
        // if ascending,
        //  if p1 data >= p2 data
        //      push p1 data to res
        //      point p1 to next node for comparison
        //  else
        //      push p2 data to res
        //      point p2 to next node for comparison

        if (asc == 1 ? p1->data <= p2->data : p1->data >= p2->data) {
            insert_at_end(res, p1->data);
            p1 = p1->next;
        }
        else {
            insert_at_end(res, p2->data);
            p2 = p2->next;
        }
    }

    tmp = p1 == NULL ? p2 : p1; // This is done to account for a single remainder node
                                // which occurs due to unequal list lengths.
    while (tmp != NULL) {
        // Push remainder node data onto res
        insert_at_end(res, tmp->data);
        tmp = tmp->next;
    }

    return res;
}

void sort (struct LinkedList ** ll, int size, int asc) {
    // Effectively a shallow copy operation — the initial linked list *ll is reallocated to a final, sorted list.

    struct LinkedList ** ll_split = split_linked_list(*ll);
    struct LinkedList ** cur = ll_split;
    // size in the function's logic context refers to the size of the cur pointer.

    while (size > 1) {
        int s = 0;
        int i = 0;

        for (i = 0; i < size - 1; i+=2) {
            ll_split[s] = merge_linked_lists(ll_split[i], ll_split[i + 1], asc);
            s++;
        }

        if (i < size) { // accounts for an odd size (since the quotient is rounded down after division, and i increments by 2)
            ll_split[s] = cur[i];
            s++;
        }

        cur = ll_split; // resets the cur pointer to the starting address of ** ll_split
        size = s; // size effectively is divided by 2 in every while loop.
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
