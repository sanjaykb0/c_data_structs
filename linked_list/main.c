#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "ll_headers.h"

int main() {
    struct LinkedList *lla = create_ll();

    srand(time(NULL));

    for (int i = 0; i < 10; i++) insert_at_end(lla, rand() % 100);

    printf("\n");

    display(lla);
    sort(&lla, lla->size, 1);
    display(lla);

}
