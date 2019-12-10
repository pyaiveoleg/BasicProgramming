#include "MyString.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
    newString->text = (char*) malloc(newString->length * sizeof(char));
    newString->maxLength = newString->length;
    for (int i = 0; i <= newString->length; i++)
    {
        newString->text[i] = value[i];
    }
    return newString;
}

Result printString(String* string)
{
    if (string == NULL)
    {
        printf("1");
        return  kResult_Fail;
    }
    printf("%s\n", string->text);
    return kResult_Ok;
}

Result deleteString(String* string)
{
    if (string == NULL)
    {
        return  kResult_Fail;
    }
    free(string->text);
    free(string);
    return kResult_Ok;
}

Result cloneString(String* originalString, String* clonedString)
{
    if (originalString == NULL)
    {
        return  kResult_Fail;
    }
    clonedString = createString(originalString->text);
    return kResult_Ok;
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
        return kResult_Fail;
    }

    *concatenatedStrings = createString(firstString->text);


    while ((*concatenatedStrings)->maxLength < firstString->length + secondString->length)
    {
        increaseLengthOfString(*concatenatedStrings);
    }

    for (int i = firstString->length; i < firstString->length + secondString->length; i++)
    {
        (*concatenatedStrings)->text[i] = secondString->text[i - firstString->length];
    }
    (*concatenatedStrings)->length = firstString->length + secondString->length;

    return kResult_Ok;
}

Result getStringLength(String* string, int* lengthOfString)
{
    if (string == NULL)
    {
        return  kResult_Fail;
    }
    *lengthOfString = string->length;
    return kResult_Ok;
}

Result areStringsEqual(String* firstString, String* secondString, bool* equalityOfStrings)
{
    if (firstString == NULL || secondString == NULL)
    {
        //*equalityOfStrings = false;
        return  kResult_Fail;
    }

    if (firstString->length == secondString->length)
    {
        for (int i = 0; i < firstString->length; i++)
        {
            if (firstString->text[i] != secondString->text[i])
            {
                *equalityOfStrings = false;
            }
        }
        *equalityOfStrings = true;
    }
    else
    {
        *equalityOfStrings = false;
    }
    return kResult_Ok;
}

Result getSubstring(String* string, int leftIndex, int rightIndex, String** substring)
{
    if (string == NULL)
    {
        return  kResult_Fail;
    }

    int lengthOfSubstring = rightIndex - leftIndex + 1;
    char substringOfChar[lengthOfSubstring];
    for (int i = 0; i < lengthOfSubstring; i++)
    {
        substringOfChar[i] = string->text[leftIndex + i];
    }

    String* pointerToSubstring = createString(substringOfChar);
    *substring = pointerToSubstring;

    return kResult_Ok;
}

Result isStringEmpty(String* string, bool* isStringEmpty)
{
    if (string == NULL)
    {
        return  kResult_Fail;
    }
    *isStringEmpty = string->length == 0;
    return kResult_Ok;
}

Result convertToPointerToChar(String* string, char** convertedString)
{
    if (string == NULL)
    {
        return  kResult_Fail;
    }
    *convertedString = string->text;
    return kResult_Ok;
}