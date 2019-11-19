#include <stdio.h>
#include "queue.h"

void printQueueWithDescriptionInFile(FILE *output, Queue* queue, char description[])
{
    fprintf(output, "%s", description);
    fprint(output, queue);
    fprintf(output, "\n");
}

int main() {
    Queue* numbersLessThanA = createQueue();
    Queue* numbersBetweenAAndB = createQueue();
    Queue* numbersBiggerThanB = createQueue();

    int leftBorder = 0;
    int rightBorder = 0;
    printf("Write down numbers A and B - borders of intervals:\n");
    scanf("%d %d", &leftBorder, &rightBorder);

    int inputNumber = 0;

    FILE *input;
    FILE *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

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

    fprintf(output, "A = %d, B = %d\n", leftBorder, rightBorder);
    printQueueWithDescriptionInFile(output, numbersLessThanA, "Numbers less than A:\n");
    printQueueWithDescriptionInFile(output, numbersBetweenAAndB, "Numbers between A and B:\n");
    printQueueWithDescriptionInFile(output, numbersBiggerThanB, "Numbers bigger than B:\n");

    return 0;
}