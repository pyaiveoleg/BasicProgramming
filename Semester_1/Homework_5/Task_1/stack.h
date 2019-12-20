#pragma once

#include <stdbool.h>
struct Stack;
typedef struct Stack Stack;

typedef enum Result
{
    success,
    fail,
} Result;

Result isStackEmpty(Stack *stack, bool* isEmpty);
Result pushToStack(int value, Stack *stack);
Result popFromStack(Stack *stack, int* value);
Result peakOfStack(Stack* stack, int* value);
Stack* createStack();
Result deleteStack(Stack* stack);
