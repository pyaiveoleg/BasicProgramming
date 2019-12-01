#pragma once

#include <stdbool.h>

struct PhoneBook;
typedef struct PhoneBook PhoneBook;

PhoneBook* createPhoneBook(int capacity);
bool addRecord(PhoneBook* phoneBook, char name[], char phone[]);
char* searchByName(PhoneBook* phoneBook, char name[]);
char* searchByPhone(PhoneBook* phoneBook, char phone[]);
PhoneBook* importPhoneBookFromFile(int capacity);
void saveDataToFile(PhoneBook* phoneBook);
void deletePhoneBook(PhoneBook* phoneBook);
