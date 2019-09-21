#include <stdio.h>
#include <stdbool.h>



int main() {
    const int maxNumber = 10000;
    int number = 0;
    bool isMutuallyPrime[maxNumber];
    for (int i = 0; i < maxNumber; i++)
    {
        isMutuallyPrime[i] = true;
    }

    printf("Please, write down the number N: ");
    scanf("%d", &number);

    for (int i = 2; i <= number; i++)
    {
        if (number % i == 0)
        {
            isMutuallyPrime[i] = false;
        }
        if (!isMutuallyPrime[i])
        {
            for (int j = i; j <= number; j += i)
            {
                isMutuallyPrime[j] = false;
            }
        }
    }

    printf("1 / n\n");
    for (int i = 2; i <= number; i++)
    {
        if (isMutuallyPrime[i])
        {
            printf("%d / n\n",i);
        }
    }

    return 0;
}