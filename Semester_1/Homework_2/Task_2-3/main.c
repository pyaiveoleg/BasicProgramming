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
    for (int i = 0; i < quantityOfDigits; i++)
    {
        isDigitUsed[i] = false;
        isDigitUsedInGuessedNumber[i] = false;
    }
    int randomDigit = rand() % 10;
    isDigitUsed[randomDigit] = true;
    int thoughtNumber[4] = {randomDigit, 0, 0, 0};
    for (int i = 1; i <= 3; i++)
    {
        randomDigit = rand() % 10;
        while (isDigitUsed[randomDigit])
        {
            randomDigit = rand() % 10;
        }
        thoughtNumber[i] = randomDigit;
        isDigitUsed[randomDigit] = true;
    }
    //printf("%d %d %d %d", thoughtNumber[0], thoughtNumber[1], thoughtNumber[2], thoughtNumber[3]);

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
            }
        }

        for (int i = 0; i < quantityOfDigits; i++)
        {
            if ((isDigitUsed[i]) && (isDigitUsedInGuessedNumber[i]))
            {
                cows++;
            }
            isDigitUsedInGuessedNumber[i] = false;
        }

        printf("           %d cows %d bulls\n", cows - bulls, bulls);

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