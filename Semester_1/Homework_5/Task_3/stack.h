#pragma once

#include <stdbool.h>

struct Stack;
struct StackElement;
typedef struct Stack Stack;
typedef struct StackElement StackElement;

struct StackOfDouble;
typedef struct StackOfDouble StackOfDouble;

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

Result isStackOfDoubleEmpty(StackOfDouble *stack, bool* isEmpty);
Result pushToStackOfDouble(double value, StackOfDouble *stack);
Result popFromStackOfDouble(StackOfDouble *stack);
Result peakOfStackOfDouble(StackOfDouble* stackOfDouble, double* value);
StackOfDouble* createStackOfDouble();
Result deleteStackOfDouble(StackOfDouble* stack);
