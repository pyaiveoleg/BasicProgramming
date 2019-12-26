#include <stdio.h>

void swap(int firstElement, int secondElement, int array[])
{
    int temporary = array[firstElement];
    array[firstElement] = array[secondElement];
    array[secondElement] = temporary;
}

void reverse(int start, int end, int array[])
{
    int endOfCycle = (start + end) / 2;
    for (int i = start; i < endOfCycle; i++)
    {
        swap(i, start + end - 1 - i, array);
    }
}

int main()
{
    const int maxArraySize = 1000;
    int array[maxArraySize];
    for (int i = 0; i < maxArraySize; i++)
    {
        array[i] = 0;
    }
    int beginningLength = 0;
    int endingLength = 0;

    printf("Please, write down length of beginning (M) and ending (N) of the array: ");
    scanf("%d %d", &beginningLength, &endingLength);
    int arrayLength = beginningLength + endingLength;

    printf("Please, write down array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        scanf("%d", &array[i]);
    }

    reverse(0, beginningLength, array);
    reverse(beginningLength, arrayLength, array);
    reverse(0, arrayLength, array);

    printf("Parsed array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
