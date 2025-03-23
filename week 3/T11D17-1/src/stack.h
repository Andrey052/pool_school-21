#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL -1

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Stack;

Stack *init_stack(size_t capacity);
int push(Stack *stack, int value);
int pop(Stack *stack, int *value);
void destroy_stack(Stack *stack);

#endif