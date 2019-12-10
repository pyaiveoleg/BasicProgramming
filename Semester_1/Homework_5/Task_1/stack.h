#pragma once

#include <stdbool.h>
struct Stack;
typedef struct Stack Stack;

typedef enum Result
{
    success,
    fail,
} Result;

bool isStackEmpty(Stack *stack);
Result pushToStack(int value, Stack *stack);
int popFromStack(Stack *stack);
int frontValueOfStack(Stack* stack);
Stack* createStack();
