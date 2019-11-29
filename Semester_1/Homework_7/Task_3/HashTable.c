#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "HashTable.h"
#include "MyString.h"

typedef struct Record Record;

struct Record
{
    bool hasDeleted;
    int attemptsToInsert;
    int maxAttemptsToInsert;
    String* key;
    int quantityOfEntries;
};

struct HashTable
{
    int sizeOfHash;
    int quantityOfRecords;
    double maxLoadFactor;
    Record** array;
};

HashTable* createHashTable(int sizeOfHash, double maxLoadFactor)
{
    HashTable* newHashTable = (HashTable*) malloc(sizeof(HashTable));
    newHashTable->array = (Record**) malloc(sizeof(Record*) * sizeOfHash);
    newHashTable->sizeOfHash = sizeOfHash;
    newHashTable->maxLoadFactor = maxLoadFactor;

    for (int i = 0; i < sizeOfHash; i++)
    {
        newHashTable->array[i] = (Record*) malloc(sizeof(Record));
        newHashTable->array[i]->key = createString("\0");
        newHashTable->array[i]->attemptsToInsert = 0;
        newHashTable->array[i]->hasDeleted = false;
        newHashTable->array[i]->maxAttemptsToInsert = 0;
        newHashTable->array[i]->quantityOfEntries = 0;
    }

    return newHashTable;
}

unsigned int calculateHash(String* string)
{
    const size_t bigPrimaryNumber = pow(10, 9) + 9;
    int hash = 0;

    int lengthOfString = 0;
    getStringLength(string, &lengthOfString);

    char* text = malloc(sizeof(int) * lengthOfString);
    convertToPointerToChar(string, text);

    for (int i = 0; i < lengthOfString; i++)
    {
        hash +=  (int) text[i] * (int) pow(bigPrimaryNumber, i);
    }

    free(text);
    return hash;
}

void deleteHashTable(HashTable* hashTable)
{
    for (int i = 0; i < hashTable->sizeOfHash; ++i)
    {
        free(hashTable->array[i]->key);
        free(hashTable->array[i]);
    }
    free(hashTable);
}

HashTable* expandHashTable(HashTable* oldHashTable)
{
    int sizeOfOldTable = oldHashTable->sizeOfHash;
    int sizeOfNewTable = 2 * sizeOfOldTable;
    HashTable* expandedHashTable = createHashTable(sizeOfNewTable, oldHashTable->maxLoadFactor);
    expandedHashTable->quantityOfRecords = oldHashTable->quantityOfRecords;

    for (int i = 0; i < sizeOfOldTable; ++i)
    {
        addStringToTable(expandedHashTable, oldHashTable->array[i]->key, sizeOfNewTable);
    }
    deleteHashTable(oldHashTable);
}

void addStringToTable(HashTable* hashTable, String* string, int sizeOfHash)
{
    unsigned int hash = calculateHash(string) % sizeOfHash;
    bool hasInserted = false;
    unsigned int possibleIndex = hash;

    String* emptyString = createString("\0");
    int i = 0;
    do
    {
        bool equalityOfStrings = false;
        areStringsEqual(string, hashTable->array[possibleIndex]->key, &equalityOfStrings);

        bool isKeyEmpty = false;
        areStringsEqual(hashTable->array[possibleIndex]->key, emptyString, &isKeyEmpty);

        if (isKeyEmpty || hashTable->array[possibleIndex]->hasDeleted || equalityOfStrings)
        {
            hashTable->array[possibleIndex]->key = string;
            hashTable->array[possibleIndex]->quantityOfEntries++;
            if (i > hashTable->array[possibleIndex]->maxAttemptsToInsert) //разобраться с инициализацией таблицы!!!
            {
                hashTable->array[possibleIndex]->maxAttemptsToInsert = i;
            }
            hashTable->array[possibleIndex]->attemptsToInsert += i;
            hashTable->quantityOfRecords++;
            hasInserted = true;

        }

        i++;
        possibleIndex = (possibleIndex + (int) pow(i, 2)) % sizeOfHash;
        //printf(hasInserted ? "true" : "false");
    }
    while (!hasInserted);

    if ((double) hashTable->quantityOfRecords / hashTable->sizeOfHash > hashTable->maxLoadFactor)
    {
        expandHashTable(hashTable);
    }
}

double getLoadFactor(HashTable* hashTable)
{
    return (double) hashTable->quantityOfRecords / hashTable->sizeOfHash;
}

double getAverageAttemptsQuantity(HashTable* hashTable)
{
    double averageAttemptsQuantity = 0;
    for (int i = 0; i < hashTable->sizeOfHash; ++i)
    {
        averageAttemptsQuantity += hashTable->array[i]->attemptsToInsert;
    }
    averageAttemptsQuantity /= hashTable->quantityOfRecords;
    return averageAttemptsQuantity;
}

void getMaxAttemptsQuantity(HashTable* hashTable, String** valueWithMaxQuantity, int* maxQuantity)
{
    for (int i = 0; i < hashTable->sizeOfHash; ++i)
    {
        if (hashTable->array[i]->maxAttemptsToInsert > *maxQuantity)
        {
            *maxQuantity = hashTable->array[i]->maxAttemptsToInsert;
            *valueWithMaxQuantity = hashTable->array[i]->key;
        }
    }
}

void printInformationAboutTable(HashTable* hashTable)
{
    printf("Load Factor is %lf\n", getLoadFactor(hashTable));

    int maxQuantityOfAttempts = 0;
    String* valueWithMaxQuantity = NULL;
    getMaxAttemptsQuantity(hashTable, &valueWithMaxQuantity, &maxQuantityOfAttempts);
    printf("Max quantity of attempts during adding the element was %d with string ", maxQuantityOfAttempts);
    printString(valueWithMaxQuantity);

    printf("\nAverage quantity of attempts during adding the element is %lf\n", getAverageAttemptsQuantity(hashTable));

    printf("There are %d words\n", hashTable->quantityOfRecords);
    printf("Quantity of empty buckets is %d", hashTable->sizeOfHash - hashTable->quantityOfRecords);
}

void getDataFromBucket(HashTable* hashTable, int numberOfBucket, int* value, String** key)
{
    *value = hashTable->array[numberOfBucket] == NULL ? -1 : hashTable->array[numberOfBucket]->quantityOfEntries;
    *key = hashTable->array[numberOfBucket] == NULL ? NULL : hashTable->array[numberOfBucket]->key;
}

int getSizeOfHashTable(HashTable* hashTable)
{
    return hashTable->sizeOfHash;
}