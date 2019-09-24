#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    const int quantityOfSymbols = 256;
    const int maxStringLength = 1000;
    int structureOfFirstString[quantityOfSymbols];
    int structureOfSecondString[quantityOfSymbols];
    for (int i = 0; i < quantityOfSymbols; i++)
    {
        structureOfFirstString[i] = 0;
        structureOfSecondString[i] = 0;
    }
    char firstString[maxStringLength];
    char secondString[maxStringLength];
    for (int i = 0; i < maxStringLength; i++)
    {
        firstString[i] = 0;
        secondString[i] = 0;
    }
    bool isTransposition = true;

    printf("Please, write down first string (s1): ");
    scanf("%s", &firstString);
    printf("Please, write down second string (s2): ");
    scanf("%s", &secondString);
    for (int i = 0; i < strlen(firstString); i++)
    {
        structureOfFirstString[firstString[i]]++;
    }
    for (int i = 0; i < strlen(secondString); i++)
    {
        structureOfSecondString[secondString[i]]++;
    }
    for (int i = 0; i < quantityOfSymbols; i++)
    {
        if (structureOfFirstString[i] != structureOfSecondString[i])
        {
            isTransposition = false;
        }
    }

    if (isTransposition)
    {
        printf("First string is transposition of elements of second string");
    }
    else
    {
        printf("First string is not transposition of elements of second string");
    }

    return 0;
}