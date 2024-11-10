#ifndef LL_DEFINITIONS_H
#define LL_DEFINITIONS_H

struct Node {
    struct Node *next;
    struct Node *prev;
    int data;
};

struct LinkedList {
    struct Node *head;
    int size;
};

#endif
