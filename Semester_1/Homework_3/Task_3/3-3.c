#include <stdio.h>


void swap(int firstElement, int secondElement, int array[])
{
    int temporary = array[firstElement];
    array[firstElement] = array[secondElement];
    array[secondElement] = temporary;
}

void putZerosToEnd(int array[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = i; j < arrayLength; j++)
        {
            if (array[i] == 0)
            {
                swap(i, j, array);
            }
        }
    }
}

int main() {
    const int maxArrayLength = 1000;
    int array[maxArrayLength];
    for (int i = 0; i < maxArrayLength; i++)
    {
        array[i] = 0;
    }
    int arrayLength = 0;

    printf("Please, write down the length of array: ");
    scanf("%d", &arrayLength);
    printf("Please, write down the array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        scanf("%d", &array[i]);
    }

    putZerosToEnd(array, arrayLength);

    printf("This is a sorted array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}