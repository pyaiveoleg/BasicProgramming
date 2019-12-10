#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool isDigit(char symbol)
{
    return (symbol >= '0') && (symbol <= '9');
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

bool isRealNumber(char* inputString)
{
    char currentSymbol = '\0';
    int state = 0;

    for (int index = 0; index <= strlen(inputString); index++)
    {
        currentSymbol = inputString[index];
        if (currentSymbol == ' ')
        {
            continue;
        }
        
        switch (state)
        {
            case 0: //start
                if (currentSymbol == '+' || currentSymbol == '-')
                {
                    state = 1;
                    break;
                }
                else if (isDigit(currentSymbol))
                {
                    state = 2;
                    break;
                }
                else
                {
                    return false;
                }
            case 1:
                if (isDigit(currentSymbol))
                {
                    state = 2;
                    break; //state неизменный
                }
                else
                {
                    return false;
                }
            case 2:
                if (isDigit(currentSymbol))
                {
                    break; //state неизменный
                }
                else if (currentSymbol == '\0')
                {
                    return true;
                }
                else if (currentSymbol == '.')
                {
                    state = 3;
                    break;
                }
                else
                {
                    return false;
                }
            case 3:
                if (isDigit(currentSymbol))
                {
                    state = 4;
                    break;
                }
                else
                {
                    return false;
                }
            case 4:
                if (isDigit(currentSymbol))
                {
                    break;
                }
                else if (currentSymbol == '\0')
                {
                    return true;
                }
                else if (currentSymbol == 'E')
                {
                    state = 5;
                    break;
                }
                else
                {
                    return false;
                }
            case 5:
                if (currentSymbol == '+' || currentSymbol == '-')
                {
                    state = 6;
                    break;
                }
                else if (isDigit(currentSymbol))
                {
                    state = 7;
                    break;
                }
                else
                {
                    return false;
                }
            case 6:
                if (isDigit(currentSymbol))
                {
                    state = 7;
                }
                else
                {
                    return false;
                }
            case 7:
                if (isDigit(currentSymbol))
                {
                    break; //state неизменный
                }
                else if (currentSymbol == '\0')
                {
                    return true;
                }
                else
                {
                    return false;
                }
        }
    }

    return true;
}

int main()
{
    const int startingSizeOfString = 10;

    printf("Please, write down string for analyse\n");
    char* inputString = readString(startingSizeOfString);

    if (isRealNumber(inputString))
    {
        printf("This is real number.\n");
    }
    else
    {
        printf("This is not a real number.\n");
    }

    free(inputString);
    return 0;
}
