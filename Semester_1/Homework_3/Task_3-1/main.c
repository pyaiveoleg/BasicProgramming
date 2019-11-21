#include <stdio.h>

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

    if ((leftChild < heapSize) && (array[leftChild] > array[maxElement]))
    {
        maxElement = leftChild;
    }
    if ((rightChild < heapSize) && (array[rightChild] > array[maxElement]))
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
    for (int i = arrayLength / 2 - 1; i >= 0; i--)
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
    const int maxArrayLength = 1000;
    int array[maxArrayLength];
    for (int i = 0; i < maxArrayLength; i++)
    {
        array[i] = 0;
    }
    int arrayLength = 0;

    printf("Please, write down the length of array: \n");
    scanf("%d", &arrayLength);
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

    return 0;
}