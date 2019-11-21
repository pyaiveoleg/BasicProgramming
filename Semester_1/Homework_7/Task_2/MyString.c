#include "MyString.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct String
{
    int length;
    char* text;
    int maxLength;
};

int getInputLength(char value[])
{
    int length = 0;
    while (value[length] != '\0')
    {
        length++;
    }
    return length;
}

String* createString(char* value)
{
    String* newString = (String*) malloc(sizeof(String));
    newString->length = getInputLength(value);
    newString->text = (char*) malloc(newString->length * sizeof(char));
    newString->maxLength = newString->length;
    for (int i = 0; i <= newString->length; i++)
    {
        newString->text[i] = value[i];
    }
    return newString;
}

void printString(String* string)
{
    printf("%s\n", string->text);
}

void deleteString(String* string)
{
    free(string->text);
    free(string);
}

String* cloneString(String* originalString)
{
    String* clonedString = createString(originalString->text);
    return clonedString;
}

void increaseLengthOfString(String* string)
{
    string->text = (char*) realloc(string->text, 2 * string->maxLength);
    string->maxLength *= 2;
}

String* concatenationOfStrings(String* firstString, String* secondString)
{
    String* concatenatedString = createString(firstString->text);
    while (concatenatedString->maxLength < firstString->length + secondString->maxLength)
    {
        increaseLengthOfString(concatenatedString);
    }
    for (int i = firstString->length; i < firstString->length + secondString->length; i++)
    {
        concatenatedString->text[i] = secondString->text[i];
    }

    concatenatedString->length = firstString->length + secondString->length;
    return concatenatedString;
}

int getStringLength(String* string)
{
    return string->length;
}

bool areStringsEqual(String* firstString, String* secondString)
{
    if (firstString->length == secondString->length)
    {
        for (int i = 0; i < firstString->length; i++)
        {
            if (firstString->text != secondString->text)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

String* getSubstring(String* string, int leftIndex, int rightIndex)
{
    int lengthOfSubstring = rightIndex - leftIndex + 1;
    char substring[lengthOfSubstring];
    for (int i = 0; i < lengthOfSubstring; i++)
    {
        substring[i] = string->text[leftIndex + i];
    }

    String* newString = createString(substring);
    return newString;
}

bool isStringEmpty(String* string)
{
    return string->length == 0;
}

char* convertToPointerToChar(String* string)
{
    return string->text;
}