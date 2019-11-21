#include "PhoneBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxQuantityOfNotes 1000
#define maxStringLength 1000
#define phoneNumberLength 11

typedef struct Record Record;

struct Record
{
    char name[maxStringLength];
    char phone[phoneNumberLength];
};

struct PhoneBook
{
    int capacity;
    Record* records[maxQuantityOfNotes];
    int size;

};

PhoneBook* createPhoneBook(int capacity)
{
    PhoneBook* newBook = malloc(sizeof(Record*) * capacity + 2 * sizeof(int));
    newBook->size = 0;
    newBook->capacity = capacity;
    return newBook;
}

void expand(PhoneBook* phoneBook)
{
    phoneBook = realloc(phoneBook, phoneBook->capacity * 2);
    phoneBook->capacity *= 2;
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
        expand(phoneBook);
    }

    Record* addedRecord = createRecord();
    strcpy(addedRecord->name, name);
    strcpy(addedRecord->phone, phone);

    phoneBook->records[phoneBook->size] = addedRecord;
    (phoneBook->size)++;

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
    PhoneBook* phoneBook = createPhoneBook(capacity);
    FILE *phoneBookFile;
    phoneBookFile = fopen("PhoneBook.txt", "r");

    char currentPhone[maxStringLength];
    char currentName[maxStringLength];

    if (phoneBookFile)
    {
        while (!feof(phoneBookFile))
        {
            fscanf(phoneBookFile, "%s %[^\n]s", currentPhone, currentName);
            addRecord(phoneBook, currentName, currentPhone);
        }
    }
    fclose(phoneBookFile);

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