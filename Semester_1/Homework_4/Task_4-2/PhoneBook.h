#ifndef INC_4_2_PHONEBOOK_H
#define INC_4_2_PHONEBOOK_H

struct PhoneBook;
typedef struct PhoneBook PhoneBook;

PhoneBook* createPhoneBook(int capacity);
void addRecord(PhoneBook* phoneBook, char name[], char phone[]);
char* searchByName(PhoneBook* phoneBook, char name[]);
char* searchByPhone(PhoneBook* phoneBook, char phone[]);
PhoneBook* importPhoneBookFromFile(int capacity);
void saveDataToFile(PhoneBook* phoneBook);

#endif //INC_4_2_PHONEBOOK_H
