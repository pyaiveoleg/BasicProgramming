#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    const int maxStringSize = 1000;
    char inputString[maxStringSize];
    for (int i = 0; i < maxStringSize; i++)
    {
        inputString[i] = '0';
    }
    bool isEmpty = true;
    int quantityOfNotEmptyStrings = 0;
    int stringLength = 0;

    FILE *input;
    input = fopen("input.txt", "r");

    if (input)
    {
        while (!feof(input))
        {
            fgets(inputString, maxStringSize, input);
            stringLength = strlen(inputString) - 1;
            for (int i = 0; i < stringLength; i++)
            {
                if ((inputString[i] != ' ') && (inputString[i] != '\t'))
                {
                    isEmpty = false;
                }
            }

            if (!isEmpty)
            {
                quantityOfNotEmptyStrings++;
                isEmpty = true;
            }
        }
        printf("Quantity of not-empty strings in the file: %d", quantityOfNotEmptyStrings);
    }
    else
    {
        printf("Error. Cannot open file.\n");
    }

    fclose(input);
    return 0;
}