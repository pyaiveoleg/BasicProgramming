#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    const int maxStringSize = 1000;
    char pattern[maxStringSize];
    char inputString[maxStringSize];
    for (int i = 0; i < maxStringSize; i++)
    {
        pattern[i] = '0';
        inputString[i] = '0';
    }
    int numberOfInclusion = 0;
    bool isIncluded = true;

    printf("Please, write down pattern (s1): ");
    scanf("%s", &pattern);
    int patternLength = strlen(pattern);
    printf("Please, write down string (s2): ");
    scanf("%s", &inputString);
    int stringLength = strlen(inputString);

    for (int i = 0; i <= stringLength - patternLength; i++)
    {
        for (int j = 0; j < patternLength; j++)
        {
            if (pattern[j] != inputString[i + j])
            {
                isIncluded = false;
                break;
            }
        }
        if (isIncluded)
        {
            numberOfInclusion++;
        }
        else
        {
            isIncluded = true;
        }
    }

    printf("This is a number of inclusions s1 in s2: %d", numberOfInclusion);

    return 0;
}