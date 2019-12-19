#pragma once

#include <stdbool.h>

typedef enum Result
{
    success,
    fail,
} Result;

typedef struct String
{
    int length;
    int maxLength;
    char* text;
} String;

String* createString(char value[]);
Result deleteString(String* string);
Result cloneString(String* originalString, String* clonedString);
Result concatenationOfStrings(String* firstString, String* secondString, String** concatenatedStrings);
Result printString(String* string);
Result areStringsEqual(String* firstString, String* secondString, bool* areEqual);
Result getStringLength(String* string, int* lengthOfString);
Result getSubstring(String* string, int leftIndex, int rightIndex, String** substring);
Result isStringEmpty(String* string, bool* isStringEmpty);
Result convertToPointerToChar(String* string, char** convertedString);
