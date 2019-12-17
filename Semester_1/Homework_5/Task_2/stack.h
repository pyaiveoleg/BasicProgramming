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

Result isStackOfDoubleEmpty(StackOfDouble *stack, bool* isEmpty);
Result pushToStackOfDouble(double value, StackOfDouble *stack);
Result popFromStackOfDouble(StackOfDouble *stack);
Result peakOfStackOfDouble(StackOfDouble* stackOfDouble, double* value);
StackOfDouble* createStackOfDouble();
