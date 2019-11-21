#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

//StackOfInt
struct StackElement
{
    int value;
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

int frontValueOfStack(Stack* stack)
{
    return stack->first->value;
}




//StackOfDouble
struct StackOfDoubleElement
{
    double value;
    StackOfDoubleElement* next;
};

struct StackOfDouble
{
    struct StackOfDoubleElement* first;
};

StackOfDouble* createStackOfDouble()
{
    StackOfDouble* stck1 = malloc(sizeof(Stack));
    stck1->first = NULL;
    return stck1;
}

bool isStackOfDoubleEmpty(StackOfDouble *stack)
{
    return stack->first == NULL;
}

bool pushToStackOfDouble(double value, StackOfDouble *stack)
{
    StackOfDoubleElement* stackElement = (StackOfDoubleElement*) malloc(sizeof(struct StackOfDoubleElement));
    stackElement->value = value;
    stackElement->next = stack->first;

    stack->first = stackElement;
    return true;
}

double popFromStackOfDouble(StackOfDouble *stack)
{
    if (isStackOfDoubleEmpty(stack))
    {
        return 0;
    }
    StackOfDoubleElement* poppedElement = stack->first;
    stack->first = poppedElement->next;
    double value = poppedElement->value;
    free(poppedElement);
    return(value);
}

double frontValueOfStackOfDouble(StackOfDouble* stack)
{
    return stack->first->value;
}