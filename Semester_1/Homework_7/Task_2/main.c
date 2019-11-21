#include <stdio.h>
#include "MyString.h"

int main()
{
    const int sizeOfString = 10000;
    char* a;
    a = "1234";
    String* testString = createString(a);
    String* anotherString = createString("12345");

    String* concatenatedString = concatenationOfStrings(testString, anotherString);
    String* extract = getSubstring(anotherString, 2, 4);
    printString(concatenatedString);
    printString(extract);
    printf(areStringsEqual(testString, anotherString) ? "These strings are equal" : "These strings are different");

    return 0;
}