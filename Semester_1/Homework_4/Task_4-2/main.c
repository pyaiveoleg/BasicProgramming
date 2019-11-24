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

void workWithPhoneBook(PhoneBook* phoneBook, const int startingStringLength)
{
    int codeOfAction = 0;
    char* currentName = NULL;
    char* currentPhone = NULL;

    while (1)
    {
        printf("Press 1 to add phone number. Press 2 to find number by name.\n"
               "Press 3 to find name by number. Press 4 to export data to file. Press 0 to quit.\n");
        scanf("%d", &codeOfAction);
        switch (codeOfAction)
        {
            case 0:
                return;
            case 1:
                printf("Please, write down the name:\n");
                fflush(stdin);
                currentName = readString(startingStringLength);
                printf("Please, write down the phone:\n");
                currentPhone = readString(startingStringLength);
                addRecord(phoneBook, currentName, currentPhone);
                printf("Added successfully.\n");
                break;
            case 2:
                printf("Please, write down the name:\n");
                fflush(stdin);
                currentName = readString(startingStringLength);
                printf("Number: %s\n", searchByName(phoneBook, currentName));
                break;
            case 3:
                printf("Please, write down the phone number:\n");
                fflush(stdin);
                currentPhone = readString(startingStringLength);
                printf("Name: %s\n", searchByPhone(phoneBook, currentPhone));
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
    const int startingCapacity = 1000;
    const int startingStringLength = 1000;

    PhoneBook* phoneBook = importPhoneBookFromFile(startingCapacity);
    workWithPhoneBook(phoneBook, startingStringLength);
}