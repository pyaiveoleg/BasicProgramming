#include <stdio.h>
#include <stdlib.h>

#include "PhoneBook.h"

char* readString(size_t startingSizeOfString)
{
    char *currentString = (char *) malloc(sizeof(char) * startingSizeOfString);
    int currentStringSize = startingSizeOfString;

    int i = 0;
    do
    {
        currentString[i] = (char) getchar();
        i++;
        if (i >= currentStringSize) {
            currentStringSize *= 2;
            currentString = (char *) realloc(currentString, sizeof(char) * currentStringSize);
        }
    }
    while (currentString[i - 1] != '\n');
    currentString[i - 1] = '\0';

    return currentString;
}

void addNumber(PhoneBook* phoneBook, const int startingStringLength)
{
    printf("Please, write down the name:\n");
    fflush(stdin);
    char* currentName = readString(startingStringLength);
    printf("Please, write down the phone:\n");
    char* currentPhone = readString(startingStringLength);
    if (addRecord(phoneBook, currentName, currentPhone))
    {
        printf("Added successfully.\n");
    }
    else
    {
        printf("Not 11 digits in number.\n");
    }
    free(currentName);
    free(currentPhone);
}

void findNumber(PhoneBook* phoneBook, const int startingStringLength)
{
    printf("Please, write down the name:\n");
    fflush(stdin);
    char* currentName = readString(startingStringLength);
    printf("Number: %s\n", searchByName(phoneBook, currentName));
    free(currentName);
}

void findName(PhoneBook* phoneBook, const int startingStringLength)
{
    printf("Please, write down the phone number:\n");
    fflush(stdin);
    char* currentPhone = readString(startingStringLength);
    printf("Name: %s\n", searchByPhone(phoneBook, currentPhone));
    free(currentPhone);
}

void workWithPhoneBook(PhoneBook* phoneBook, const int startingStringLength)
{
    int codeOfAction = 0;

    while (1)
    {
        printf("Press 1 to add phone number. Press 2 to find number by name.\n"
               "Press 3 to find name by number. Press 4 to export data to file. Press 0 to quit.\n");
        scanf("%d", &codeOfAction);
        switch (codeOfAction)
        {
            case 0:
                deletePhoneBook(phoneBook);
                return;
            case 1:
                addNumber(phoneBook, startingStringLength);
                break;
            case 2:
                findNumber(phoneBook, startingStringLength);
                break;
            case 3:
                findName(phoneBook, startingStringLength);
                break;
            case 4:
                saveDataToFile(phoneBook);
                printf("Saved successfully.\n");
                break;
            default:
                printf("Error. Invalid command.\n");
                break;
        }
    }
}

int main()
{
    const int startingCapacity = 1;
    const int startingStringLength = 1;

    PhoneBook* phoneBook = importPhoneBookFromFile(startingCapacity);
    workWithPhoneBook(phoneBook, startingStringLength);
}