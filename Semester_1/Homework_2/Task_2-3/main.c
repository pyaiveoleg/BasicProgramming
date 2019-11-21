#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int quantityOfDigits = 10;
    srand(time(NULL));

    bool isDigitUsed[quantityOfDigits];
    bool isDigitUsedInGuessedNumber[quantityOfDigits];
    bool isDigitABull[quantityOfDigits];
    for (int i = 0; i < quantityOfDigits; i++)
    {
        isDigitUsed[i] = false;
        isDigitUsedInGuessedNumber[i] = false;
        isDigitABull[i] = false;
    }

    int thoughtNumber[4] = {0, 0, 0, 0};
    int randomDigit = 0;
    for (int i = 0; i <= 3; i++)
    {
        do
        {
            randomDigit = rand() % 10;
        }
        while (isDigitUsed[randomDigit]);

        thoughtNumber[i] = randomDigit;
        isDigitUsed[randomDigit] = true;
    }

    bool isSolved = false;
    int guessedNumber[4] = {0, 0, 0, 0};
    int inputNumber = 0;
    int cows = 0;
    int bulls = 0;
    int turn = 1;

    printf("     Guess Result\n");
    while (!isSolved)
    {
        printf(" %d  |", turn);
        scanf("%d", &inputNumber);

        for (int i = 3; i >= 0; i--)
        {
            int currentDigit = inputNumber % 10;
            guessedNumber[i] = currentDigit;
            isDigitUsedInGuessedNumber[currentDigit] = true;
            inputNumber /= 10;
        }

        for (int i = 0; i <= 3; i++)
        {
            if (guessedNumber[i] == thoughtNumber[i])
            {
                bulls++;
                isDigitABull[i] = true;
            }
        }

        for (int i = 0; i < quantityOfDigits; i++)
        {
            if ((isDigitUsed[i]) && (isDigitUsedInGuessedNumber[i]) && (!isDigitABull[i]))
            {
                cows++;
            }
            isDigitABull[i] = false;
            isDigitUsedInGuessedNumber[i] = false;
        }

        printf("           %d cows %d bulls\n", cows, bulls);

        if (bulls == 4)
        {
            isSolved = true;
        }
        bulls = 0;
        cows = 0;
        turn++;
    }

    printf("You win!");

    return 0;
}