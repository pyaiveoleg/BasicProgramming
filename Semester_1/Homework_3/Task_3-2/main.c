#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char* readString(bool* hasReachedEndOfFile, const int startingSizeOfString, FILE* input, char* inputString)
{
    int inputStringSize = startingSizeOfString;
    int i = 0;
    do
    {
        inputString[i] =  (char) fgetc(input);
        if (inputString[i] == EOF)
        {
            *hasReachedEndOfFile = true;
            i++;
            break;
        }

        i++;
        if (i >= inputStringSize)
        {
            inputStringSize *= 2;
            inputString = (char*) realloc (inputString, sizeof(char) * inputStringSize);
        }
    }
    while (inputString[i - 1] != '\n');
    inputString[i - 1] = '\0';

    return inputString;
}

void countNotEmptyStrings(FILE* input, const int startingSizeOfString, int* quantityOfNotEmptyStrings)
{
    size_t stringLength = 0;
    bool hasReachedEndOfFile = false;
    bool isEmpty = true;
    while (!hasReachedEndOfFile)
    {
        char* inputString = (char*) malloc(sizeof(char) * startingSizeOfString);
        inputString = readString(&hasReachedEndOfFile, startingSizeOfString, input, inputString);

        stringLength = strlen(inputString);

        for (size_t j = 0; j < stringLength; j++)
        {
            if ((inputString[j] != ' ') && (inputString[j] != '\t'))
            {
                isEmpty = false;
            }
        }

        if (!isEmpty && stringLength > 0)
        {
            (*quantityOfNotEmptyStrings)++;
        }
        free(inputString);
        isEmpty = true;
    }
}

int main()
{
    const int startingSizeOfString = 5;
    int quantityOfNotEmptyStrings = 0;

    FILE *input = fopen("input.txt", "r");

    if (!input)
    {
        printf("Error. Cannot open file.\n");
        return 0;
    }
    countNotEmptyStrings(input, startingSizeOfString, &quantityOfNotEmptyStrings);
    fclose(input);

    printf("Quantity of not-empty strings in the file: %d", quantityOfNotEmptyStrings);

    return 0;
}