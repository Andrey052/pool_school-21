#include "stack.h"

Stack *init_stack(size_t capacity) {
    Stack *stack = malloc(sizeof(Stack));
    stack->data = malloc(capacity * sizeof(int));
    stack->size = 0;
    stack->capacity = capacity;
    return stack;
}

int push(Stack *stack, int value) {
    if (stack->size >= stack->capacity) return FAIL;
    stack->data[stack->size++] = value;
    return SUCCESS;
}

int pop(Stack *stack, int *value) {
    if (stack->size == 0) return FAIL;
    *value = stack->data[--stack->size];
    return SUCCESS;
}

void destroy_stack(Stack *stack) {
    free(stack->data);
    free(stack);
}