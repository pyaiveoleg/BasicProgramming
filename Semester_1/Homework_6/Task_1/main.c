#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void convertToExponentialForm(float testVariable, double* normalizedValue, int* exponent)
{
    unsigned int bit = 2147483648; //единица и 31 ноль
    const int sizeOfSign = 1;
    const int sizeOfExponent = 8;
    const int bitesInByte = 8;
    const unsigned int sizeOfMantissa = (unsigned int) bitesInByte * sizeof(float) - sizeOfSign - sizeOfExponent;

    unsigned int* pointerToVariable = (unsigned int*) &testVariable;
    unsigned int convertedVariable = *pointerToVariable;

    if (testVariable == 0)
    {
        *normalizedValue = 0.0;
        *exponent = 0;
        return;
    }

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
            shiftedExponent += (int) pow(2, sizeOfExponent - j);
        }
        bit = bit >> 1;
    }
    *exponent = (int) (shiftedExponent - (pow(2, sizeOfExponent - 1) - 1));

    double valueOfMantissa = 0;
    for (int j = 1; j <= sizeOfMantissa; j++)
    {
        if (convertedVariable & bit)
        {
            valueOfMantissa += pow(2, - j);
        }
        bit = bit >> 1;
    }

    *normalizedValue = 1 + valueOfMantissa;
    if (!isPositive)
    {
        (*normalizedValue) *= -1;
    }
}

int main() 
{
    float testVariable = 0;
    printf("Enter a number:\n");
    scanf("%f", &testVariable);

    double normalizedValue = 0;
    int exponent = 0;
    convertToExponentialForm(testVariable, &normalizedValue, &exponent);
    printf("%lf * 2 ^ %d", normalizedValue, exponent);

    return 0;
}