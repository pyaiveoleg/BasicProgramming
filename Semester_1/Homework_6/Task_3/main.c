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
    printf("Type: Add to add integer to set\n");
    printf("Type: Delete to delete integer from set\n");
    printf("Type: Check to check if this integer in set\n");
    printf("Type: Print in Ascending Order to print elements of set in this order\n");
    printf("Type: Print in Descending Order to print elements of set in this order\n");
    printf("Type: Print in (a b c) Order to print elements of set in this order\n");
    printf("Type: Exit to close the program\n");
}

int main() {
    printf("If you don't know how to use it, type 'Help'\n");

    const int maxLengthOfCommand = 1000;
    const int maxSizeOfSet = 1000;
    char inputCommand[maxLengthOfCommand];


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
        gets(inputCommand);
        //scanf("\n");
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
            printf(findElement(set, numberToCheck) ? "Element exists\n" : "Element haven't found\n");
        }
        else if (strcmp(inputCommand, "Print in Ascending Order") == 0)
        {
            getSymmetricOrder(set, elementsOfSet, &currentArraySize);
            for (int i = 0; i < currentArraySize; i++)
            {
                printf("%d ", elementsOfSet[i]);
            }
            printf("\n");
            clearArray(elementsOfSet, &currentArraySize);
        }
        else if (strcmp(inputCommand, "Print in Descending Order") == 0)
        {
            getSymmetricOrder(set, elementsOfSet, &currentArraySize);
            for (int i = currentArraySize - 1; i > 0; i--)
            {
                printf("%d ", elementsOfSet[i]);
            }
            printf("\n");
            clearArray(elementsOfSet, &currentArraySize);
        }
        else if (strcmp(inputCommand, "Print in (a b c) Order") == 0)
        {
            printf("1");
        }
        else if (strcmp(inputCommand, "Exit") == 0)
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