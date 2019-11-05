//
// Created by Олег on 01.10.2019.
//

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

#endif //REALISATION_OF_STACK_STACK_H
