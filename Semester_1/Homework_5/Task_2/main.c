#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "stack.h"

bool isOperator(char symbol)
{
    return (symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/');
}

bool isDigit(char symbol)
{
    return ((int) symbol >= (int) '0') && ((int) symbol <= (int) '9');
}

double binaryOperation(char currentSymbol, double firstOperand, double secondOperand)
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
        case '/':
        {
            return firstOperand / secondOperand;
        }
    }
}

void printValueOfWholeExpression(double value)
{
    const double eps = 0.0001;
    printf("This is the value of your expression:\n");
    if (fabs(value - (int) value) < eps)
    {
        printf("%d", (int) value);
    }
    else
    {
        printf("%lf", value);
    }
}

void countValueOfWholeExpression(char *inputExpression)
{
    char currentSymbol = 0;
    StackOfDouble* stack = createStackOfDouble();

    int inputExpressionLength = (int) strlen(inputExpression);

    for (int i = 0; i < inputExpressionLength; i++)
    {
        int currentNumber = 0;
        currentSymbol = inputExpression[i];

        if (isOperator( (char) currentSymbol))
        {
            double secondOperand = 0;
            peakOfStackOfDouble(stack, &secondOperand);
            popFromStackOfDouble(stack);
            double firstOperand = 0;
            peakOfStackOfDouble(stack, &firstOperand);
            popFromStackOfDouble(stack);
            pushToStackOfDouble(binaryOperation(currentSymbol, firstOperand, secondOperand), stack);
        }
        else if (isDigit(currentSymbol))
        {
            while (isDigit(currentSymbol))
            {
                currentNumber = currentNumber * 10 + (int) currentSymbol - (int) '0';
                i++;
                currentSymbol = inputExpression[i];
            }
            pushToStackOfDouble(currentNumber, stack);
            i--;
        }
    }

    double resultingValue = 0;
    peakOfStackOfDouble(stack, &resultingValue);
    printValueOfWholeExpression(resultingValue);

    popFromStackOfDouble(stack);
    free(stack);
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
        if (i >= currentStringSize) {
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
    const size_t startingSizeOfString = 1000;
    printf("Please, write down the expression:\n");
    char* inputExpression = readString(startingSizeOfString);

    countValueOfWholeExpression(inputExpression);
    free(inputExpression);
    return 0;
}