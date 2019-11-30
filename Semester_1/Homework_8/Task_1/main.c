#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void divideIntoComponentsByDFS(int numberOfVertex, bool* used, const int quantityOfStudents, bool** areWorksEqual)
{
    used[numberOfVertex] = true;
    if (numberOfVertex != 0)
    {
        printf("%d ", numberOfVertex);
    }

    for (int i = 0; i <= quantityOfStudents; ++i)
    {
        if (areWorksEqual[numberOfVertex][i] && !used[i])
        {
            divideIntoComponentsByDFS(i, used, quantityOfStudents, areWorksEqual);
        }
    }
}

int main()
{
    int quantityOfStudents = 0;
    printf("Please, write down quantity of students:\n");
    scanf("%d", &quantityOfStudents);

    bool** areWorksEqual = (bool**) malloc(sizeof(bool*) * (quantityOfStudents + 1)); //+1, так как есть ещё не сдавшие ничего
    for (int i = 0; i <= quantityOfStudents; ++i)
    {
        areWorksEqual[i] = (bool*) malloc(sizeof(bool) * (quantityOfStudents + 1));
    }

    for (int j = 0; j <= quantityOfStudents; ++j)
    {
        for (int i = 0; i <= quantityOfStudents; ++i)
        {
            areWorksEqual[i][j] = false;
        }
    }

    int numberOfStudent = 0;
    int numberOfOriginalWork = 0;

    printf("Please, write down number of student and number of original work:\n");
    for (int i = 0; i < quantityOfStudents; ++i)
    {
        scanf("%d %d", &numberOfStudent, &numberOfOriginalWork);
        if (numberOfOriginalWork == -1)
        {
            areWorksEqual[numberOfStudent][0] = true;
            areWorksEqual[0][numberOfStudent] = true;
        }
        else
        {
            areWorksEqual[numberOfStudent][numberOfOriginalWork] = true;
            areWorksEqual[numberOfOriginalWork][numberOfStudent] = true;
        }
    }

    bool used[quantityOfStudents + 1];
    for (int i = 0; i <= quantityOfStudents; ++i)
    {
        used[i] = false;
    }

    printf("These students haven't done anything: ");
    divideIntoComponentsByDFS(0, used, quantityOfStudents, areWorksEqual);
    printf("\n");

    for (int i = 1; i <= 3; ++i)
    {
        printf("These students copied work of %d student: ", i);
        divideIntoComponentsByDFS(i, used, quantityOfStudents, areWorksEqual);
        printf("\n");
    }

    free(areWorksEqual);
    return 0;
}