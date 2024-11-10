#include <stdlib.h>
#include "node.h"

#ifndef STACK_H
#define STACK_H

struct Stack {
    struct Node *head;
    size_t max_size;
    size_t cur_size;
};

void push(struct Stack* stack, union Value value) {
    if (stack->cur_size == stack->max_size) {
        printf("ERROR: Maximum Size Reached! (max: %lu)\n", stack->max_size);
        return;
    }

    struct Node *node = def_node(stack->head, value);
    stack->head = node;
    stack->cur_size++;
}

union Value pop(struct Stack *stack) {
    union Value v;
    v.i = -1;
    if (stack->cur_size == 0) {
        return v;
    }

    if (stack->cur_size == 1) {
        v.i = stack->head->value.i;
        free(stack->head);
        stack->head = NULL;
        stack->cur_size--;
        return v;
    }

    struct Node *tmp = stack->head->prev;
    v.i = stack->head->value.i;
    free(tmp->next);
    stack->head = tmp;
    stack->head->next = NULL;
    stack->cur_size--;
    return v;
}

void display(struct Stack *stack) {
    struct Node *ptr= stack->head;
    while (ptr != NULL) {
        printf("%d ", ptr->value.i); // Todo: figure out a way to detect data type. Only supports one at a time
        ptr = ptr->prev;
    }
    printf("\n");
}

void get_size(struct Stack *stack) {
    printf("%lu\n", stack->cur_size);
}

struct Stack *init_stack(size_t max_size) {
    struct Stack* stack = (struct Stack*)calloc(1, sizeof(struct Stack));

    stack->head = NULL;
    stack->max_size = max_size;
    stack->cur_size = 0;

    return stack;
}

#endif
