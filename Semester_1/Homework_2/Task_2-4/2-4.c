#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void * x1, const void * x2)   // функция сравнения элементов массива
{
    return ( *(int*)x1 - *(int*)x2 );
}

int main() {
    const int maxArraySize = 1000;
    int array[maxArraySize];
    for (int i = 0; i < maxArraySize; i++)
    {
        array[i] = 0;
    }
    int maxRepeatingElement = 0;
    int arrayLength = 0;
    bool isFound = false;

    printf("Please, write down length of the array: \n");
    scanf("%d", &arrayLength);

    printf("Please, write down array: \n");
    for (int i = 0; i < arrayLength; i++)
    {
        scanf("%d", &array[i]);
    }

    qsort(array, arrayLength, sizeof(int), compare);

    int checkingElement = arrayLength - 1;
    while (!isFound)
    {
        if (checkingElement == 0)
        {
            printf("There aren't repeating elements in this array.\n");
            return 0;
        }
        if (array[checkingElement] == array[checkingElement - 1])
        {
            maxRepeatingElement = array[checkingElement];
            isFound = true;
        }
        checkingElement--;
    }

    printf("There is maximal repeating element in this array: %d", maxRepeatingElement);

    return 0;
}