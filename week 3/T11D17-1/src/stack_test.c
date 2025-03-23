#include "stack.h"

#include <stdio.h>

int main() {
    Stack *stack = init_stack(2);
    int result;

    if (push(stack, 1) == SUCCESS && push(stack, 2) == SUCCESS && pop(stack, &result) == SUCCESS &&
        result == 2 && pop(stack, &result) == SUCCESS && result == 1 && pop(stack, &result) == FAIL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    destroy_stack(stack);
    return 0;
}