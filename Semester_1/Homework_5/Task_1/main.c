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
    return (symbol >= '0') && (symbol <= '9');
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

int getcode(char symbol, const int shiftForOperators) //код сдвигается, чтобы случайно не совпал с введённым числом
{
    return symbol + shiftForOperators;
}

void addToResultingArray(int resultingArray[], int* currentIndex, int value)
{
    resultingArray[*currentIndex] = value;
    (*currentIndex)++;
}

bool convertInfixToPostfix(char *inputExpression, int resultingArray[],
                           int* currentIndexInResultingArray, const int shiftForOperators)
{
    int currentNumber = 0;
    Stack* stack = createStack();

    size_t inputExpressionLength = strlen(inputExpression);

    for (size_t i = 0; i < inputExpressionLength; i++)
    {
        char currentSymbol = inputExpression[i];
        if (isOperator(currentSymbol))
        {
            int frontValue = 0;
            bool isEmpty = false;
            peakOfStack(stack, &frontValue);
            while (!isEmpty && (getPriority( (char) (frontValue - shiftForOperators)) >= getPriority(currentSymbol)))
            {
                int poppedValue = 0;
                popFromStack(stack, &poppedValue);
                addToResultingArray(resultingArray, currentIndexInResultingArray, poppedValue);
                peakOfStack(stack, &frontValue);
                isStackEmpty(stack, &isEmpty);
            }

            pushToStack(getcode(currentSymbol, shiftForOperators), stack);
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
            pushToStack(getcode('(', shiftForOperators), stack);
        }
        else if (currentSymbol == ')')
        {
            int frontValue = 0;
            peakOfStack(stack, &frontValue);
            while (frontValue != getcode ('(', shiftForOperators))
            {
                int poppedValue = 0;
                popFromStack(stack, &poppedValue);
                addToResultingArray(resultingArray, currentIndexInResultingArray, poppedValue);
                peakOfStack(stack, &frontValue);
            }
            int poppedValue = 0;
            popFromStack(stack, &poppedValue);
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

    bool isEmpty = false;
    isStackEmpty(stack, &isEmpty);
    while (!isEmpty)
    {
        int frontValue = 0;
        peakOfStack(stack, &frontValue);
        if (frontValue == getcode('(', shiftForOperators))
        {
            printf("Closing bracket missed in input expression.");
            return false;
        }
        int poppedValue = 0;
        popFromStack(stack, &poppedValue);
        addToResultingArray(resultingArray, currentIndexInResultingArray, poppedValue);
        isStackEmpty(stack, &isEmpty);
    }

    free(stack);
    return true;
}

void convertResultingArrayToString(int* resultingArray, int sizeOfResultingArray, const int shiftForOperators,
                                   size_t stringLength, char* resultingString)
{
    char* tempString = (char*) malloc(sizeof(char) * stringLength);

    for (int i = 0; i < sizeOfResultingArray; i++)
    {
        if (isOperator((char) (resultingArray[i] - shiftForOperators)))
        {
            sprintf(tempString, "%c ", (char) resultingArray[i] - shiftForOperators);
            strcat(resultingString, tempString);
        }
        else
        {
            sprintf(tempString, "%d ", resultingArray[i]);
            strcat(resultingString, tempString);
        }
    }
    free(tempString);
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
    const int shiftForOperators = -1000;
    const int startingStringLength = 10;

    printf("Please, write down the expression (with gaps between numbers and operators):\n");
    char* inputExpression = readString(startingStringLength);

    int* resultingArray = (int*) malloc(sizeof(int) * strlen(inputExpression));
    for (size_t i = 0; i < strlen(inputExpression); i++)
    {
        resultingArray[i] = 0;
    }
    int currentIndexInResultingArray = 0;

    if (!convertInfixToPostfix(inputExpression, resultingArray, &currentIndexInResultingArray, shiftForOperators))
    {
        return 0;
    }

    char* resultingString = (char*) malloc(sizeof(char) * strlen(inputExpression));
    resultingString[0] = '\0';

    convertResultingArrayToString(resultingArray, currentIndexInResultingArray, shiftForOperators,
            strlen(inputExpression), resultingString);
    printf("This is your expression in postfix format:\n%s", resultingString);
    free(resultingString);

    return 0;
}