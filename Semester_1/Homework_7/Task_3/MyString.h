#pragma once

#include <stdbool.h>

typedef enum Result
{
    kResult_Ok,
    kResult_Fail,
} Result;

typedef struct String
{
    int length;
    char* text;
    int maxLength;
} String;

String* createString(char value[]);
Result deleteString(String* string);
Result cloneString(String* originalString, String* clonedString);
Result concatenationOfStrings(String* firstString, String* secondString, String** concatenatedStrings);
Result printString(String* string);
Result areStringsEqual(String* firstString, String* secondString, bool* equalityOfStrings);
Result getStringLength(String* string, int* lengthOfString);
Result getSubstring(String* string, int leftIndex, int rightIndex, String** substring);
Result isStringEmpty(String* string, bool* isStringEmpty);
Result convertToPointerToChar(String* string, char** convertedString);
