#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"

bool isOperator(char symbol)
{
    return (symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/');
}

bool isDigit(char symbol)
{
    return ((int) symbol >= (int) '0') && ((int) symbol <= (int) '9');
}

double binaryOperation(char currentSymbol, int firstOperand, int secondOperand)
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

void countValueOfWholeExpression(char *inputExpression, StackOfDouble* stack)
{
    int currentSymbol = 0;

    int inputExpressionLength = strlen(inputExpression);

    for (int i = 0; i < inputExpressionLength; i++)
    {
        int currentNumber = 0;
        currentSymbol = inputExpression[i];

        if (isOperator( (char) currentSymbol))
        {
            int firstOperand = frontValueOfStackOfDouble(stack);
            popFromStackOfDouble(stack);
            int secondOperand = frontValueOfStackOfDouble(stack);
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

void printValueOfWholeExpression(double value, const double eps)
{
    if (fabs(value - (int) value) < eps)
    {
        printf("This is the value of your expression:\n%d", (int) value);
    }
    else
    {
        printf("This is the value of your expression:\n%lf", value);
    }
}

int main() 
{
    struct StackOfDouble* stack = createStackOfDouble();

    const int maxInputLength = 1000;
    const double eps = 0.0001;
    char inputExpression[maxInputLength];
    printf("Please, write down the expression:\n");
    gets(inputExpression);

    countValueOfWholeExpression(inputExpression, stack);
    printValueOfWholeExpression(frontValueOfStackOfDouble(stack), eps);

    return 0;
}