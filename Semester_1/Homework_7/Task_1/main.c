#include <stdio.h>
#include <stdbool.h>
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
    printf("Type: 1 to add integer to set\n");
    printf("Type: 2 to delete integer from set\n");
    printf("Type: 3 to check if this integer in set\n");
    printf("Type: 4 to print elements of set in ascending order\n");
    printf("Type: 5 to print elements of set in descending order\n");
    printf("Type: 6 to print elements of set in (a b c) order\n");
    printf("Type: 0 to close the program\n");
}

void add(bool* isCommand, Tree* set)
{
    int numberToAdd = 0;
    printf("Write down number to add:\n");
    scanf("%d", &numberToAdd);
    *isCommand = true;
    addElement(set, numberToAdd);
    printf("Successfully added\n");
}

void deleteFromSet(bool* isCommand, Tree* set)
{
    int numberToDelete = 0;
    printf("Write down number to delete:\n");
    scanf("%d", &numberToDelete);
    *isCommand = true;
    deleteElement(set, numberToDelete);
    printf("Successfully deleted\n");
}

void check(bool* isCommand, Tree* set)
{
    int numberToCheck = 0;
    printf("Write down number to check:\n");
    scanf("%d", &numberToCheck);
    *isCommand = true;
    bool existenceOfElement = false;
    findElement(set, numberToCheck, &existenceOfElement);
    printf(existenceOfElement ? "Element exists\n" : "Element haven't found\n");
}

void printAscendingOrder(bool* isCommand, Tree* set, const int startingSizeOfArray)
{
    *isCommand = true;
    int currentArraySize = 0;
    int maxArraySize = startingSizeOfArray;
    int* elementsOfSet = malloc(sizeof(int) * maxArraySize);
    clearArray(elementsOfSet, &currentArraySize, &maxArraySize, startingSizeOfArray);

    getSymmetricOrder(set, elementsOfSet, &currentArraySize, &maxArraySize);
    if (currentArraySize == 0)
    {
        printf("Tree is empty.");
    }
    else
    {
        for (int i = 0; i < currentArraySize; i++)
        {
            printf("%d ", elementsOfSet[i]);
        }
    }
    printf("\n");
    free(elementsOfSet);
}

void printDescendingOrder(bool* isCommand, Tree* set, const int startingSizeOfArray)
{
    *isCommand = true;
    int currentArraySize = 0;
    int maxArraySize = startingSizeOfArray;
    int* elementsOfSet = malloc(sizeof(int) * maxArraySize);
    clearArray(elementsOfSet, &currentArraySize, &maxArraySize, startingSizeOfArray);

    getSymmetricOrder(set, elementsOfSet, &currentArraySize, &maxArraySize);
    if (currentArraySize == 0)
    {
        printf("Tree is empty.");
    }
    else
    {
        for (int i = currentArraySize - 1; i >= 0; i--)
        {
            printf("%d ", elementsOfSet[i]);
        }
    }
    printf("\n");
    free(elementsOfSet);
}

void printABCOrder(bool* isCommand, Tree* set)
{
    *isCommand = true;
    bool isTreeEmpty = false;
    printInABCOrder(set, &isTreeEmpty);
    if (isTreeEmpty)
    {
        printf("Tree is empty.");
    }
    printf("\n");
}

void workWithSet(Tree* set, const int startingSizeOfArray)
{
    int inputCommand;
    bool isCommand = false;

    while (true)
    {
        scanf("%d", &inputCommand);

        if (inputCommand == -1)
        {
            printGreetingMessage();
        }
        else if (inputCommand == 1)
        {
            add(&isCommand, set);
        }
        else if (inputCommand == 2)
        {
            deleteFromSet(&isCommand, set);
        }
        else if (inputCommand == 3)
        {
            check(&isCommand, set);
        }
        else if (inputCommand == 4)
        {
            printAscendingOrder(&isCommand, set, startingSizeOfArray);
        }
        else if (inputCommand == 5)
        {
            printDescendingOrder(&isCommand, set, startingSizeOfArray);
        }
        else if (inputCommand == 6)
        {
            printABCOrder(&isCommand, set);
        }
        else if (inputCommand == 0)
        {
            break;
        }
        else if (!isCommand)
        {
            printf("Invalid command\n");
        }
        else
        {
            isCommand = false;
        }
    }
}

int main()
{
    printf("If you don't know how to use it, type '-1'\n");

    const int startingSizeOfArray = 10;
    Tree* set = createTree();

    workWithSet(set, startingSizeOfArray);
    deleteTree(&set);

    return 0;
}