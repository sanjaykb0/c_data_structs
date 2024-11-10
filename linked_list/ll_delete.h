
#ifndef LL_DELETE_H
#define LL_DELETE_H

void delete_at_i(struct LinkedList *ll, int i) {
    struct Node *tmp = ll->head;
    if (i > ll->size) return;
    while (i - 1 > 0) {
        i--;
        tmp = tmp->next;
    }


    struct Node *tmp2;

    if (i == 0) {
        tmp2 = ll->head;
        ll->head = tmp->next;
    } else {
        tmp2 = tmp->next;
        tmp->next = tmp->next->next;
    }

    free(tmp2);
    ll->size--;
}

#endif
