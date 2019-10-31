#include <stdio.h>
#include <string.h>
#include "stack.h"

bool isNotDividingOperator(char symbol)
{
    return (symbol == '+') || (symbol == '-') || (symbol == '*');
}

bool isDigit(char symbol)
{
    return ((int) symbol >= (int) '0') && ((int) symbol <= (int) '9');
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

void parseExpression(char *inputExpression, Stack* stack)
{
    int currentSymbol = 0;

    int inputExpressionLength = strlen(inputExpression);

    for (int i = 0; i < inputExpressionLength; i++)
    {
        int currentNumber = 0;
        currentSymbol = inputExpression[i];

        if (isNotDividingOperator( (char) currentSymbol))
        {
            int firstOperand = frontValue(stack);
            popFromStack(stack);
            int secondOperand = frontValue(stack);
            popFromStack(stack);
            pushToStack(valueOfCurrentExpression(currentSymbol, firstOperand, secondOperand), stack);
        }
        else if (currentSymbol == '/')
        {
            int firstOperand = frontValue(stack);
            popFromStack(stack);
            int secondOperand = frontValue(stack);
            popFromStack(stack);
            pushToStack(firstOperand / secondOperand, stack);
        }
        else if (isDigit(currentSymbol))
        {
            while (isDigit(currentSymbol))
            {
                currentNumber = currentNumber * 10 + (int) currentSymbol - (int) '0';
                i++;
                currentSymbol = inputExpression[i];
            }
            pushToStack(currentNumber, stack);
            i--;
        }
    }
}

int main() {
    struct Stack* stack = createStack();

    const int maxInputLength = 1000;
    char inputExpression[maxInputLength];
    printf("Please, write down the expression:\n");
    gets(inputExpression);

    parseExpression(inputExpression, stack);
    printf("This is the value of your expression:\n%d", frontValue(stack));

    return 0;
}