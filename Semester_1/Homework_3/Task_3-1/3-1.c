#include <stdio.h>
#include <stdbool.h>

void swap(int array[], int firstElement, int secondElement)
{
    int temporary = array[firstElement];
    array[firstElement] = array[secondElement];
    array[secondElement] = temporary;
}

void heapFiltering(int array[], int root, int bottom)
{
    int maxChild = 0;
    bool isFormed = false;

    while ((root * 2 <= bottom) && (!isFormed))
    {
        if (root * 2 == bottom)
        {
            maxChild = root * 2;
        }
        else if (array[root * 2] > array[root * 2 + 1])
        {
            maxChild = root * 2;
        }
        else
        {
            maxChild = root * 2 + 1;
        }

        if (array[root] < array[maxChild])
        {
            swap(array, root, maxChild);
            root = maxChild;
        }
        else
        {
            isFormed = true;
        }
    }
}

void heapSort(int array[], int arrayLength)
{
    for (int i = arrayLength / 2 - 1; i >= 0; i--)
    {
        heapFiltering(array, i, arrayLength - 1);
    }

    for (int i = arrayLength - 1; i >= 1; i--)
    {
        swap(array, 0, i);
        heapFiltering(array, 0, i - 1);
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

    heapSort(array, arrayLength);

    printf("This is a sorted array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}