#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** createTwoDimensionalArray(int height, int width, int defaultValue)
{
    int** newArray = (int**) malloc(sizeof(int*) * height);

    for (int i = 0; i < height; i++)
    {
        newArray[i] = (int*) malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++)
        {
            newArray[i][j] = defaultValue;
        }
    }
    return newArray;
}

bool** createTwoDimensionalBoolArray(int height, int width, bool defaultValue)
{
    bool** newArray = (bool**) malloc(sizeof(bool*) * height);

    for (int i = 0; i < height; i++)
    {
        newArray[i] = (bool*) malloc(sizeof(bool) * width);
        for (int j = 0; j < width; j++)
        {
            newArray[i][j] = defaultValue;
        }
    }
    return newArray;
}

void deleteTwoDimensionalArray(int** array, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(array[i]);
    }
    free(array);
}

void deleteTwoDimensionalBoolArray(bool** array, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(array[i]);
    }
    free(array);
}

int** readArray(int height, int width)
{
    int** array = createTwoDimensionalArray(height, width, 0); //default value is 0
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    return array;
}

void createMatrixOfReachability(int quantityOfEdges, int quantityOfVertexes, int** graph, bool** reachable)
{
    for (int i = 0; i < quantityOfEdges; i++)
    {
        int numberOfBegin = -1;
        int numberOfEnd = -1;
        for (int j = 0; j < quantityOfVertexes; j++)
        {
            if (graph[j][i] == 1)
            {
                numberOfBegin = j;
            }
            if (graph[j][i] == -1)
            {
                numberOfEnd = j;
            }
        }
        reachable[numberOfBegin][numberOfEnd] = true;
    }
    for (int i = 0; i < quantityOfVertexes; i++)
    {
        reachable[i][i] = true;
    }
}

void findAllReachablePairs(int quantityOfVertexes, bool** reachable)
{
    for (int k = 0; k < quantityOfVertexes; k++)
    {
        for (int i = 0; i < quantityOfVertexes; i++)
        {
            for (int j = 0; j < quantityOfVertexes; j++)
            {
                if (reachable[i][k] && reachable[k][j])
                {
                    reachable[i][j] = true;
                }
            }
        }
    }
}

void printVertexesReachableFromAllOthers(int quantityOfVertexes, bool** reachable)
{
    printf("This is list of vertexes that are reachable from all other vertexes.\n");
    int quantityOfRequiredVertexes = 0;
    for (int i = 0; i < quantityOfVertexes; i++)
    {
        bool allReachable = true;
        for (int j = 0; j < quantityOfVertexes; j++)
        {
            if (!reachable[j][i])
            {
                allReachable = false;
            }
        }
        if (allReachable)
        {
            printf("%d\n", i + 1);
            quantityOfRequiredVertexes++;
        }
    }
    if (quantityOfRequiredVertexes == 0)
    {
        printf("List is empty.\n");
    }
}

int main()
{
    printf("Please, write down quantity of vertexes in graph.\n");
    int quantityOfVertexes = 0;
    scanf("%d", &quantityOfVertexes);

    printf("Please, write down quantity of edges in graph.\n");
    int quantityOfEdges = 0;
    scanf("%d", &quantityOfEdges);

    if (quantityOfEdges > 0)
    {
        printf("Please, write down graph as Incidence matrix: -1 if vertex is end of edge,\n");
        printf("1 if vertex is begin of edge and 0 if they are not incident.\n");
    }
    else
    {
        printf("There aren't edges at all.\n");
    }

    int** graph = readArray(quantityOfVertexes, quantityOfEdges);
    bool** reachable = createTwoDimensionalBoolArray(quantityOfVertexes, quantityOfVertexes, false);

    createMatrixOfReachability(quantityOfEdges, quantityOfVertexes, graph, reachable);
    findAllReachablePairs(quantityOfVertexes, reachable);
    printVertexesReachableFromAllOthers(quantityOfVertexes, reachable);

    deleteTwoDimensionalBoolArray(reachable, quantityOfVertexes);
    deleteTwoDimensionalArray(graph, quantityOfVertexes);
    return 0;
}
