#include <stdio.h>
#include <string.h>
#include "stack.h"
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

void addToResultingArray(int resultingArray[], int* currentIndex, int value)
{
    resultingArray[*currentIndex] = value;
    (*currentIndex)++;
}

bool convertInfixToPostfix(char *inputExpression, Stack* stack, int resultingArray[], int* currentIndexInResultingArray)
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
            while ((!isStackEmpty(stack)) && (getPriority( (char) (frontValueOfStack(stack) - maxNumber)) >= getPriority(currentSymbol)))
            {
                addToResultingArray(resultingArray, currentIndexInResultingArray, popFromStack(stack));
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
            addToResultingArray(resultingArray, currentIndexInResultingArray, currentNumber);
            currentNumber = 0;
            i--;
        }
        else if (currentSymbol == '(')
        {
            pushToStack(getcode('('), stack);
        }
        else if (currentSymbol == ')')
        {
            while (frontValueOfStack(stack) != getcode ('('))
            {
                addToResultingArray(resultingArray, currentIndexInResultingArray, popFromStack(stack));
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

    while (!isStackEmpty(stack))
    {
        if (frontValueOfStack(stack) == getcode('('))
        {
            printf("Closing bracket missed in input expression.");
            return false;
        }
        addToResultingArray(resultingArray, currentIndexInResultingArray, popFromStack(stack));
    }

    return true;
}

void convertResultingArrayToString(int resultingArray[], int currentIndexInResultingArray, const int maxNumber, const int maxInputLength, char* resultingString)
{
    char tempString[maxInputLength];

    int sizeOfResultingArray = currentIndexInResultingArray;
    for (int i = 0; i < sizeOfResultingArray; i++)
    {
        if (isOperator((char) resultingArray[i] - maxNumber))
        {
            sprintf(tempString, "%c ", (char) resultingArray[i] - maxNumber);
            strcat(resultingString, tempString);
        }
        else
        {
            sprintf(tempString, "%d ", resultingArray[i]);
            strcat(resultingString, tempString);
        }
    }
}

int main() 
{
    const int maxNumber = 1000;
    struct Stack* stack = createStack();

    const int maxInputLength = 1000;
    char inputExpression[maxInputLength];
    printf("Please, write down the expression:\n");
    gets(inputExpression);

    int resultingArray[maxInputLength];
    for (int i = 0; i < maxInputLength; i++)
    {
        resultingArray[i] = 0;
    }
    int currentIndexInResultingArray = 0;

    if (!convertInfixToPostfix(inputExpression, stack, resultingArray, &currentIndexInResultingArray))
    {
        return 0;
    }

    char resultingString[maxInputLength];
    convertResultingArrayToString(resultingArray, currentIndexInResultingArray, maxNumber, maxInputLength, resultingString);
    printf("This is your expression in postfix format:\n%s", resultingString);

    return 0;
}