#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include <stdbool.h>

bool isOperator(char symbol)
{
    return (symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/');
}

bool isDigit(char symbol)
{
    return ((int) symbol >= (int) '0') && ((int) symbol <= (int) '9');
}

int getPriority(char symbol)
{
    if ((symbol == '+') || (symbol == '-'))
    {
        return 1;
    }
    if ((symbol == '*') || (symbol == '/'))
    {
        return 2;
    }
    return 0;
}

int getcode(char symbol) //код сдвигается, чтобы случайно не совпал с введённым числом
{
    const int maxNumber = 1000;
    return (int) symbol + maxNumber;
}

bool parseExpression(char *inputExpression, Stack* stack, Queue* queue)
{
    char currentSymbol = '0';
    int currentNumber = 0;
    const int maxNumber = 1000;

    int inputExpressionLength = strlen(inputExpression);

    for (int i = 0; i < inputExpressionLength; i++)
    {
        currentSymbol = inputExpression[i];
        if (isOperator(currentSymbol))
        {
            while ((!isStackEmpty(stack)) && (getPriority( (char) (frontValue(stack) - maxNumber)) >= getPriority(currentSymbol)))
            {
                pushToQueue(frontValue(stack), queue);
                popFromStack(stack);
            }
            pushToStack(getcode(currentSymbol), stack);
        }
        else if (isDigit(currentSymbol))
        {
            while (isDigit(currentSymbol))
            {
                currentNumber = currentNumber * 10 + (int) currentSymbol - (int) '0';
                i++;
                currentSymbol = inputExpression[i];
            }
            pushToQueue(currentNumber, queue);
            currentNumber = 0;
            i--;
        }
        else if (currentSymbol == '(')
        {
            pushToStack(getcode('('), stack);
        }
        else if (currentSymbol == ')')
        {
            while (frontValue(stack) != getcode ('('))
            {
                pushToQueue(frontValue(stack), queue);
                popFromStack(stack);
            }
            popFromStack(stack);
        }
        else if (currentSymbol == ' ') {}
        else
        {
            printf("There is unexpected symbol in input expression.");
            return false;
        }
    }

    return true;
}

int valueOfCurrentExpression(char currentSymbol, int firstOperand, int secondOperand)
{
    switch (currentSymbol)
    {
        case '+':
        {
            return firstOperand + secondOperand;
        }
        case '-':
        {
            return firstOperand - secondOperand;
        }
        case '*':
        {
            return firstOperand * secondOperand;
        }
    }
}

int main() {
    const int maxNumber = 1000;
    struct Stack* stack = createStack();
    struct Queue* queue = createQueue();

    const int maxInputLength = 1000;
    char inputExpression[maxInputLength];
    printf("Please, write down the expression:\n");
    gets(inputExpression);
    //printf("as;dlfk");
    if (!parseExpression(inputExpression, stack, queue))
    {
        return 0;
    }

    while (!isStackEmpty(stack))
    {
        if (frontValue(stack) == getcode('('))
        {
            printf("Closing bracket missed in input expression.");
            return 0;
        }
        pushToQueue(frontValue(stack), queue);
        popFromStack(stack);
    }



    return 0;
}