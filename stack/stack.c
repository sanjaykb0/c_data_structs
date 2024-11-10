#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include "stack.h"

int main() {
    int n;
    char ch;
    float f;

    scanf("%d", &n);

    // Doubt: How does calloc work with structures? Are the values initialised with 0?
    struct Stack *s = init_stack(n);

    for (int i = 0; i < n; i++) {
        union Value v;
        getchar();
        scanf("%c", &v.c);
        push(s, v);
    }

    display(s);

}
