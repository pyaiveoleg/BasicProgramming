#include <stdio.h>

void addNewDigit(int digit, unsigned long long *parsedNumber, int *consistance)
{
    while (consistance[digit] != 0)
    {
        *parsedNumber = *parsedNumber * 10 + digit;
        consistance[digit]--;
    }
}

int main() {
    const int quantityOfDigits = 10;
    int consistance[quantityOfDigits];
    for (int i = 0; i < quantityOfDigits; i++)
    {
        consistance[i] = 0;
    }
    unsigned long long number = 0;
    unsigned long long parsedNumber = 0;

    printf("Please, write down number N: ");
    scanf("%d", &number);

    while (number != 0)
    {
        consistance[number%10]++;
        number /= 10;
    }

    addNewDigit(1, &parsedNumber, consistance);
    addNewDigit(0, &parsedNumber, consistance);

    for (int i = 2; i < quantityOfDigits; i++)
    {
        addNewDigit(i, &parsedNumber, consistance);
    }

    printf("This is parsed number: %d", parsedNumber);

    return 0;
}