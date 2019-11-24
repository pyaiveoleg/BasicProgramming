#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void createThoughtNumber(int* thoughtNumber, bool* isDigitUsed)
{
    srand(time(NULL));
    int randomDigit = 1 + rand() % 9;
    isDigitUsed[randomDigit] = true;
    thoughtNumber[0] = randomDigit;

    for (int i = 1; i <= 3; i++)
    {
        do
        {
            randomDigit = rand() % 10;
        }
        while (isDigitUsed[randomDigit]);

        thoughtNumber[i] = randomDigit;
        isDigitUsed[randomDigit] = true;
    }
}

void play(int* thoughtNumber, const int quantityOfDigits, const bool* isDigitUsed)
{
    bool isDigitUsedInGuessedNumber[quantityOfDigits];
    bool isDigitABull[quantityOfDigits];
    for (int i = 0; i < quantityOfDigits; i++)
    {
        isDigitUsedInGuessedNumber[i] = false;
        isDigitABull[i] = false;
    }

    bool isSolved = false;
    int guessedNumber[4] = {0, 0, 0, 0};
    int inputNumber = 0;
    int cows = 0;
    int bulls = 0;
    int turn = 1;

    printf("I thought: %d%d%d%d\n", thoughtNumber[0], thoughtNumber[1], thoughtNumber[2], thoughtNumber[3]);
    printf("     Guess Result\n");
    while (!isSolved)
    {
        printf(" %d  |", turn);
        scanf("%d", &inputNumber);
        if (inputNumber >= 10000 || inputNumber < 1000)
        {
            printf("\nThere must be 4 digits in your number, please rewrite\n");
            continue;
        }
        bool allDigitsAreDifferent = true;

        for (int i = 3; i >= 0; i--)
        {
            int currentDigit = inputNumber % 10;
            guessedNumber[i] = currentDigit;

            if (isDigitUsedInGuessedNumber[currentDigit])
            {
                printf("\nAll digits need to be different, please rewrite:\n");
                allDigitsAreDifferent = false;
                break;
            }
            else
            {
                isDigitUsedInGuessedNumber[currentDigit] = true;
            }
            inputNumber /= 10;
        }

        if (!allDigitsAreDifferent)
        {
            continue;
        }

        for (int i = 0; i <= 3; i++)
        {
            if (guessedNumber[i] == thoughtNumber[i])
            {
                bulls++;
                isDigitABull[guessedNumber[i]] = true;
            }
        }

        for (int i = 0; i < quantityOfDigits; i++)
        {
            if (isDigitUsed[i] && isDigitUsedInGuessedNumber[i] && (!isDigitABull[i]))
            {
                cows++;
            }
        }

        printf("           %d cows %d bulls\n", cows, bulls);

        if (bulls == 4)
        {
            isSolved = true;
        }
        turn++;
        for (int i = 0; i < quantityOfDigits; i++)
        {
            isDigitUsedInGuessedNumber[i] = false;
            isDigitABull[i] = false;
        }
        bulls = 0;
        cows = 0;
    }

    printf("You win!");
}

int main()
{
    const int quantityOfDigits = 10;

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

    createThoughtNumber(thoughtNumber, isDigitUsed);
    play(thoughtNumber, quantityOfDigits, isDigitUsed);

    return 0;
}