#pragma once

struct PhoneBook;
typedef struct PhoneBook PhoneBook;

PhoneBook* createPhoneBook(int capacity);
void addRecord(PhoneBook* phoneBook, char name[], char phone[]);
char* searchByName(PhoneBook* phoneBook, char name[]);
char* searchByPhone(PhoneBook* phoneBook, char phone[]);
PhoneBook* importPhoneBookFromFile(int capacity);
void saveDataToFile(PhoneBook* phoneBook);
