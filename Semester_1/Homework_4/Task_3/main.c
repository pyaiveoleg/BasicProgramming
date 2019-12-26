#include <stdio.h>

void printHorizontalInterval(int array[][100], int lengthOfInterval, int* startX, int* startY, char direction[])
{
    if (direction == "right")
    {
        for (int j = 1; j <= lengthOfInterval; j++)
        {
            printf("%d ", array[*startX][*startY + j]);
        }
        *startY += lengthOfInterval;
    }
    else
    {
        for (int j = 1; j <= lengthOfInterval; j++)
        {
            printf("%d ", array[*startX][*startY - j]);
        }
        *startY -= lengthOfInterval;
    }
}

void printVerticalInterval(int array[][100], int lengthOfInterval, int* startX, int* startY, char direction[])
{
    if (direction == "down")
    {
        for (int j = 1; j <= lengthOfInterval; j++)
        {
            printf("%d ", array[*startX + j][*startY]);
        }
        *startX += lengthOfInterval;
    }
    else
    {
        for (int j = 1; j <= lengthOfInterval; j++)
        {
            printf("%d ", array[*startX - j][*startY]);
        }
        *startX -= lengthOfInterval;
    }
}

int main() {
    const int maxArraySize = 100;
    int array[maxArraySize][maxArraySize];
    for (int i = 0; i < maxArraySize; i++)
    {
        for (int j = 0; j < maxArraySize; j++)
        {
            array[i][j] = 0;
        }
    }
    int lengthOfInterval = 0;
    int arraySize = 0;

    printf("Please, write down size of the array:\n");
    scanf("%d", &arraySize);
    printf("Please, write down the array:\n");
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    int startX = arraySize / 2;
    int startY = arraySize / 2;
    printf("There are numbers from array on spiral starting in center:\n");
    printf("%d ", array[startX][startY]);
    for (int i = 0; i <= arraySize - 3; i++)
    {
        lengthOfInterval++;
        printHorizontalInterval(array, lengthOfInterval, &startX, &startY, "right");
        printVerticalInterval(array, lengthOfInterval, &startX, &startY, "down");

        lengthOfInterval++;
        printHorizontalInterval(array, lengthOfInterval, &startX, &startY, "left");
        printVerticalInterval(array, lengthOfInterval, &startX, &startY, "up");
    }
    printHorizontalInterval(array, lengthOfInterval, &startX, &startY, "right");

    return 0;
}