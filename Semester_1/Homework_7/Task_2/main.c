#include <stdio.h>

#include "MyString.h"

void testModuleMyString()
{
    char* a = "1234";
    String* testString = createString(a);
    String* anotherString = createString("56789");

    String* concatenatedString = NULL;
    concatenationOfStrings(testString, anotherString, &concatenatedString);
    printf("This is concatenated string: ");
    printString(concatenatedString);

    String* extract = NULL;
    const int leftIndex = 2;
    const int rightIndex = 4;
    getSubstring(anotherString, leftIndex, rightIndex, &extract);
    printf("This is extract from second string (from %d to %d character): ", leftIndex, rightIndex);
    printString(extract);

    bool equalityOfStrings = false;
    areStringsEqual(testString, anotherString, &equalityOfStrings);
    printf(equalityOfStrings ? "These strings are equal" : "These strings are different");

    deleteString(testString);
    deleteString(anotherString);
    deleteString(concatenatedString);
    deleteString(extract);
}

int main()
{
    testModuleMyString();

    return 0;
}