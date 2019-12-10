#pragma once

#include <stdbool.h>

struct Stack;
struct StackElement;
typedef struct Stack Stack;
typedef struct StackElement StackElement;

bool isStackEmpty(Stack *stack);
bool pushToStack(int value, Stack *stack);
int popFromStack(Stack *stack);
int peakOfStack(Stack* stack);
Stack* createStack();

struct StackOfDouble;
typedef struct StackOfDouble StackOfDouble;

typedef enum Result
{
    success,
    fail,
} Result;

Result pushToStackOfDouble(double value, StackOfDouble *stack);
Result popFromStackOfDouble(StackOfDouble *stack);
Result peakOfStackOfDouble(StackOfDouble* stackOfDouble, double* value);
StackOfDouble* createStackOfDouble();
