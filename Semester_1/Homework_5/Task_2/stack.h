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
struct StackOfDoubleElement;
typedef struct StackOfDouble StackOfDouble;
typedef struct StackOfDoubleElement StackOfDoubleElement;

bool isStackOfDoubleEmpty(StackOfDouble *stack);
bool pushToStackOfDouble(double value, StackOfDouble *stack);
double popFromStackOfDouble(StackOfDouble *stack);
double peakOfStackOfDouble(StackOfDouble* stack);
StackOfDouble* createStackOfDouble();
