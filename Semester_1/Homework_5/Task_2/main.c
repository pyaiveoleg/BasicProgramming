#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "CountExpressionInPostfix.h"

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
    const size_t startingSizeOfString = 1000;
    printf("Please, write down the expression:\n");
    char *inputExpression = readString(startingSizeOfString);

    double resultingValue = 0;
    if (!countValueOfWholeExpression(inputExpression, &resultingValue))
    {
        printf("Error.\n");
    }
    else
    {
        printf("Resulting value is %lf", resultingValue);
    }

    free(inputExpression);
    return 0;
}