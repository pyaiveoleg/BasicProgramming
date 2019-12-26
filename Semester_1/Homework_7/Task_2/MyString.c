#include "MyString.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct String
{
    int length;
    int maxLength;
    char* text;
};

int getInputLength(const char value[])
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
    newString->text = (char*) malloc((newString->length + 1) * sizeof(char));//для завершающего символа \0
    newString->maxLength = newString->length;
    for (int i = 0; i < newString->length; i++)
    {
        newString->text[i] = value[i];
    }
    newString->text[newString->length] = '\0';
    return newString;
}

Result printString(String* string)
{
    if (string == NULL)
    {
        return fail;
    }
    for (int i = 0; i < string->length; i++)
    {
        printf("%c", string->text[i]);
    }
    printf("\n");
    return success;
}

Result deleteString(String* string)
{
    if (string == NULL)
    {
        return fail;
    }
    free(string->text);
    free(string);
    return success;
}

Result cloneString(String* originalString, String* clonedString)
{
    if (originalString == NULL)
    {
        return fail;
    }
    clonedString = createString(originalString->text);
    return success;
}

void increaseLengthOfString(String* string)
{
    string->maxLength *= 2;
    string->text = (char*) realloc(string->text, string->maxLength);
}

Result concatenationOfStrings(String *firstString, String *secondString, String** concatenatedStrings)
{
    if (firstString == NULL || secondString == NULL)
    {
        return fail;
    }

    char* concatenatedText = (char*) malloc((firstString->length + secondString->length + 1) * sizeof(char));
    for (int i = 0; i < firstString->length; i++)
    {
        concatenatedText[i] = firstString->text[i];
    }
    for (int i = firstString->length; i < firstString->length + secondString->length; i++)
    {
        concatenatedText[i] = secondString->text[i - firstString->length];
    }
    concatenatedText[firstString->length + secondString->length] = '\0';
    deleteString(*concatenatedStrings);
    *concatenatedStrings = createString(concatenatedText);
    free(concatenatedText);
    return success;
}

Result getStringLength(String* string, int* lengthOfString)
{
    if (string == NULL)
    {
        return fail;
    }
    *lengthOfString = string->length;
    return success;
}

Result areStringsEqual(String* firstString, String* secondString, bool* areEqual)
{
    if (firstString == NULL || secondString == NULL)
    {
        return fail;
    }

    if (firstString->length == secondString->length)
    {
        for (int i = 0; i < firstString->length; i++)
        {
            if (firstString->text[i] != secondString->text[i])
            {
                *areEqual = false;
            }
        }
        *areEqual = true;
    }
    else
    {
        *areEqual = false;
    }
    return success;
}

Result getSubstring(String* string, int leftIndex, int rightIndex, String** substring)
{
    if (string == NULL)
    {
        return fail;
    }

    int lengthOfSubstring = rightIndex - leftIndex + 1;
    char substringOfChar[lengthOfSubstring + 1];
    for (int i = 0; i < lengthOfSubstring; i++)
    {
        substringOfChar[i] = string->text[leftIndex + i];
    }
    substringOfChar[lengthOfSubstring] = '\0';
    deleteString(*substring);
    *substring = createString(substringOfChar);
    return success;
}

Result isStringEmpty(String* string, bool* isStringEmpty)
{
    if (string == NULL)
    {
        return fail;
    }
    *isStringEmpty = string->length == 0;
    return success;
}

Result convertToPointerToChar(String* string, char** convertedString)
{
    if (string == NULL)
    {
        return fail;
    }
    *convertedString = string->text;
    return success;
}