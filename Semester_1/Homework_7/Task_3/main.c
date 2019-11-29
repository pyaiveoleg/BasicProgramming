#include <stdio.h>
#include <stdlib.h>

#include "MyString.h"
#include "HashTable.h"

char* readStringFromFile(bool* hasReachedEndOfFile, const int startingSizeOfString, FILE* input)
{
    char* inputString = (char*) malloc(sizeof(char) * startingSizeOfString);
    int inputStringSize = startingSizeOfString;
    int i = 0;
    do
    {
        inputString[i] =  (char) fgetc(input);
        if (inputString[i] == EOF)
        {
            *hasReachedEndOfFile = true;
            i++;
            break;
        }

        i++;
        if (i >= inputStringSize)
        {
            inputStringSize *= 2;
            inputString = (char*) realloc (inputString, sizeof(char) * inputStringSize);
        }
    }
    while (inputString[i - 1] != ' ' && inputString[i - 1] != '\n');
    inputString[i - 1] = '\0';

    return inputString;
}

int main()
{
    const double maxLoadFactor = 0.7; //оптимально для таблиц с открытой адресацией
    const int startingStringLength = 1000;
    const int startingSizeOfHash = 1000;

    int sizeOfHash = startingSizeOfHash;

    HashTable* hashTable = createHashTable(sizeOfHash, maxLoadFactor);

    FILE *input;
    input = fopen("input.txt", "r");

    char* inputString = NULL;
    if (!input)
    {
        printf("Error. Cannot open file.");
        return 0;
    }

    bool hasReachedEndOfFile = false;
    while (!hasReachedEndOfFile)
    {
        inputString = readStringFromFile(&hasReachedEndOfFile, startingStringLength, input);
        String* addedString = createString(inputString);
        addStringToTable(hashTable, addedString, sizeOfHash);
        printf("1");
        free(inputString);
    }
    fclose(input);

    printInformationAboutTable(hashTable);
    int sizeOfHashTable = getSizeOfHashTable(hashTable);

    int quantityOfEntries = 0;
    String* currentString = NULL;
    for (int i = 0; i < sizeOfHashTable; i++)
    {
        getDataFromBucket(hashTable, i, &quantityOfEntries, &currentString);
        printf("String ");
        printString(currentString);
        printf("used %d times\n", quantityOfEntries);
    }

    return 0;
}