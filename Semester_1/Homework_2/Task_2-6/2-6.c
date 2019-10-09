#include <stdio.h>

void addNewDigit(int digit, unsigned long long *parsedNumber, int *quantityOfEachDigit)
{
    while (quantityOfEachDigit[digit] != 0)
    {
        *parsedNumber = *parsedNumber * 10 + digit;
        quantityOfEachDigit[digit]--;
    }
}

int main() {
    const int quantityOfDigits = 10;
    int quantityOfEachDigit[quantityOfDigits];
    for (int i = 0; i < quantityOfDigits; i++)
    {
        quantityOfEachDigit[i] = 0;
    }
    unsigned long long number = 0;
    unsigned long long parsedNumber = 0;

    printf("Please, write down number N: ");
    scanf("%llu", &number);

    while (number != 0)
    {
        quantityOfEachDigit[number % 10]++;
        number /= 10;
    }

    for (int i = 1; i < quantityOfDigits; i++)
    {
        if (quantityOfEachDigit[i] > 0)
        {
            parsedNumber = i;
            quantityOfEachDigit[i]--;
            break;
        }
    }

    for (int i = 0; i < quantityOfDigits; i++)
    {
        addNewDigit(i, &parsedNumber, quantityOfEachDigit);
    }

    printf("This is parsed number: %llu", parsedNumber);

    return 0;
}