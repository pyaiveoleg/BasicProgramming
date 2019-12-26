#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

//--------------------StackOfInt-------------------------//

typedef struct StackElement StackElement;
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
    Stack* newStack = malloc(sizeof(Stack));
    newStack->first = NULL;
    return newStack;
}

Result isStackEmpty(Stack *stack, bool* isEmpty)
{
    if (stack == NULL)
    {
        return fail;
    }
    *isEmpty = stack->first == NULL;
    return success;
}

Result pushToStack(int value, Stack *stack)
{
    if (stack == NULL)
    {
        return fail;
    }
    StackElement* stackElement = (StackElement*) malloc(sizeof(StackElement));
    stackElement->value = value;
    stackElement->next = stack->first;

    stack->first = stackElement;
    return success;
}

Result popFromStack(Stack *stack, int* value)
{
    if (stack == NULL)
    {
        return fail;
    }
    bool isEmpty = false;
    isStackEmpty(stack, &isEmpty);
    if (isEmpty)
    {
        return fail;
    }
    StackElement* poppedElement = stack->first;
    stack->first = poppedElement->next;
    *value = poppedElement->value;
    free(poppedElement);
    return success;
}

Result peakOfStack(Stack* stack, int* value)
{
    if (stack == NULL)
    {
        return fail;
    }
    bool isEmpty = false;
    isStackEmpty(stack, &isEmpty);
    if (isEmpty)
    {
        return fail;
    }
    *value = stack->first->value;
    return success;
}

Result deleteStack(Stack* stack)
{
    if (stack == NULL)
    {
        return fail;
    }

    StackElement* currentElement = stack->first;
    StackElement* elementForDelete = currentElement;
    while (currentElement != NULL)
    {
        elementForDelete = currentElement;
        currentElement = currentElement->next;
        free(elementForDelete);
    }
    free(stack);
    return success;
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
    StackOfDouble* newStack = malloc(sizeof(StackOfDouble));
    newStack->head = NULL;
    return newStack;
}

Result isStackOfDoubleEmpty(StackOfDouble *stack, bool* isEmpty)
{
    if (stack == NULL)
    {
        return fail;
    }
    *isEmpty = stack->head == NULL;
    return success;
}

Result pushToStackOfDouble(double value, StackOfDouble *stack)
{
    if (stack == NULL)
    {
        return fail;
    }


    StackOfDoubleElement* stackElement = (StackOfDoubleElement*) malloc(sizeof(StackOfDoubleElement));
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

    bool isStackEmpty = false;
    isStackOfDoubleEmpty(stack, &isStackEmpty);
    if (isStackEmpty)
    {
        return fail;
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

Result deleteStackOfDouble(StackOfDouble* stack)
{
    if (stack == NULL)
    {
        return fail;
    }

    StackOfDoubleElement* currentElement = stack->head;
    StackOfDoubleElement* elementForDelete = currentElement;
    while (currentElement != NULL)
    {
        elementForDelete = currentElement;
        currentElement = currentElement->next;
        free(elementForDelete);
    }
    free(stack);
    return success;
}