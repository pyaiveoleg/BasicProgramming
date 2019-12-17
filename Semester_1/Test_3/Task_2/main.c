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

double* createOneDimensionalArray(int size, double defaultValue)
{
    double* newArray = (double*) malloc(sizeof(double) * size);
    for (int i = 0; i < size; i++)
    {
        newArray[i] = defaultValue;
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

void printSaddlePoints(double** array, const double* maxInColumn, const double* minInLine, int height, int width)
{
    printf("There are indexes (X Y) of elements (and elements itself) that are saddle points of array:\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (array[i][j] == maxInColumn[j] && array[i][j] == minInLine[i])
            {
                printf("(%d %d %lf)\n", i, j, array[i][j]);
            }
        }
    }
}

void readArray(double** array, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            scanf("%lf", &array[i][j]);
        }
    }
}

void countMaxInColumnsAndMinInLines(double** array, int height, int width, double* maxInColumn, double* minInLine)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
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
}

int main()
{
    int width = 0;
    int height = 0;
    printf("Please, write down width and height of array:\n");
    scanf("%d %d", &width, &height);
    double** array = createTwoDimensionalArray(height, width, 0);

    double* maxInColumn = createOneDimensionalArray(width, 0);
    double* minInLine = createOneDimensionalArray(height, 0);

    printf("Please, write down the two-dimensional array:\n");
    readArray(array, height, width);
    countMaxInColumnsAndMinInLines(array, height, width, maxInColumn, minInLine);
    printSaddlePoints(array, maxInColumn, minInLine, height, width);

    deleteTwoDimensionalArray(array, height);
    free(maxInColumn);
    free(minInLine);
    return 0;
}
