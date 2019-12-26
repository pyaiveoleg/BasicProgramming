#include <stdio.h>
#include <stdbool.h>

int main() {
    const int maxNumber = 10000;
    int number = 0;
    bool isPrime[maxNumber];
    for (int i = 0; i < maxNumber; i++)
    {
        isPrime[i] = true;
    }

    printf("Please, write down the number N: ");
    scanf("%d", &number);

    for (int i = 2; i <= number; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= number; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    printf("There are all prime numbers which are less or equal to N: ");
    for (int i = 2; i <= number; i++)
    {
        if (isPrime[i])
        {
            printf("%d ",i);
        }
    }

    return 0;
}