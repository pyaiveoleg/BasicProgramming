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
        default:
            exit(1);
    }
}

void countValueOfWholeExpression(char *inputExpression, StackOfDouble* stack)
{
    char currentSymbol = 0;

    int inputExpressionLength = (int) strlen(inputExpression);

    for (int i = 0; i < inputExpressionLength; i++)
    {
        int currentNumber = 0;
        currentSymbol = inputExpression[i];

        if (isOperator( (char) currentSymbol))
        {
            double firstOperand = peakOfStackOfDouble(stack);
            popFromStackOfDouble(stack);
            double secondOperand = peakOfStackOfDouble(stack);
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
}

void printValueOfWholeExpression(double value)
{
    const double eps = 0.0001;
    if (fabs(value - (int) value) < eps)
    {
        printf("This is the value of your expression:\n%d", (int) value);
    }
    else
    {
        printf("This is the value of your expression:\n%lf", value);
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
    struct StackOfDouble* stack = createStackOfDouble();

    const size_t startingSizeOfString = 1000;
    printf("Please, write down the expression:\n");
    char* inputExpression = readString(startingSizeOfString);

    countValueOfWholeExpression(inputExpression, stack);
    printValueOfWholeExpression(peakOfStackOfDouble(stack));

    return 0;
}