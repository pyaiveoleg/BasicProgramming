#include <stdio.h>

void readArray(int array[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        scanf("%d", &array[i]);
    }
}

int main() {
    const int maxArrayLength = 1000;
    int arrayOfPetya[maxArrayLength];
    int arrayOfVasya[maxArrayLength];
    int mergedArray[maxArrayLength];
    for (int i = 0; i < maxArrayLength; i++)
    {
        arrayOfVasya[i] = 0;
        arrayOfPetya[i] = 0;
        mergedArray[i] = 0;
    }
    int firstArrayLength = 0;
    int secondArrayLength = 0;
    int maxElement = 0;
    int firstIndex = 0;
    int secondIndex = 0;
    int mergedIndex = 0;

    printf("Please, write down length of array of Petya\n");
    scanf("%d", &firstArrayLength);
    printf("Please, write down array of Petya\n");
    readArray(arrayOfPetya, firstArrayLength);

    printf("Please, write down length of array of Vasya\n");
    scanf("%d", &secondArrayLength);
    printf("Please, write down array of Vasya\n");
    readArray(arrayOfVasya, secondArrayLength);

    if (arrayOfPetya[0] > arrayOfVasya[0])
    {
        maxElement = arrayOfPetya[0];
    }
    else
    {
        maxElement = arrayOfVasya[0];
    }

    for (int i = maxElement; i >= 1; i--)
    {
        if ((arrayOfPetya[firstIndex] == i) || (arrayOfVasya[secondIndex] == i))
        {
            mergedArray[mergedIndex] = i;
            mergedIndex++;
        }
        if (arrayOfPetya[firstIndex] == i)
        {
            firstIndex++;
        }
        if (arrayOfVasya[secondIndex] == i)
        {
            secondIndex++;
        }
    }

    printf("There is merged array:\n");
    for (int i = 0; i < mergedIndex; i++)
    {
        printf("%d ", mergedArray[i]);
    }

    return 0;
}