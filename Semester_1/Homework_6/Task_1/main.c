#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() 
{
    unsigned int bit = 2147483648; //единица и 31 ноль
    const int sizeOfSign = 1;
    const int sizeOfExponent = 8;
    const int bitesInByte = 8;
    const int sizeOfMantissa = bitesInByte * sizeof(float) - sizeOfSign - sizeOfExponent;

    float testVariable = 0;
    printf("Enter a number:\n");
    scanf("%f", &testVariable);
    unsigned int* pointerToVariable = (unsigned int*) &testVariable;
    unsigned int convertedVariable = *pointerToVariable;

    bool isPositive = true;
    if (convertedVariable & bit)
    {
        isPositive = false;
    }
    bit = bit >> 1;

    int shiftedExponent = 0;
    for (int j = 1; j <= sizeOfExponent; j++)
    {
        if (convertedVariable & bit)
        {
            shiftedExponent += pow(2, sizeOfExponent - j);
        }
        bit = bit >> 1;
    }
    int exponent = shiftedExponent - (pow(2, sizeOfExponent - 1) - 1);

    double valueOfMantissa = 0;
    for (int j = 1; j <= sizeOfMantissa; j++)
    {
        if (convertedVariable & bit)
        {
            valueOfMantissa += pow(2, - j);
        }
        bit = bit >> 1;
    }

    double normalizedValue = 1 + valueOfMantissa;
    if (!isPositive)
    {
        normalizedValue *= -1;
    }

    printf("%lf * 2 ^ %d", normalizedValue, exponent);

    return 0;
}