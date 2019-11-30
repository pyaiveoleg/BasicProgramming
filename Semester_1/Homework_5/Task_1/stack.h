#pragma once

#include <stdbool.h>
struct Stack;
typedef struct Stack Stack;

typedef enum Result
{
    kResult_Ok,
    kResult_Fail,
} Result;

bool isStackEmpty(Stack *stack);
Result pushToStack(int value, Stack *stack);
int popFromStack(Stack *stack);
int frontValueOfStack(Stack* stack);
Stack* createStack();
