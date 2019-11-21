#include <stdio.h>
#include "PhoneBook.h"

int main()
{
    const int startingCapacity = 1000;
    const int maxStringLength = 1000;

    PhoneBook* phoneBook = importPhoneBookFromFile(startingCapacity);

    int codeOfAction = 0;
    char currentName[maxStringLength];
    char currentPhone[maxStringLength];
    char foundPhone[maxStringLength];
    char foundName[maxStringLength];
    for (int i = 0; i < maxStringLength; i++)
    {
        currentName[i] = '\0';
        currentPhone[i] = '\0';
        foundPhone[i] = '\0';
        foundName[i] = '\0';
    }

    while (1)
    {
        printf("Press 1 to add phone number. Press 2 to find number by name.\n"
               "Press 3 to find name by number. Press 4 to export data to file. Press 0 to quit.\n");
        scanf("%d", &codeOfAction);
        switch (codeOfAction)
        {
            case 0:
                return 0;
            case 1:
                printf("Please, write down the name:\n");
                fflush(stdin);
                gets(currentName);
                printf("Please, write down the phone:\n");
                scanf("%s", currentPhone);
                addRecord(phoneBook, currentName, currentPhone);
                printf("Added successfully.\n");
                break;
            case 2:
                printf("Please, write down the name:\n");
                fflush(stdin);
                gets(currentName);
                printf("Number: %s\n", searchByName(phoneBook, currentName));
                break;
            case 3:
                printf("Please, write down the phone number:\n");
                fflush(stdin);
                gets(currentPhone);
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