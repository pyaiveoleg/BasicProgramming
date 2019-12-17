#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

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
    StackOfDouble* newStack = malloc(sizeof(StackOfDouble));
    newStack->head = NULL;
    return newStack;
}

bool isStackOfDoubleEmpty(StackOfDouble *stack)
{
    if (stack != NULL)
    {
        return stack->head == NULL;
    }
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