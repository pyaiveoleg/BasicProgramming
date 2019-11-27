#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "AVLtree.h"

void clearArray(int* array, int* sizeOfArray, int* maxSizeOfArray, const int staringSizeOfArray)
{
    free(array);
    array = malloc(sizeof(int) * staringSizeOfArray);
    for (int i = 0; i < staringSizeOfArray; i++)
    {
        array[i] = 0;
    }
    *sizeOfArray = 0;
    *maxSizeOfArray = staringSizeOfArray;
}

void printGreetingMessage()
{
    printf("There are following commands:\n");
    printf("Type: Add to add integer to set\n");
    printf("Type: Delete to delete integer from set\n");
    printf("Type: Check to check if this integer in set\n");
    printf("Type: Print in Ascending Order to print elements of set in this order\n");
    printf("Type: Print in Descending Order to print elements of set in this order\n");
    printf("Type: Print in (a b c) Order to print elements of set in this order\n");
    printf("Type: Exit to close the program\n");
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

void workWithSet(Tree* set, const int startingSizeOfString, const int startingSizeOfArray)
{
    char* inputCommand;
    int numberToAdd = 0;
    int numberToDelete = 0;
    int numberToCheck = 0;
    bool isCommand = false;

    int currentArraySize = 0;
    int maxArraySize = startingSizeOfArray;
    int* elementsOfSet = malloc(sizeof(int) * maxArraySize);
    clearArray(elementsOfSet, &currentArraySize, &maxArraySize, startingSizeOfArray);

    while (true)
    {
        inputCommand = readString(startingSizeOfString);

        if (strcmp(inputCommand, "Help") == 0)
        {
            printGreetingMessage();
        }
        else if (strcmp(inputCommand, "Add") == 0)
        {
            printf("Write down number to add:\n");
            scanf("%d", &numberToAdd);
            isCommand = true;
            addElement(set, numberToAdd);
            printf("Successfully added\n");
        }
        else if (strcmp(inputCommand, "Delete") == 0)
        {
            printf("Write down number to delete:\n");
            scanf("%d", &numberToDelete);
            isCommand = true;
            deleteElement(set, numberToDelete);
            printf("Successfully deleted\n");
        }
        else if (strcmp(inputCommand, "Check") == 0)
        {
            printf("Write down number to check:\n");
            scanf("%d", &numberToCheck);
            isCommand = true;
            bool existenceOfElement = false;
            findElement(set, numberToCheck, &existenceOfElement);
            printf(existenceOfElement ? "Element exists\n" : "Element haven't found\n");
        }
        else if (strcmp(inputCommand, "Print in Ascending Order") == 0)
        {
            getSymmetricOrder(set, elementsOfSet, &currentArraySize, &maxArraySize);
            for (int i = 0; i < currentArraySize; i++)
            {
                printf("%d ", elementsOfSet[i]);
            }
            printf("\n");
            clearArray(elementsOfSet, &currentArraySize, &maxArraySize, startingSizeOfArray);
        }
        else if (strcmp(inputCommand, "Print in Descending Order") == 0)
        {
            getSymmetricOrder(set, elementsOfSet, &currentArraySize, &maxArraySize);
            for (int i = currentArraySize - 1; i > 0; i--)
            {
                printf("%d ", elementsOfSet[i]);
            }
            printf("\n");
            clearArray(elementsOfSet, &currentArraySize, &maxArraySize, startingSizeOfArray);
        }
        else if (strcmp(inputCommand, "Print in (a b c) Order") == 0)
        {
            printInABCOrder(set);
        }
        else if (strcmp(inputCommand, "Exit") == 0)
        {
            deleteTree(set);
            free(elementsOfSet);
            free(inputCommand);
            return;
        }
        else if (!isCommand)
        {
            printf("Invalid command\n");
        }
        else
        {
            isCommand = false;
        }

        free(inputCommand);
    }
}

int main()
{
    printf("If you don't know how to use it, type 'Help'\n");

    const int startingSizeOfString = 10;
    const int startingSizeOfArray = 10;
    Tree* set = createTree();

    workWithSet(set, startingSizeOfString, startingSizeOfArray);

    return 0;
}