#include <stdio.h>

int recursiveFactorial(int number)
{
    if (number > 1)
    {
        return number * recursiveFactorial(number - 1);
    }
    return number;
}

int iterativeFactorial(int number)
{
    int factorial = 1;
    for (int i = 2; i <= number; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}

int main()
{
    int number = 0;

    printf("Please, write down N:");
    scanf("%d", &number);

    printf("Factorial of N (recursive): %u\n", recursiveFactorial(number));

    printf("Factorial of N (iterative): %u", iterativeFactorial(number));

    return 0;
}
