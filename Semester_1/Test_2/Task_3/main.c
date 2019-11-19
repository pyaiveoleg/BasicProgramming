#include <stdio.h>
#include "queue.h"

void printQueueWithDescription(Queue* queue, char description[])
{
    printf("%s", description);
    print(queue);
    printf("\n");
}

int main()
{
    Queue* numbersLessThanA = createQueue();
    Queue* numbersBetweenAAndB = createQueue();
    Queue* numbersBiggerThanB = createQueue();

    int leftBorder = 0;
    int rightBorder = 0;
    printf("Write down numbers A and B - borders of intervals:\n");
    scanf("%d %d", &leftBorder, &rightBorder);

    int inputNumber = 0;

    FILE *input;
    input = fopen("input.txt", "r");

    if (!input)
    {
        printf("Error. Cannot open file.");
        return 0;
    }
    while (!feof(input))
    {
        fscanf(input, "%d", &inputNumber);
        if (inputNumber < leftBorder)
        {
            push(inputNumber, numbersLessThanA);
        }
        else if (inputNumber > rightBorder)
        {
            push(inputNumber, numbersBiggerThanB);
        }
        else
        {
            push(inputNumber, numbersBetweenAAndB);
        }
    }
    fclose(input);

    printQueueWithDescription(numbersLessThanA, "Numbers less than A:\n");
    printQueueWithDescription(numbersBetweenAAndB, "Numbers between A and B:\n");
    printQueueWithDescription(numbersBiggerThanB, "Numbers bigger than B:\n");

    return 0;
}