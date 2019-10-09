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

    for (int currentNumber = 2; currentNumber <= number; currentNumber++)
    {
        for (int i = 2; i <= currentNumber; i++)
        {
            if (currentNumber % i == 0)
            {
                isMutuallyPrime[i] = false;
            }
            if (!isMutuallyPrime[i])
            {
                for (int k = i; k <= number; k += i)
                {
                    isMutuallyPrime[k] = false;
                }
            }
        }

        for (int i = 1; i <= currentNumber; i++)
        {
            if (isMutuallyPrime[i])
            {
                printf("%d / %d\n", i, currentNumber);
            }
        }

        for (int i = 0; i < maxNumber; i++)
        {
            isMutuallyPrime[i] = true;
        }
    }

    return 0;
}