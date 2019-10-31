//
// Created by Олег on 01.10.2019.
//

#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

struct StackElement
{
    int value;
    char charValue;
    StackElement* next;
};

struct Stack
{
    struct StackElement* first;
};

Stack* createStack()
{
    Stack* stck1 = malloc(sizeof(Stack));
    stck1->first = NULL;
    return stck1;
}

bool isStackEmpty(Stack *stack)
{
    return stack->first == NULL;
}

bool pushToStack(int value, Stack *stack)
{
    StackElement* stackElement = (StackElement*) malloc(sizeof(StackElement));
    stackElement->value = value;
    stackElement->next = stack->first;

    stack->first = stackElement;
    return true;
}

bool pushCharToStack(char charValue, Stack *stack)
{
    StackElement* stackElement = (StackElement*) malloc(sizeof(StackElement));
    stackElement->charValue = charValue;
    stackElement->value = 0;
    stackElement->next = stack->first;

    stack->first = stackElement;
    return true;
}

int popFromStack(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        return 0;
    }
    StackElement* poppedElement = stack->first;
    stack->first = poppedElement->next;
    int value = poppedElement->value;
    free(poppedElement);
    return(value);
}

int frontValue(Stack* stack)
{
    return stack->first->value;
}

char frontCharValue(Stack* stack)
{
    return stack->first->charValue;
}