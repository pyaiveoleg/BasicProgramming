#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    const int maxStringSize = 1000;
    char stack[maxStringSize];
    for (int i = 0; i < maxStringSize; i++)
    {
        stack[i] = '0';
    }
    char inputString[maxStringSize];
    for (int i = 0; i < maxStringSize; i++)
    {
        inputString[i] = '0';
    }
    int pointer = 0;
    bool isRight = true;

    printf("Please, write down the string: ");
    scanf("%s", inputString);
    int stringLength = strlen(inputString);

    for (int i = 0; i < stringLength; i++)
    {
        if ((inputString[i] == '(')  || (inputString[i] == '[') || (inputString[i] == '{'))
        {
            pointer++;
            stack[pointer] = inputString[i];
        }
        else if (((inputString[i] == ')') && (stack[pointer] == '(')) ||
                 ((inputString[i] == ']') && (stack[pointer] == '[')) ||
                 ((inputString[i] == '}') && (stack[pointer] == '{')))
        {
            stack[pointer] = '0';
            pointer--;
        }
        else
        {
            isRight = false;
            break;
        }
    }
    if (pointer != 0)
    {
        isRight = false;
    }

    if (isRight)
    {
        printf("Right bracket sequence");
    }
    else
    {
        printf("Wrong bracket sequence");
    }

    return 0;
}