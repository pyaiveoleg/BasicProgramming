#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

void clearArray(int array[], int* sizeOfArray)
{
    for (int i = 0; i < *sizeOfArray; i++)
    {
        array[i] = 0;
    }
    *sizeOfArray = 0;
}

void printGreetingMessage()
{
    printf("There are following commands:\n");
    printf("Type: 1 to add integer to set\n");
    printf("Type: 2 to delete integer from set\n");
    printf("Type: 3 to check if this integer in set\n");
    printf("Type: 4 to print elements of set in this order\n");
    printf("Type: 5 to print elements of set in this order\n");
    printf("Type: 6 to print elements of set in this order\n");
    printf("Type: 0 to close the program\n");
}

int main()
{
    printf("If you don't know how to use it, type '-1'\n");

    const int maxLengthOfCommand = 1000;
    const int maxSizeOfSet = 1000;
    int inputCommand = 0;

    Tree* set = createTree();
    int numberToAdd = 0;
    int numberToDelete = 0;
    int numberToCheck = 0;
    bool isCommand = false;

    int elementsOfSet[maxSizeOfSet];
    int currentArraySize;
    clearArray(elementsOfSet, &currentArraySize);
    while (true)
    {
        scanf("%d", &inputCommand);

        if (inputCommand == -1)
        {
            printGreetingMessage();
        }
        else if (inputCommand == 1)
        {
            printf("Write down number to add:\n");
            scanf("%d", &numberToAdd);
            isCommand = true;
            addElement(set, numberToAdd);
            printf("Successfully added\n");
        }
        else if (inputCommand == 2)
        {
            printf("Write down number to delete:\n");
            scanf("%d", &numberToDelete);
            isCommand = true;
            deleteElement(set, numberToDelete);
            printf("Successfully deleted\n");
        }
        else if (inputCommand == 3)
        {
            printf("Write down number to check:\n");
            scanf("%d", &numberToCheck);
            isCommand = true;
            printf(findElement(set, numberToCheck) ? "Element exists\n" : "Element haven't found\n");
        }
        else if (inputCommand == 4)
        {
            getSymmetricOrder(set, elementsOfSet, &currentArraySize);
            for (int i = 0; i < currentArraySize; i++)
            {
                printf("%d ", elementsOfSet[i]);
            }
            printf("\n");
            clearArray(elementsOfSet, &currentArraySize);
        }
        else if (inputCommand == 5)
        {
            getSymmetricOrder(set, elementsOfSet, &currentArraySize);
            for (int i = currentArraySize - 1; i > 0; i--)
            {
                printf("%d ", elementsOfSet[i]);
            }
            printf("\n");
            clearArray(elementsOfSet, &currentArraySize);
        }
        else if (inputCommand == 6)
        {
            printInABCOrder(set);
        }
        else if (inputCommand == 7)
        {
            return 0;
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