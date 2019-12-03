#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* readStringFromFile(bool* hasReachedEndOfFile, const int startingSizeOfString, FILE* input)
{
    char* inputString = (char*) malloc(sizeof(char) * startingSizeOfString);
    int inputStringSize = startingSizeOfString;
    int i = 0;
    do
    {
        inputString[i] =  (char) fgetc(input);
        if (inputString[i] == EOF)
        {
            *hasReachedEndOfFile = true;
            break;
        }

        i++;
        if (i >= inputStringSize)
        {
            inputStringSize *= 2;
            inputString = (char*) realloc (inputString, sizeof(char) * inputStringSize);
        }
    }
    while (inputString[i - 1] != ' ');
    inputString[i - 1] = '\0';

    return inputString;
}

void swap(char** surnames, int* loyalties, int firstNumber, int secondNumber)
{
    char* temporaryString = surnames[firstNumber];
    surnames[firstNumber] = surnames[secondNumber];
    surnames[secondNumber] = temporaryString;

    int temporaryInt = loyalties[firstNumber];
    loyalties[firstNumber] = loyalties[secondNumber];
    loyalties[secondNumber] = temporaryInt;
}

void sortArray(char** surnames, int* loyalties, int quantityOfPeople, const char* parameter)
{
    for (int i = 0; i < quantityOfPeople; i++)
    {
        for (int j = i; j < quantityOfPeople; j++)
        {
            if ((strcmp(parameter, "loyalties") == 0 && loyalties[j] > loyalties[i])          //сортировка по лояльностям
             || (strcmp(parameter, "surnames") == 0 && strcmp(surnames[j], surnames[i]) > 0)) //сортировка по фамилиям
            {
                swap(surnames, loyalties, i, j);
            }
        }
    }
}

void readInputFromFile(char** surnames, int* loyalties, FILE* input, const int startingSizeOfString,
                        int* quantityOfPeople, int* currentSizeOfArray)
{
    int iterator = 0;
    bool hasReachedEndOfFile = false;
    while (!hasReachedEndOfFile)
    {
        surnames[iterator] = readStringFromFile(&hasReachedEndOfFile, startingSizeOfString, input);
        fscanf(input, "- %d\n", &loyalties[iterator]);
        iterator++;
        if (iterator >= *currentSizeOfArray)
        {
            (*currentSizeOfArray) *= 2;
            surnames = realloc(surnames, sizeof(char*) * (*currentSizeOfArray));
            loyalties = realloc(loyalties, sizeof(int) * (*currentSizeOfArray));
        }
    }
    *quantityOfPeople = iterator - 1;
}

void printKilledPeople(char** surnames, int quantityOfPeople, int quantityToKill, int* quantityOfNotKilledPeople)
{
    printf("These people will be killed:\n");
    for (int j = quantityOfPeople - 1; j > quantityOfPeople - 1 - quantityToKill; j--)
    {
        printf("%s\n", surnames[j]);
        (*quantityOfNotKilledPeople)--;
    }
}

void printExiledPeople(char** surnames, int quantityOfNotKilledPeople, int quantityToExile, int* quantityOfHappyPeople)
{
    printf("These people will be exiled to Siberia:\n");
    for (int j = quantityOfNotKilledPeople - 1; j > quantityOfNotKilledPeople - 1 - quantityToExile; j--)
    {
        printf("%s\n", surnames[j]);
        (*quantityOfHappyPeople)--;
    }
}

void printHappyPeople(char** surnames, int quantityOfHappyPeople)
{
    printf("These people will be safe and sound. May be.\n");
    for (int j = quantityOfHappyPeople - 1; j >= 0; j--)
    {
        printf("%s\n", surnames[j]);
    }
}

int main()
{
    const int startingSizeOfString = 10;
    const int startingSizeOfArray = 10;

    int currentSizeOfArray = startingSizeOfArray;
    char** surnames = (char**) malloc(sizeof(char*) * currentSizeOfArray);
    int* loyalties = (int*) malloc(sizeof(int) * currentSizeOfArray);

    FILE* input = fopen("names and loyalty.txt", "r");
    if (!input)
    {
        printf("Error. Cannot open file.\n");
        return 0;
    }

    int quantityOfPeople = 0;
    readInputFromFile(surnames, loyalties, input, startingSizeOfString, &quantityOfPeople, &currentSizeOfArray);
    fclose(input);

    printf("Please, write down quantity to kill (N) and to exile to Siberia (M):\n");
    int quantityToKill = 0;
    int quantityToExile = 0;
    scanf("%d %d", &quantityToKill, &quantityToExile);
    if (quantityToKill + quantityToExile > quantityOfPeople)
    {
        printf("N + M need to be less than quantity of people in file.");
        return 0;
    }

    sortArray(surnames, loyalties, quantityOfPeople, "loyalties");
    int quantityOfNotKilledPeople = quantityOfPeople;
    printKilledPeople(surnames, quantityOfPeople, quantityToKill, &quantityOfNotKilledPeople);

    sortArray(surnames, loyalties, quantityOfNotKilledPeople, "surnames");
    int quantityOfHappyPeople = quantityOfNotKilledPeople;
    printExiledPeople(surnames, quantityOfNotKilledPeople, quantityToExile, &quantityOfHappyPeople);

    printHappyPeople(surnames, quantityOfHappyPeople);

    for (int i = 0; i < currentSizeOfArray; i++)
    {
        free(surnames[i]);
    }
    free(surnames);
    free(loyalties);

    return 0;
}
