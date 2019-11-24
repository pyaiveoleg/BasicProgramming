#include "PhoneBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PHONE_NUMBER_LENGTH 12

typedef struct Record Record;

struct Record
{
    char phone[PHONE_NUMBER_LENGTH];
    char* name;
};

struct PhoneBook
{
    int capacity;
    int size;
    Record** records;
};

PhoneBook* createPhoneBook(int capacity)
{
    PhoneBook* newBook = malloc(sizeof(PhoneBook));
    newBook->records = (Record**) malloc(sizeof(Record*) * capacity);
    newBook->size = 0;
    newBook->capacity = capacity;
    return newBook;
}

void expand(PhoneBook** phoneBook)
{
    (*phoneBook)->capacity *= 2;
    (*phoneBook)->records = realloc((*phoneBook)->records, (*phoneBook)->capacity);
}

Record* createRecord()
{
    Record* newRecord = malloc(sizeof(Record));
    return newRecord;
}

void addRecord(PhoneBook* phoneBook, char name[], char phone[])
{
    if (phoneBook->size == phoneBook->capacity)
    {
        expand(&phoneBook);
    }

    Record* addedRecord = createRecord();
    strcpy(addedRecord->phone, phone);

    addedRecord->name = (char*) malloc(sizeof(char) * strlen(name));
    strcpy(addedRecord->name, name);

    phoneBook->records[phoneBook->size] = addedRecord;
    phoneBook->size++;
}

char* searchByName(PhoneBook* phoneBook, char name[])
{
    for (int i = 0; i < phoneBook->size; i++)
    {
        if (strcmp(phoneBook->records[i]->name, name) == 0)
        {
            return phoneBook->records[i]->phone;
        }
    }
    return "haven't found";
}

char* searchByPhone(PhoneBook* phoneBook, char phone[])
{
    for (int i = 0; i < phoneBook->size; i++)
    {
        if (strcmp(phoneBook->records[i]->phone, phone) == 0)
        {
            return phoneBook->records[i]->name;
        }
    }
    return "haven't found";
}

PhoneBook* importPhoneBookFromFile(int capacity)
{
    const int startingSizeOfString = 1000;
    PhoneBook* phoneBook = createPhoneBook(capacity);
    FILE *phoneBookFile;
    phoneBookFile = fopen("PhoneBook.txt", "r");

    if (phoneBookFile)
    {
        bool hasReachedEndOfFile = false;
        while (!hasReachedEndOfFile)
        {
            char currentPhone[PHONE_NUMBER_LENGTH];
            fscanf(phoneBookFile, "%s ", currentPhone);

            char *currentName = (char *) malloc(sizeof(char) * startingSizeOfString);
            int currentNameSize = startingSizeOfString;

            int i = 0;
            do
            {
                currentName[i] = (char) fgetc(phoneBookFile);
                if (currentName[i] == EOF)
                {
                    hasReachedEndOfFile = true;
                    break;
                }

                i++;
                if (i >= currentNameSize) {
                    currentNameSize *= 2;
                    currentName = (char *) realloc(currentName, sizeof(char) * currentNameSize);
                }
            }
            while (currentName[i - 1] != '\n');
            currentName[i - 1] = '\0';
            if (!hasReachedEndOfFile)
            {
                addRecord(phoneBook, currentName, currentPhone);
            }
        }
        fclose(phoneBookFile);
    }

    return phoneBook;
}

void saveDataToFile(PhoneBook* phoneBook)
{
    FILE *phoneBookFile;
    phoneBookFile = fopen("PhoneBook.txt", "w");

    for (int i = 0; i < phoneBook->size; i++)
    {
        fprintf(phoneBookFile, "%s %s\n", phoneBook->records[i]->phone, phoneBook->records[i]->name);
    }

    fclose(phoneBookFile);
}