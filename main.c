#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    bool isSolved = false;
    int thoughtNumber[4] = {rand() % 10, rand() % 10, rand() % 10, rand() % 10};
    //printf ("%d%d%d%d\n", thoughtNumber[0], thoughtNumber[1], thoughtNumber[2], thoughtNumber[3]);
    int guessedNumber[4] = {0,0,0,0};
    int inputNumber = 0;
    int cows = 0;
    int bulls = 0;
    int turn = 1;

    printf("     Guess Result\n");
    while (!isSolved)
    {
        printf(" %d  |", turn);
        scanf("%d", &inputNumber);
        guessedNumber[3] = inputNumber % 10;
        inputNumber /= 10;
        guessedNumber[2] = inputNumber % 10;
        inputNumber /= 10;
        guessedNumber[1] = inputNumber % 10;
        inputNumber /= 10;
        guessedNumber[0] = inputNumber;
        //printf ("%d%d%d%d\n", guessedNumber[0], guessedNumber[1], guessedNumber[2], guessedNumber[3]);
        for (int i = 0; i <= 3; i++)
        {
            if (guessedNumber[i] == thoughtNumber[i])
            {
                bulls++;
            }
            if ((guessedNumber[i] == thoughtNumber [0]) || (guessedNumber[i] == thoughtNumber [1])
             || (guessedNumber[i] == thoughtNumber [2]) || (guessedNumber[i] == thoughtNumber [3]))
            {
                cows++;
            }
        }
        printf ("           %dA %dB\n", cows - bulls, bulls);
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