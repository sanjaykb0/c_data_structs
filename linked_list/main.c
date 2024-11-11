#include <time.h>
#include <stdio.h>
#include "ll.h"

void display(struct LinkedList *ll) {
    struct Node *tmp = ll->head;
    while (tmp != NULL ){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList *lla = create_ll();

    srand(time(NULL));

    for (int i = 0; i < 10; i++) insert_at_end(lla, rand() % 100);

    display(lla);
    sort(&lla, lla->size, 1);
    display(lla);

}
