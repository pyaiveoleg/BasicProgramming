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

    FILE *input;
    input = fopen("input.txt", "r");

    if (!input)
    {
        printf("Error. Cannot open file.");
        return 0;
    }

    int sizeOfHash = startingSizeOfHash;
    HashTable* hashTable = createHashTable(sizeOfHash, maxLoadFactor);
    char* inputString = NULL;

    bool hasReachedEndOfFile = false;
    while (!hasReachedEndOfFile)
    {
        inputString = readStringFromFile(&hasReachedEndOfFile, startingStringLength, input);
        String* addedString = createString(inputString);
        addStringToTable(hashTable, addedString, sizeOfHash);
        free(inputString);
    }
    fclose(input);

    printInformationAboutTable(hashTable);
    int sizeOfHashTable = getSizeOfHashTable(hashTable);

    int quantityOfEntries = 0;
    String* currentString = NULL;
    String* emptyString = createString("\0");
    for (int i = 0; i < sizeOfHashTable; i++)
    {
        getDataFromBucket(hashTable, i, &quantityOfEntries, &currentString);

        bool isStringEmpty = false;
        areStringsEqual(currentString, emptyString, &isStringEmpty);
        if (!isStringEmpty)
        {
            printf("String ");
            printString(currentString);
            printf("used %d times\n", quantityOfEntries);
        }
    }

    deleteHashTable(hashTable);
    deleteString(&emptyString);
    return 0;
}