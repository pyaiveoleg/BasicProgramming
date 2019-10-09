#include <stdio.h>
#include <stdbool.h>

void printFareiSequence(int maxDenominator, int firstNumerator, int firstDenominator, int secondNumerator, int secondDenominator)
{
    int numeratorOfMediant = firstNumerator + secondNumerator;
    int denominatorOfMediant = firstDenominator + secondDenominator;

    if (denominatorOfMediant <= maxDenominator)
    {
        printFareiSequence(maxDenominator, firstNumerator, firstDenominator, numeratorOfMediant, denominatorOfMediant);
        printf("%d / %d\n", numeratorOfMediant, denominatorOfMediant);
        printFareiSequence(maxDenominator, numeratorOfMediant, denominatorOfMediant, secondNumerator, secondDenominator);
    }
}

int main() {
    int maxDenominator = 0;

    printf("Please, write down maximal denominator (N):\n");
    scanf("%d", &maxDenominator);

    printf("There are all fractions with denominator less than N:\n");
    printFareiSequence(maxDenominator, 0, 1, 1, 1);

    return 0;
}