#include <stdio.h>

int main() {
    printf("Write down number in Fibonacci sequence (i):\n");
    int numberInFibonacciSequence = 0;
    scanf("%d", &numberInFibonacciSequence);

    int firstNumber = 1;
    int secondNumber = 1;

    for (int i = 1; i < numberInFibonacciSequence; i++)
    {
        int temporary = secondNumber;
        secondNumber = firstNumber + secondNumber;
        firstNumber = temporary;
    }

    if ((numberInFibonacciSequence == 1) || (numberInFibonacciSequence == 2))
    {
        printf("%d", 1);
    }
    else
    {
        printf("%d", firstNumber);
    }

    return 0;
}