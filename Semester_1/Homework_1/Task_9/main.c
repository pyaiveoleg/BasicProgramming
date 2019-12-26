#include <stdio.h>

int binaryPow(int basisOfPower, int indicatorOfPower)
{
    if (indicatorOfPower == 0)
    {
        return 1;
    }
    if (indicatorOfPower % 2 == 1)
    {
        return binaryPow(basisOfPower, indicatorOfPower - 1) * basisOfPower;
    }

    int squareRoot = binaryPow(basisOfPower, indicatorOfPower / 2);
    return squareRoot * squareRoot;
}

int main()
{
    int basisOfPower = 0;
    int indicatorOfPower = 0;
    printf("Please, write down basis of power (A) and indicator of power (N): ");
    scanf("%d %d", &basisOfPower, &indicatorOfPower);

    printf("A ^ N = %d", binaryPow(basisOfPower, indicatorOfPower));

    return 0;
}
