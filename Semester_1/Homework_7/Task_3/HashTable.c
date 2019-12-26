#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "HashTable.h"
#include "MyString.h"

typedef struct Record Record;

struct Record
{
    bool wasDeleted;
    int attemptsToInsert;
    int maxAttemptsToInsert;
    String* key;
    int quantityOfEntries;
};

struct HashTable
{
    int size;
    int quantityOfRecords;
    int quantityOfFilledBuckets;
    double maxLoadFactor;
    Record** array;
};

HashTable* createHashTable(int sizeOfHash, double maxLoadFactor)
{
    HashTable* newHashTable = (HashTable*) malloc(sizeof(HashTable));
    newHashTable->array = (Record**) malloc(sizeof(Record*) * sizeOfHash);
    newHashTable->size = sizeOfHash;
    newHashTable->maxLoadFactor = maxLoadFactor;
    newHashTable->quantityOfRecords = 0;
    newHashTable->quantityOfFilledBuckets = 0;

    for (int i = 0; i < sizeOfHash; i++)
    {
        newHashTable->array[i] = (Record*) malloc(sizeof(Record));
        newHashTable->array[i]->key = createString("\0");
        newHashTable->array[i]->attemptsToInsert = 0;
        newHashTable->array[i]->wasDeleted = false;
        newHashTable->array[i]->maxAttemptsToInsert = 0;
        newHashTable->array[i]->quantityOfEntries = 0;
    }

    return newHashTable;
}

unsigned int calculateHash(String* string)
{
    const size_t bigPrimaryNumber = pow(10, 9) + 9;
    unsigned int hash = 0;

    int lengthOfString = 0;
    getStringLength(string, &lengthOfString);

    for (int i = 0; i < lengthOfString; i++)
    {
        hash +=  (int) string->text[i] * (int) pow(bigPrimaryNumber, i);
    }

    return hash;
}

void deleteHashTable(HashTable* hashTable)
{
    for (int i = 0; i < hashTable->size; ++i)
    {
        deleteString(&hashTable->array[i]->key);
        free(hashTable->array[i]);
    }
    free(hashTable->array);
    free(hashTable);
}

HashTable* expandHashTable(HashTable* oldHashTable)
{
    int sizeOfOldTable = oldHashTable->size;
    int sizeOfNewTable = 2 * sizeOfOldTable;
    HashTable* expandedHashTable = createHashTable(sizeOfNewTable, oldHashTable->maxLoadFactor);
    expandedHashTable->quantityOfRecords = oldHashTable->quantityOfRecords;

    for (int i = 0; i < sizeOfOldTable; ++i)
    {
        addStringToTable(expandedHashTable, oldHashTable->array[i]->key, sizeOfNewTable);
    }
    deleteHashTable(oldHashTable);
    return expandedHashTable;
}

void addStringToTable(HashTable* hashTable, String* string, int sizeOfHash)
{
    unsigned int hash = calculateHash(string) % sizeOfHash;
    bool wasInserted = false;
    unsigned int possibleIndex = hash;

    String* emptyString = createString("\0");
    int i = 1;
    do
    {
        bool areEqual = false;
        areStringsEqual(string, hashTable->array[possibleIndex]->key, &areEqual);

        bool isKeyEmpty = false;
        areStringsEqual(hashTable->array[possibleIndex]->key, emptyString, &isKeyEmpty);

        if (isKeyEmpty || hashTable->array[possibleIndex]->wasDeleted || areEqual)
        {
            deleteString(&hashTable->array[possibleIndex]->key);
            hashTable->array[possibleIndex]->key = string;
            hashTable->array[possibleIndex]->quantityOfEntries++;
            if (i > hashTable->array[possibleIndex]->maxAttemptsToInsert)
            {
                hashTable->array[possibleIndex]->maxAttemptsToInsert = i;
            }
            hashTable->array[possibleIndex]->attemptsToInsert += i;
            hashTable->quantityOfRecords++;
            if (isKeyEmpty || hashTable->array[possibleIndex]->wasDeleted)
            {
                hashTable->quantityOfFilledBuckets++;
            }
            wasInserted = true;
        }

        i++;
        possibleIndex = (possibleIndex + (int) pow(i, 2)) % sizeOfHash;
    }
    while (!wasInserted);

    deleteString(&emptyString);

    if ((double) hashTable->quantityOfRecords / hashTable->size > hashTable->maxLoadFactor)
    {
        expandHashTable(hashTable);
    }
}

double getLoadFactor(HashTable* hashTable)
{
    return (double) hashTable->quantityOfFilledBuckets / hashTable->size;
}

double getAverageAttemptsQuantity(HashTable* hashTable)
{
    double averageAttemptsQuantity = 0;
    for (int i = 0; i < hashTable->size; ++i)
    {
        averageAttemptsQuantity += hashTable->array[i]->attemptsToInsert;
    }
    averageAttemptsQuantity /= hashTable->quantityOfRecords;
    return averageAttemptsQuantity;
}

void getMaxAttemptsQuantity(HashTable* hashTable, String** valueWithMaxQuantity, int* maxQuantity)
{
    for (int i = 0; i < hashTable->size; ++i)
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

    printf("Average quantity of attempts during adding the element is %lf\n", getAverageAttemptsQuantity(hashTable));

    printf("There are %d words at all\n", hashTable->quantityOfRecords);
    printf("There are %d different words\n", hashTable->quantityOfFilledBuckets);
    printf("Quantity of empty buckets is %d\n", hashTable->size - hashTable->quantityOfFilledBuckets);
}

void getDataFromBucket(HashTable* hashTable, int numberOfBucket, int* value, String** key)
{
    *value = hashTable->array[numberOfBucket] == NULL ? -1 : hashTable->array[numberOfBucket]->quantityOfEntries;
    *key = hashTable->array[numberOfBucket]->key;
}

int getSizeOfHashTable(HashTable* hashTable)
{
    return hashTable->size;
}

int search(HashTable* hashTable, String* key)
{
    unsigned int hash = calculateHash(key);
    unsigned int possibleIndex = hash;
    int i = 1;

    do
    {
        bool areEqual = false;
        areStringsEqual(key, hashTable->array[possibleIndex]->key, &areEqual);

        if (areEqual)
        {
            return (int) possibleIndex;
        }

        i++;
        possibleIndex = (possibleIndex + (int) pow(i, 2)) % hashTable->size;
    }
    while (hashTable->array[possibleIndex] != NULL);

    return -1;
}

void delete(HashTable* hashTable, String* key)
{
    int indexOfDeletingElement = search(hashTable, key);
    if (indexOfDeletingElement == -1)
    {
        return;
    }

    hashTable->array[indexOfDeletingElement]->key = NULL;
    hashTable->array[indexOfDeletingElement]->wasDeleted = true;
    hashTable->quantityOfFilledBuckets--;
}