#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

//---------------------------StackOfInt-------------------------//

struct StackElement
{
    int value;
    StackElement* next;
};

struct Stack
{
    struct StackElement* head;
};

Stack* createStack()
{
    Stack* stck1 = malloc(sizeof(Stack));
    stck1->head = NULL;
    return stck1;
}

bool isStackEmpty(Stack *stack)
{
    return stack->head == NULL;
}

bool pushToStack(int value, Stack *stack)
{
    StackElement* stackElement = (StackElement*) malloc(sizeof(StackElement));
    stackElement->value = value;
    stackElement->next = stack->head;

    stack->head = stackElement;
    return true;
}

int popFromStack(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        return 0;
    }
    StackElement* poppedElement = stack->head;
    stack->head = poppedElement->next;
    int value = poppedElement->value;
    free(poppedElement);
    return value;
}

int peakOfStack(Stack* stack)
{
    return stack->head->value;
}

//------------------------StackOfDouble-----------------------------//

typedef struct StackOfDoubleElement StackOfDoubleElement;
struct StackOfDoubleElement
{
    double value;
    StackOfDoubleElement* next;
};

struct StackOfDouble
{
    struct StackOfDoubleElement* head;
};

StackOfDouble* createStackOfDouble()
{
    StackOfDouble* newStack = malloc(sizeof(Stack));
    newStack->head = NULL;
    return newStack;
}

bool isStackOfDoubleEmpty(StackOfDouble *stack)
{
    return stack->head == NULL;
}

Result pushToStackOfDouble(double value, StackOfDouble *stack)
{
    if (stack == NULL)
    {
        return fail;
    }

    StackOfDoubleElement* stackElement = (StackOfDoubleElement*) malloc(sizeof(struct StackOfDoubleElement));
    stackElement->value = value;
    stackElement->next = stack->head;

    stack->head = stackElement;
    return success;
}

Result popFromStackOfDouble(StackOfDouble *stack)
{
    if (stack == NULL)
    {
        return fail;
    }

    if (isStackOfDoubleEmpty(stack))
    {
        return 0;
    }
    StackOfDoubleElement* poppedElement = stack->head;
    stack->head = poppedElement->next;
    double value = poppedElement->value;
    free(poppedElement);
    return success;
}

Result peakOfStackOfDouble(StackOfDouble* stack, double* value)
{
    if (stack == NULL)
    {
        return  fail;
    }
    *value = stack->head->value;
    return success;
}