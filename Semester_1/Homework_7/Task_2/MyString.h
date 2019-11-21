#ifndef INC_7_2_STRING_H
#define INC_7_2_STRING_H
#include <stdbool.h>

typedef struct String String;

String* createString(char value[]);
void deleteString(String* string);
String* cloneString(String* originalString);
String* concatenationOfStrings(String* firstString, String* secondString);
void printString(String* string);
bool areStringsEqual(String* firstString, String* secondString);
int getStringLength(String* string);
String* getSubstring(String* string, int leftIndex, int rightIndex);
bool isStringEmpty(String* string);
char* convertToPointerToChar(String* string);

#endif //INC_7_2_STRING_H
