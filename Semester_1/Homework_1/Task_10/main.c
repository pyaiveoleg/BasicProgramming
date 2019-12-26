#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    const int maxStringSize = 1000;
    char inputString[maxStringSize];
    bool isPalindrome = true;
    for (int i = 0; i < maxStringSize; i++)
    {
        inputString[i] = '0';
    }

    printf("Please, write down the string: ");
    scanf("%s", &inputString);
    int stringLength = strlen (inputString);

    for (int i = 0; i < stringLength / 2; i++)
    {
        if (inputString[i] != inputString[stringLength - i - 1])
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
    {
        printf("String is palindrome");
    }
    else
    {
        printf("String is not palindrome");
    }

    return 0;
}
