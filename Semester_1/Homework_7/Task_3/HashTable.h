#pragma once

#include "MyString.h"

typedef struct HashTable HashTable;

HashTable* createHashTable(int sizeOfHash, double maxLoadFactor);
void addStringToTable(HashTable* hashTable, String* string, int sizeOfHash);
void printInformationAboutTable(HashTable* hashTable);
void getDataFromBucket(HashTable* hashTable, int numberOfBucket, int* value, String** key);
int getSizeOfHashTable(HashTable* hashTable);
