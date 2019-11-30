#include <stdio.h>
#include <string.h>
#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

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

int getcode(char symbol, const int maxNumber) //код сдвигается, чтобы случайно не совпал с введённым числом
{
    return (int) symbol + maxNumber;
}

void addToResultingArray(int resultingArray[], int* currentIndex, int value)
{
    resultingArray[*currentIndex] = value;
    (*currentIndex)++;
}

bool convertInfixToPostfix(char *inputExpression, int resultingArray[],
                           int* currentIndexInResultingArray, const int maxNumber)
{
    int currentNumber = 0;
    Stack* stack = createStack();

    size_t inputExpressionLength = strlen(inputExpression);

    for (size_t i = 0; i < inputExpressionLength; i++)
    {
        char currentSymbol = inputExpression[i];
        if (isOperator(currentSymbol))
        {
            while ((!isStackEmpty(stack)) && (getPriority( (char) (frontValueOfStack(stack) - maxNumber)) >= getPriority(currentSymbol)))
            {
                addToResultingArray(resultingArray, currentIndexInResultingArray, popFromStack(stack));
            }
            pushToStack(getcode(currentSymbol, maxNumber), stack);
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
            pushToStack(getcode('(', maxNumber), stack);
        }
        else if (currentSymbol == ')')
        {
            while (frontValueOfStack(stack) != getcode ('(', maxNumber))
            {
                addToResultingArray(resultingArray, currentIndexInResultingArray, popFromStack(stack));
            }
            popFromStack(stack);
        }
        else if (currentSymbol == ' ')
        {
            continue;
        }
        else
        {
            printf("There is unexpected symbol in input expression.");
            return false;
        }
    }

    while (!isStackEmpty(stack))
    {
        if (frontValueOfStack(stack) == getcode('(', maxNumber))
        {
            printf("Closing bracket missed in input expression.");
            return false;
        }
        addToResultingArray(resultingArray, currentIndexInResultingArray, popFromStack(stack));
    }

    free(stack);
    return true;
}

void convertResultingArrayToString(int resultingArray[], int sizeOfResultingArray, const int maxNumber,
                                   const int maxInputLength, char* resultingString)
{
    char tempString[maxInputLength];

    for (int i = 0; i < sizeOfResultingArray; i++)
    {
        if (isOperator((char) (resultingArray[i] - maxNumber)))
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

char* readString(size_t startingSizeOfString)
{
    char *currentString = (char *) malloc(sizeof(char) * startingSizeOfString);
    int currentStringSize = startingSizeOfString;

    int i = 0;
    do
    {
        currentString[i] = (char) getchar();
        i++;
        if (i >= currentStringSize)
        {
            currentStringSize *= 2;
            currentString = (char *) realloc(currentString, sizeof(char) * currentStringSize);
        }
    }
    while (currentString[i - 1] != '\n');
    currentString[i - 1] = '\0';

    return currentString;
}

int main() 
{
    const int maxNumber = 1000;
    const int maxInputLength = 1000;

    const int startingStringLength = 1000;
    printf("Please, write down the expression:\n");
    char* inputExpression = readString(startingStringLength);

    int* resultingArray = (int*) malloc(sizeof(int) * strlen(inputExpression));
    for (size_t i = 0; i < strlen(inputExpression); i++)
    {
        resultingArray[i] = 0;
    }
    int currentIndexInResultingArray = 0;

    if (!convertInfixToPostfix(inputExpression, resultingArray, &currentIndexInResultingArray, maxNumber))
    {
        return 0;
    }

    char* resultingString = (char*) malloc(sizeof(char) * maxInputLength);
    resultingString[0] = '\0';

    convertResultingArrayToString(resultingArray, currentIndexInResultingArray, maxNumber, maxInputLength, resultingString);
    printf("This is your expression in postfix format:\n%s", resultingString);
    free(resultingString);

    return 0;
}