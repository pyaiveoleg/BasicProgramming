#include <string.h>

#include "CountExpressionInPostfix.h"
#include "stack.h"

bool isOperator(char symbol)
{
    return (symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/');
}

bool isDigit(char symbol)
{
    return ((int) symbol >= (int) '0') && ((int) symbol <= (int) '9');
}

double binaryOperation(char currentSymbol, double firstOperand, double secondOperand, bool* dividingByZero)
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
            if (secondOperand == 0)
            {
                *dividingByZero = true;
                return 0;
            }
            return firstOperand / secondOperand;
        }
    }
}

void countBinaryOperation(StackOfDouble* stack, char currentSymbol, bool* error)
{
    bool isStackEmpty = false;
    isStackOfDoubleEmpty(stack, &isStackEmpty);
    if (isStackEmpty)
    {
        *error = true;
        return;
    }
    double secondOperand = 0;
    peakOfStackOfDouble(stack, &secondOperand);
    popFromStackOfDouble(stack);

    isStackOfDoubleEmpty(stack, &isStackEmpty);
    if (isStackEmpty)
    {
        *error = true;
        return;
    }
    double firstOperand = 0;
    peakOfStackOfDouble(stack, &firstOperand);
    popFromStackOfDouble(stack);
    bool dividingByZero = false;
    binaryOperation(currentSymbol, firstOperand, secondOperand, &dividingByZero);
    if (dividingByZero)
    {
        *error = true;
        return;
    }
    pushToStackOfDouble(binaryOperation(currentSymbol, firstOperand, secondOperand, &dividingByZero), stack);
}

bool countValueOfWholeExpression(char *inputExpression, double* resultingValue)
{
    char currentSymbol = 0;
    StackOfDouble* stack = createStackOfDouble();

    int inputExpressionLength = (int) strlen(inputExpression);

    for (int i = 0; i < inputExpressionLength; i++)
    {
        int currentNumber = 0;
        currentSymbol = inputExpression[i];

        if (isOperator(currentSymbol))
        {
            bool error = false;
            countBinaryOperation(stack, currentSymbol, &error);
            if (error)
            {
                deleteStackOfDouble(stack);
                return false;
            }
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
        else if (currentSymbol == ' ')
        {
            continue;
        }
        else
        {
            deleteStackOfDouble(stack);
            return false;
        }
    }
    peakOfStackOfDouble(stack, resultingValue);
    popFromStackOfDouble(stack);

    bool isStackEmpty = false;
    isStackOfDoubleEmpty(stack, &isStackEmpty);
    deleteStackOfDouble(stack);
    return isStackEmpty;
}
