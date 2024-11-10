#include <stdio.h>
#include "queue.h"

int main() {
    struct Queue *q = init_queue(5);
    union Value v;

    v.i = 0;
    for (int i = 0; i < 5; i++) {
        v.i = i;
        enqueue(q, v);
    }

    display(q);
}
