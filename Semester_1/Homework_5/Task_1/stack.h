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

bool isStackOfDoubleEmpty(StackOfDouble* stack);
Result pushToStackOfDouble(double value, StackOfDouble *stack);
Result popFromStackOfDouble(StackOfDouble *stack);
Result peakOfStackOfDouble(StackOfDouble* stackOfDouble, double* value);
StackOfDouble* createStackOfDouble();
