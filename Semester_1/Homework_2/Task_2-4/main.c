#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void getStructureOfString(int structureOfString[], const char stringForAnalyze[], size_t stringLength)
{
    for (size_t i = 0; i < stringLength; i++)
    {
        structureOfString[stringForAnalyze[i] - (int)'a']++;
    }
}

int main()
{
    const int quantityOfEnglishLetters = 26;
    const int maxStringLength = 1000;
    int structureOfFirstString[quantityOfEnglishLetters];
    int structureOfSecondString[quantityOfEnglishLetters];
    for (int i = 0; i < quantityOfEnglishLetters; i++)
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

    printf("Please, write down first string (s1):\n");
    scanf("%s", firstString);
    printf("Please, write down second string (s2):\n");
    scanf("%s", secondString);

    getStructureOfString(structureOfFirstString, firstString, strlen(firstString));
    getStructureOfString(structureOfSecondString, secondString, strlen(secondString));

    for (int i = 0; i < quantityOfEnglishLetters; i++)
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