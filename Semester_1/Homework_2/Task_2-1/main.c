#include <stdio.h>

void decomposeNumberIntoTerms(int remainingPart, int maximalTerm, int numberOfCurrentTerm, int currentRepresentation[])
{
    if (remainingPart < 0)
    {
        return;
    }
    if (remainingPart == 0)
    {
        printf("%d ", currentRepresentation[0]);
        for (int j = 1; j < numberOfCurrentTerm; j++)
        {
            printf("+ %d ", currentRepresentation[j]);
        }
        printf("\n");
    }
    else
    {
        if (remainingPart >= maximalTerm)
        {
            currentRepresentation[numberOfCurrentTerm] = maximalTerm;
            decomposeNumberIntoTerms(remainingPart - maximalTerm, maximalTerm, numberOfCurrentTerm + 1, currentRepresentation);
        }
        if (maximalTerm > 1)
        {
            decomposeNumberIntoTerms(remainingPart, maximalTerm - 1, numberOfCurrentTerm, currentRepresentation);
        }
    }
    return;
}

int main()
{
    const int maxNumber = 100;
    int currentRepresentation[maxNumber];
    for (int i = 0; i < maxNumber; i++)
    {
        currentRepresentation[i] = 0;
    }
    int number = 0;

    printf("Please, write down number (N): ");
    scanf("%d", &number);

    decomposeNumberIntoTerms(number, number, 0, currentRepresentation);

    return 0;
}