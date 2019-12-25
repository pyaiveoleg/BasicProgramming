#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"
#include "ConvertToPostfix.h"

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
            currentString = (char*) realloc(currentString, sizeof(char) * currentStringSize);
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

    int* resultingArray = (int*) malloc(sizeof(int) * (2 * strlen(inputExpression)));
    for (size_t i = 0; i < strlen(inputExpression); i++)
    {
        resultingArray[i] = 0;
    }
    int currentIndexInResultingArray = 0;

    if (!convertInfixToPostfix(inputExpression, resultingArray, &currentIndexInResultingArray, shiftForOperators))
    {
        free(resultingArray);
        free(inputExpression);
        return 0;
    }

    char* resultingString = (char*) malloc(sizeof(char) * (2 * strlen(inputExpression) + 1));
    resultingString[0] = '\0';

    convertResultingArrayToString(resultingArray, currentIndexInResultingArray, shiftForOperators,
            strlen(inputExpression), resultingString);
    printf("This is your expression in postfix format:\n%s", resultingString);

    free(resultingString);
    free(resultingArray);
    free(inputExpression);
    return 0;
}