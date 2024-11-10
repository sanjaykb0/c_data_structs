#include "../node.h"

#ifndef QUEUE_H
#define QUEUE_H

struct Queue {
    struct Node *head;
    struct Node *top;
    size_t max_size;
    size_t cur_size;
};

struct Queue *init_queue(int max_size) {
    struct Queue *q = (struct Queue *) calloc(1, sizeof(struct Queue));
    q->head = NULL;
    q->top = q->head;
    q->max_size = max_size;
    q->cur_size = 0;

    return q;
}

void enqueue(struct Queue *queue, union Value v) {
    if (queue->cur_size == queue->max_size) {
        printf("QUEUE OVERFLOW!\n");
        return;
    }


    struct Node *n = (struct Node*) calloc(1, sizeof(struct Node));
    n->value = v;

    if (queue->head == NULL) {
        queue->head = n;
        queue->top = queue->head;
        queue->head->next = NULL;
        queue->head->prev = NULL;
        queue->cur_size++;
        return;
    }

    queue->top->next = n;
    n->prev = queue->top;
    queue->top = queue->top->next;
    queue->top->next = NULL;
    queue->cur_size++;
}

void dequeue(struct Queue * q) {
    if (q->cur_size == 0) {
        printf("\n UNDERFLOW");
        return;
    }

    if (q->cur_size == 1) {
        free(q->head);
        q->head = NULL;
        q->cur_size--;
        return;
    }

    q->head = q->head->next;
    free(q->head->prev);
    q->head->prev = NULL;
    q->cur_size--;
}

void display(struct Queue * queue) {
    struct Node *ptr = queue->head;
    while (ptr != NULL) {
        printf("%d ", ptr->value.i);
        ptr = ptr->next;
    }
    printf("\n");
}

#endif
