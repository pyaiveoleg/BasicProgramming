#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum State State;
enum State
{
    start,
    firstDigit,
    integerPart,
    dotInMantissa,
    fractionalPart,
    charE,
    firstDigitOfExponent,
    integerPartOfExponent,
    success,
    error
};

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

void signParsing(char currentSymbol, State* state)
{
    if (currentSymbol == '+' || currentSymbol == '-')
    {
        *state = firstDigit;
    }
    else if (isDigit(currentSymbol))
    {
        *state = integerPart;
    }
    else
    {
        *state = error;
    }
}

void firstDigitParsing(char currentSymbol, State* state)
{
    if (isDigit(currentSymbol))
    {
        *state = integerPart;
    }
    else
    {
        *state = error;
    }
}

void integerPartParsing(char currentSymbol, State* state)
{
    if (isDigit(currentSymbol))
    {
        return; //state неизменный
    }
    else if (currentSymbol == '\0')
    {
        *state = success;
    }
    else if (currentSymbol == '.')
    {
        *state = dotInMantissa;
    }
    else
    {
        *state = error;
    }
}

void dotInMantissaParsing(char currentSymbol, State* state)
{
    if (isDigit(currentSymbol))
    {
        *state = fractionalPart;
    }
    else
    {
        *state = error;
    }
}

void fractionalPartParsing(char currentSymbol, State* state)
{
    if (isDigit(currentSymbol))
    {
        return; //state неизменный
    }
    else if (currentSymbol == '\0')
    {
        *state = success;
    }
    else if (currentSymbol == 'E')
    {
        *state = charE;
    }
    else
    {
        *state = false;
    }
}

void charEParsing(char currentSymbol, State* state)
{
    if (currentSymbol == '+' || currentSymbol == '-')
    {
        *state = firstDigitOfExponent;
    }
    else if (isDigit(currentSymbol))
    {
        *state = integerPartOfExponent;
    }
    else
    {
        *state = error;
    }
}

void firstDigitOfExponentParsing(char currentSymbol, State* state)
{
    if (isDigit(currentSymbol))
    {
        *state = integerPartOfExponent;
    }
    else
    {
        *state = false;
    }
}

void integerPartOfExponentParsing(char currentSymbol, State* state)
{
    if (isDigit(currentSymbol))
    {
        return; //state неизменный
    }
    else if (currentSymbol == '\0')
    {
        *state = true;
    }
    else
    {
        *state = false;
    }
}

bool isRealNumber(char* inputString)
{
    char currentSymbol = '\0';
    State state = start;

    for (int index = 0; index <= strlen(inputString); index++)
    {
        currentSymbol = inputString[index];
        if (currentSymbol == ' ')
        {
            continue;
        }
        switch (state)
        {
            case start:
            {
                signParsing(currentSymbol, &state);
                break;
            }
            case firstDigit:
            {
                firstDigitParsing(currentSymbol, &state);
                break;
            }
            case integerPart:
            {
                integerPartParsing(currentSymbol, &state);
                break;
            }
            case dotInMantissa:
            {
                dotInMantissaParsing(currentSymbol, &state);
                break;
            }
            case fractionalPart:
            {
                fractionalPartParsing(currentSymbol, &state);
                break;
            }
            case charE:
            {
                charEParsing(currentSymbol, &state);
                break;
            }
            case firstDigitOfExponent:
            {
                firstDigitOfExponentParsing(currentSymbol, &state);
                break;
            }
            case integerPartOfExponent:
            {
                integerPartOfExponentParsing(currentSymbol, &state);
                break;
            }
            case success:
            {
                return true;
            }
            case error:
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
