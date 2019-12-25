#include <stdio.h>
#include <string.h>
#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

#include "ConvertToPostfix.h"
#include "stack.h"

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

void addRemainingOperators(Stack* stack, const int shiftForOperators, int* resultingArray,
                           int* currentIndexInResultingArray, bool* error)
{
    bool isEmpty = false;
    isStackEmpty(stack, &isEmpty);
    while (!isEmpty)
    {
        int frontValue = 0;
        peakOfStack(stack, &frontValue);
        if (frontValue == getcode('(', shiftForOperators))
        {
            printf("Closing bracket missed in input expression.");
            *error = true;
        }
        int poppedValue = 0;
        popFromStack(stack, &poppedValue);
        addToResultingArray(resultingArray, currentIndexInResultingArray, poppedValue);
        isStackEmpty(stack, &isEmpty);
    }
}
void parseOperator(char currentSymbol, const int shiftForOperators, Stack* stack, int* resultingArray,
                   int* currentIndexInResultingArray, bool* wasOperatorBefore, bool* error)
{
    if (*wasOperatorBefore)
    {
        printf("Error.\n");
        *error = true;
        return;
    }

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
    *wasOperatorBefore = true;
}

void parseClosingBracket(Stack* stack, const int shiftForOperators, int* resultingArray,
                         int* currentIndexInResultingArray)
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

void parseNumber(bool* wasOperatorBefore, Stack* stack, bool* error, char currentSymbol, int* resultingArray,
                 char* inputExpression, int* i, int* currentNumber, int* currentIndexInResultingArray)
{
    if (!*wasOperatorBefore)
    {
        printf("Error.\n");
        *error = true;
        return;
    }

    while (isDigit(currentSymbol))
    {
        *currentNumber = *currentNumber * 10 + (int) currentSymbol - (int) '0';
        (*i)++;
        currentSymbol = inputExpression[*i];
    }
    addToResultingArray(resultingArray, currentIndexInResultingArray, *currentNumber);
    *currentNumber = 0;
    (*i)--;
    *wasOperatorBefore = false;
}

bool convertInfixToPostfix(char *inputExpression, int resultingArray[],
                           int* currentIndexInResultingArray, int shiftForOperators)
{
    int currentNumber = 0;
    Stack* stack = createStack();

    size_t inputExpressionLength = strlen(inputExpression);
    bool wasOperatorBefore = true;//начинаться должно с цифры
    bool error = false;

    for (int i = 0; i < inputExpressionLength; i++)
    {
        char currentSymbol = inputExpression[i];
        if (error)
        {
            deleteStack(stack);
            return false;
        }
        if (isOperator(currentSymbol))
        {
            parseOperator(currentSymbol, shiftForOperators, stack, resultingArray, currentIndexInResultingArray,
                          &wasOperatorBefore, &error);
        }
        else if (isDigit(currentSymbol))
        {
            parseNumber(&wasOperatorBefore, stack, &error, currentSymbol, resultingArray,
                        inputExpression, &i, &currentNumber, currentIndexInResultingArray);
        }
        else if (currentSymbol == '(')
        {
            pushToStack(getcode('(', shiftForOperators), stack);
        }
        else if (currentSymbol == ')')
        {
            parseClosingBracket(stack, shiftForOperators, resultingArray, currentIndexInResultingArray);
        }
        else if (currentSymbol == ' ')
        {
            continue;
        }
        else
        {
            printf("There is unexpected symbol in input expression.");
            deleteStack(stack);
            return false;
        }
    }

    addRemainingOperators(stack, shiftForOperators, resultingArray, currentIndexInResultingArray, &error);
    deleteStack(stack);
    if (error)
    {
        return false;
    }
    return true;
}

void convertResultingArrayToString(int* resultingArray, int sizeOfResultingArray, int shiftForOperators,
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