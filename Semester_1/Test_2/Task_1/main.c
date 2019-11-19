#include <stdio.h>

int main() {
    printf("Write down number in Fibonacci sequence (i):\n");
    int numberInFibonacciSequence = 0;
    scanf("%d", &numberInFibonacciSequence);

    int firstNumber = 0;
    int secondNumber = 1;

    for (int i = 0; i < numberInFibonacciSequence; i++)
    {
        int temporary = secondNumber;
        secondNumber = firstNumber + secondNumber;
        firstNumber = temporary;
    }

    if (numberInFibonacciSequence == 0)
    {
        printf("%d", 0);
    }
    else if (numberInFibonacciSequence == 1)
    {
        printf("%d", 1);
    }
    else
    {
        printf("%d", firstNumber);
    }

    return 0;
}