#include <stdio.h>
#include <string.h>

int main() {
    const int maxInputLength = 1000;
    const int numberOfLetterInAlphabet = 26;
    const int codeOfA = (int) 'a';
    const int codeOfZ = (int) 'z';

    int quantityOfLetters[numberOfLetterInAlphabet];
    for(int i = 0; i < numberOfLetterInAlphabet; i++)
    {
        quantityOfLetters[i] = 0;
    }

    FILE *input;
    FILE *output;
    input = fopen("input.txt", "r");

    char inputFile[maxInputLength];
    if (input)
    {
        while (!feof(input))
        {
            fscanf(input, "%[^\0]", inputFile);
        }
        fclose(input);
    }
    else
    {
        printf("Error. Cannot open file.");
        return 0;
    }

    int lengthOfInputString = strlen(inputFile);
    for (int i = 0; i < lengthOfInputString; i++)
    {
        int codeOfSymbol = inputFile[i];
        if ((codeOfSymbol >= codeOfA) && (codeOfSymbol <= codeOfZ))
        {
            quantityOfLetters[codeOfSymbol - codeOfA] += 1;
        }
    }

    output = fopen("output.txt", "w");
    for (int i = codeOfA; i <= codeOfZ; i++)
    {
        if (quantityOfLetters[i - codeOfA] != 0)
        {
            fprintf(output, "%c: %d\n", (char) i, quantityOfLetters[i - codeOfA]);
        }
    }
    fclose(output);

    return 0;
}