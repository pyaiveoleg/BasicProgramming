#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

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
    Stack* stck1 = malloc(sizeof(Stack));
    stck1->first = NULL;
    return stck1;
}

bool isStackEmpty(Stack *stack)
{
    return stack->first == NULL;
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
    return success
}

int popFromStack(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        return -1;
    }
    StackElement* poppedElement = stack->first;
    stack->first = poppedElement->next;
    int value = poppedElement->value;
    free(poppedElement);
    return(value);
}

int frontValueOfStack(Stack* stack)
{
    if (isStackEmpty(stack))
    {
        return -1;
    }
    return stack->first->value;
}