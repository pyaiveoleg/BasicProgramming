#include "PhoneBook.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Record Record;

struct Record
{
    char* phone;
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
    (*phoneBook)->records = realloc((*phoneBook)->records, (*phoneBook)->capacity * sizeof(Record*));
}

Record* createRecord()
{
    Record* newRecord = malloc(sizeof(Record));
    return newRecord;
}

bool addRecord(PhoneBook** phoneBook, char name[], char phone[])
{
    if ((*phoneBook)->size == (*phoneBook)->capacity)
    {
        expand(phoneBook);
    }

    Record* addedRecord = createRecord();
    addedRecord->phone = (char*) malloc(sizeof(char) * (strlen(phone) + 1)); // для \0
    strcpy(addedRecord->phone, phone);

    addedRecord->name = (char*) malloc(sizeof(char) * (strlen(name) + 1)); // для \0
    strcpy(addedRecord->name, name);

    (*phoneBook)->records[(*phoneBook)->size] = addedRecord;
    (*phoneBook)->size++;
    return true;
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

char* readStringFromFile(bool* hasReachedEndOfFile, const int startingSizeOfString, FILE* input)
{
    char* inputString = (char*) malloc(startingSizeOfString);
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
            inputString = (char*) realloc(inputString, sizeof(char) * inputStringSize);
        }
    }
    while (inputString[i - 1] != '\n' && inputString[i - 1] != ' ');
    inputString[i - 1] = '\0';

    return inputString;
}

PhoneBook* importPhoneBookFromFile(int capacity)
{
    const int startingSizeOfString = 1000;
    PhoneBook* phoneBook = createPhoneBook(capacity);
    FILE* phoneBookFile = fopen("PhoneBook.txt", "r");

    if (!phoneBookFile)
    {
        printf("Cannot open file\n");
        return phoneBook;
    }

    bool hasReachedEndOfFile = false;
    while (!hasReachedEndOfFile)
    {
        char* currentPhone = readStringFromFile(&hasReachedEndOfFile, startingSizeOfString, phoneBookFile);
        char* currentName = readStringFromFile(&hasReachedEndOfFile, startingSizeOfString, phoneBookFile);
        addRecord(&phoneBook, currentName, currentPhone);

        free(currentName);
        free(currentPhone);
    }
    fclose(phoneBookFile);

    return phoneBook;
}

void saveDataToFile(PhoneBook* phoneBook)
{
    FILE *phoneBookFile = fopen("PhoneBook.txt", "w");

    for (int i = 0; i < phoneBook->size; i++)
    {
        fprintf(phoneBookFile, "%s %s\n", phoneBook->records[i]->phone, phoneBook->records[i]->name);
    }
    fclose(phoneBookFile);
}

void deletePhoneBook(PhoneBook** phoneBook)
{
    for (int i = 0; i < (*phoneBook)->size; i++)
    {
        free((*phoneBook)->records[i]->name);
        free((*phoneBook)->records[i]->phone);
        free((*phoneBook)->records[i]);
    }
    free((*phoneBook)->records);
    free(*phoneBook);
}