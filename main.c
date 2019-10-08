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
    int pointerInFirstArray = 0;
    int pointerInSecondArray = 0;
    int numberOfAddedElement = 0;

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
        if ((arrayOfPetya[pointerInFirstArray] == i) || (arrayOfVasya[pointerInSecondArray] == i))
        {
            mergedArray[numberOfAddedElement] = i;
            numberOfAddedElement++;
        }
        if (arrayOfPetya[pointerInFirstArray] == i)
        {
            pointerInFirstArray++;
        }
        if (arrayOfVasya[pointerInSecondArray] == i)
        {
            pointerInSecondArray++;
        }
    }

    int mergedArrayLength = numberOfAddedElement;
    printf("There is merged array:\n");
    for (int i = 0; i < mergedArrayLength; i++)
    {
        printf("%d ", mergedArray[i]);
    }

    return 0;
}