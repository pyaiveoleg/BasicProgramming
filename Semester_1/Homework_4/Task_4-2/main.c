#include <stdio.h>
#include <stdlib.h>

#include "PhoneBook.h"

char* readString(size_t startingSizeOfString)
{
    char* currentString = (char*) calloc(startingSizeOfString, sizeof(char));
    int currentStringSize = startingSizeOfString;

    int i = 0;
    currentString[0] = (char) getchar();
    while (currentString[i] != '\n' || i == 0)
    {
        if (currentString[i] == '\n' && i == 0)//игнорирует пустые строки
        {
            currentString[i] = '\0';
            i--;
        }
        i++;

        if (i >= currentStringSize)
        {
            currentStringSize *= 2;
            currentString = (char *) realloc(currentString, sizeof(char) * currentStringSize);
        }
        currentString[i] = (char) getchar();
    }
    currentString[i] = '\0';

    return currentString;
}

void addNumber(PhoneBook* phoneBook, const int startingStringLength)
{
    printf("Please, write down the name:\n");
    char* currentName = readString(startingStringLength);
    printf("Please, write down the phone:\n");
    char* currentPhone = readString(startingStringLength);
    if (addRecord(&phoneBook, currentName, currentPhone))
    {
        printf("Added successfully.\n");
    }
    else
    {
        printf("Error.\n");
    }
    free(currentName);
    free(currentPhone);
}

void findNumber(PhoneBook* phoneBook, const int startingStringLength)
{
    printf("Please, write down the name:\n");
    char* currentName = readString(startingStringLength);
    printf("Number: %s\n", searchByName(phoneBook, currentName));
    free(currentName);
}

void findName(PhoneBook* phoneBook, const int startingStringLength)
{
    printf("Please, write down the phone number:\n");
    char* currentPhone = readString(startingStringLength);
    printf("Name: %s\n", searchByPhone(phoneBook, currentPhone));
    free(currentPhone);
}

void workWithPhoneBook(PhoneBook* phoneBook, const int startingStringLength)
{
    int codeOfAction = 0;
    bool isInterrupted = false;

    while (!isInterrupted)
    {
        printf("Press 1 to add phone number. Press 2 to find number by name.\n"
               "Press 3 to find name by number. Press 4 to export data to file. Press 0 to quit.\n");
        scanf("%d", &codeOfAction);
        switch (codeOfAction)
        {
            case 0:
            {
                isInterrupted = true;
                break;
            }
            case 1:
            {
                addNumber(phoneBook, startingStringLength);
                break;
            }
            case 2:
            {
                findNumber(phoneBook, startingStringLength);
                break;
            }
            case 3:
            {
                findName(phoneBook, startingStringLength);
                break;
            }
            case 4:
            {
                saveDataToFile(phoneBook);
                printf("Saved successfully.\n");
                break;
            }
            default:
            {
                printf("Error. Invalid command.\n");
                break;
            }
        }
    }
}

int main()
{
    const int startingCapacity = 100;
    const int startingStringLength = 100;

    PhoneBook* phoneBook = importPhoneBookFromFile(startingCapacity);
    workWithPhoneBook(phoneBook, startingStringLength);
    deletePhoneBook(&phoneBook);
    return 0;
}