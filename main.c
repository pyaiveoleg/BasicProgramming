#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertionSort(int array[], int arrayLength, int step)
{
    int currentElement = 0;
    int indexOfElement = 0;

    for (int i = step; i < arrayLength; i += step)
    {
        currentElement = array[i];
        indexOfElement = i - step;
        while((indexOfElement >= 0) && (array[indexOfElement] > currentElement))
        {
            array[indexOfElement + step] = array[indexOfElement];
            indexOfElement -= step;
        }
        array[indexOfElement + step] = currentElement;
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
    int i = -1;
    int codeOfAction = 0;
    const int step = 2;

    printf("If you want to type the array, press 0, if you want to generate array randomly, write down any other number\n");
    scanf("%d", &codeOfAction);
    if (codeOfAction == 0)
    {
        printf("Please, write down the array:\n");
        do
        {
            i++;
            scanf("%d", &array[i]);
        }
        while (array[i] != 0);
        arrayLength = i;
    }
    else
    {
        printf("Please, write down length of the array:\n");
        scanf("%d", &arrayLength);

        srand(time(NULL));
        const int minNumber = 11;
        const int maxNumber = 42;

        for (i = 0; i < arrayLength; i++)
        {
            array[i] = minNumber + rand() % (maxNumber - minNumber);
        }
    }

    insertionSort(array, arrayLength, step);

    printf("This is array, sorted with step 2:\n");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}