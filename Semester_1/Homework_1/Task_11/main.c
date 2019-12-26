#include <stdio.h>

void swap(int firstElement, int secondElement, int array[])
{
    int temporary = array[firstElement];
    array[firstElement] = array[secondElement];
    array[secondElement] = temporary;
}

void quickSort(int array[], int left, int right)
{
    int sample = array[(left + right) / 2];
    int i = left;
    int j = right;

    do
    {
        while (array[i] < sample)
        {
            i++;
        }
        while (array[j] > sample)
        {
            j--;
        }
        if (i <= j)
        {
            if (array[i] > array[j])
            {
                swap(i, j, array);
            }
            i++;
            if (j > 0)
            {
                j--;
            }
        }
    }
    while (i <= j);

    if (i < right)
    {
        quickSort(array, i, right);
    }
    if (j > left)
    {
        quickSort(array, left, j);
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

    printf("Please, write down the length of array: ");
    scanf("%d", &arrayLength);
    printf("Please, write down the array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        scanf("%d", &array[i]);
    }

    quickSort(array, 0, arrayLength - 1);

    printf("This is a sorted array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}