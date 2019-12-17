#include <stdio.h>
#include <stdlib.h>

void swap(int first, int second, int array[])
{
    int temporary = array[first];
    array[first] = array[second];
    array[second] = temporary;
}

void quickSort(int array[], int left, int right) {
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

int* readArrayWithZeroOnEnd(int* quantityOfNumbersInArray, const int startingSizeOfArray)
{
    int* array = (int*) malloc(sizeof(int) * startingSizeOfArray);
    int maxArraySize = startingSizeOfArray;
    int inputNumber = 1;

    for (int i = 0; inputNumber != 0; i++)
    {
        scanf("%d", &inputNumber);
        if (inputNumber == 0)
        {
            break;
        }

        (*quantityOfNumbersInArray)++;
        if (*quantityOfNumbersInArray == maxArraySize)
        {
            maxArraySize *= 2;
            array = (int*) realloc(array, sizeof(int) * maxArraySize);
        }
        array[i] = inputNumber;
    }

    return array;
}

void printSortedArrayWithQuantityOfElements(int* array, int quantityOfNumbersInArray)
{
    int currentNumber = array[0];
    int quantityOfCurrentNumber = 1;
    for (int i = 1; i < quantityOfNumbersInArray; i++)
    {
        if (array[i] == currentNumber)
        {
            quantityOfCurrentNumber++;
            continue;
        }
        printf("%d, repeated %d times\n", currentNumber, quantityOfCurrentNumber);
        currentNumber = array[i];
        quantityOfCurrentNumber = 1;
    }
    printf("%d, repeated %d times\n", currentNumber, quantityOfCurrentNumber);//на последней итерации нужно вывести
}

int main()
{
    const int startingSizeOfArray = 10;
    printf("Please, write down sequence of integers with 0 at the end:\n");
    int quantityOfNumbersInArray = 0;
    int* array = readArrayWithZeroOnEnd(&quantityOfNumbersInArray, startingSizeOfArray);

    quickSort(array, 0, quantityOfNumbersInArray - 1);

    printf("There is sorted array without repeating elements.\n");
    printf("There is quantity of each number in original array right to number in each line.\n");
    printSortedArrayWithQuantityOfElements(array, quantityOfNumbersInArray);

    free(array);
    return 0;
}
