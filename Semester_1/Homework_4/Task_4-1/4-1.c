#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define maxQuantityOfNotes 1000
#define maxNameLength 1000

int searchByName(char names[maxQuantityOfNotes][maxNameLength], char name[], int quantityOfNotes)
{
    for (int i = 0; i < quantityOfNotes; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int searchByPhone(unsigned long long phones[], unsigned long long phone, int quantityOfNotes)
{
    for (int i = 0; i < quantityOfNotes; i++)
    {
        if (phone == phones[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    unsigned long long phones[maxQuantityOfNotes];
    unsigned long long phoneForSearch = 0;
    char names[maxQuantityOfNotes][maxNameLength];
    char nameForSearch[maxNameLength];
    for (int i = 0; i < maxQuantityOfNotes; i++)
    {
        phones[i] = 0;
        names[i][0] = '0';
        nameForSearch[i] = '0';
    }
    int currentNumber = 0;
    int codeOfAction = 0;
    int foundName = 0;
    int foundPhone = 0;

    FILE *input;
    FILE *output;
    input = fopen("input.txt", "r");

    if (input)
    {
        while (!feof(input))
        {
            fscanf(input, "%llu %[^\n]", &phones[currentNumber], &names[currentNumber]);
            currentNumber++;
        }
    }
    fclose(input);

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
                printf("Write down number and name:\n");
                scanf("%llu %[^\n]", &phones[currentNumber], &names[currentNumber]);
                currentNumber++;
                break;
            case 2:
                printf("Please, write down the name:\n");
                scanf("%[\n]%[^\n]", &nameForSearch, &nameForSearch);
                //gets(nameForSearch);
                foundPhone = searchByName(names, nameForSearch, currentNumber);
                if (foundPhone != -1)
                {
                    printf("%llu\n", phones[foundPhone]);
                }
                else
                {
                    printf("Error 404. Name not found.\n");
                }
                break;
            case 3:
                printf("Please, write down the phone number:\n");
                scanf("%llu", &phoneForSearch);
                foundName = searchByPhone(phones, phoneForSearch, currentNumber);
                if (foundName != -1)
                {
                    printf("%s\n", names[foundName]);
                }
                else
                {
                    printf("Error 404. Phone number not found.\n");
                }
                break;
            case 4:
                output = fopen("output.txt", "w");
                for (int i = 0; i < currentNumber; i++)
                {
                    fprintf(output, "%llu %s\n", phones[i], names[i]);
                }
                fclose(output);
                break;
            default:
                printf("Error. Invalid command.\n");
                break;
        }
    }
    return 0;
}