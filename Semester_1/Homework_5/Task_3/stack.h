#ifndef REALISATION_OF_STACK_STACK_H
#define REALISATION_OF_STACK_STACK_H

#include <stdbool.h>
struct Stack;
struct StackElement;
typedef struct Stack Stack;
typedef struct StackElement StackElement;

bool isStackEmpty(Stack *stack);
bool pushToStack(int value, Stack *stack);
int popFromStack(Stack *stack);
int frontValueOfStack(Stack* stack);
Stack* createStack();


struct StackOfDouble;
struct StackOfDoubleElement;
typedef struct StackOfDouble StackOfDouble;
typedef struct StackOfDoubleElement StackOfDoubleElement;

bool isStackOfDoubleEmpty(StackOfDouble *stack);
bool pushToStackOfDouble(double value, StackOfDouble *stack);
double popFromStackOfDouble(StackOfDouble *stack);
double frontValueOfStackOfDouble(StackOfDouble* stack);
StackOfDouble* createStackOfDouble();


#endif //REALISATION_OF_STACK_STACK_H
