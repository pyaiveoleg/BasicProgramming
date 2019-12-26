#include <stdio.h>
#include <stdlib.h>

void swap(int array[], int firstElement, int secondElement)
{
    int temporary = array[firstElement];
    array[firstElement] = array[secondElement];
    array[secondElement] = temporary;
}

void heapFiltering(int array[], int root, int heapSize)
{
    int leftChild = root * 2 + 1;
    int rightChild = root * 2 + 2;
    int maxElement = root;

    if (leftChild < heapSize && array[leftChild] > array[maxElement])
    {
        maxElement = leftChild;
    }
    if (rightChild < heapSize && array[rightChild] > array[maxElement])
    {
        maxElement = rightChild;
    }

    if (maxElement != root)
    {
        swap(array, root, maxElement);
        heapFiltering(array, maxElement, heapSize);
    }
}

void heapSort(int array[], int arrayLength)
{
    int arrayMiddle = arrayLength / 2 - 1;
    for (int i = arrayMiddle; i >= 0; i--)
    {
        heapFiltering(array, i, arrayLength);
    }

    for (int i = arrayLength - 1; i >= 0; i--)
    {
        swap(array, 0, i);
        heapFiltering(array, 0, i);
    }
}

int main()
{
    int arrayLength = 0;
    printf("Please, write down the length of array: \n");
    scanf("%d", &arrayLength);
    int* array = (int*) malloc (sizeof(int) * arrayLength);
    for (int i = 0; i < arrayLength; i++)
    {
        array[i] = 0;
    }

    printf("Please, write down the array: \n");
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

    free(array);
    return 0;
}