#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

double** createTwoDimensionalArray(int height, int width, int defaultValue)
{
    double** newArray = (double**) malloc(sizeof(double*) * height);

    for (int i = 0; i < height; i++)
    {
        newArray[i] = (double*) malloc(sizeof(double) * width);
        for (int j = 0; j < width; j++)
        {
            newArray[i][j] = defaultValue;
        }
    }
    return newArray;
}

void deleteTwoDimensionalArray(double** array, int height)
{
    for (int i = 0; i < height; ++i)
    {
        free(array[i]);
    }
    free(array);
}

int main()
{
    int width = 0;
    int height = 0;
    printf("Please, write down width and height of array:\n");
    scanf("%d %d", &width, &height);
    double** array = createTwoDimensionalArray(height, width, 0);

    double maxInColumn[width];
    for (int i = 0; i < width; i++)
    {
        maxInColumn[i] = 0;
    }

    double minInLine[height];
    for (int i = 0; i < height; i++)
    {
        minInLine[i] = 0;
    }//createOneDimensionalArray - dont't forget!

    printf("Please, write down the two-dimensional array:\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            scanf("%lf", &array[i][j]);
            if (array[i][j] > maxInColumn[j] || i == 0)//инциализируем maxInColumn[j] первым элементом столбца
            {
                maxInColumn[j] = array[i][j];
            }
            if (array[i][j] < minInLine[i] || j == 0)//инициализируем minInLine[i] первым элементом строки
            {
                minInLine[i] = array[i][j];
            }
        }
    }

    printf("There are indexes (X Y) of elements that are saddle points of array:\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (array[i][j] == maxInColumn[j] && array[i][j] == minInLine[i])
            {
                printf("(%d %d)\n", i, j);
            }
        }
    }

    deleteTwoDimensionalArray(array, height);
    return 0;
}
