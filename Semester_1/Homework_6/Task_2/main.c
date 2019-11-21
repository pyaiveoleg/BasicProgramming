#include <stdio.h>
#include <math.h>

void printBinaryForm(int binaryForm[], int bitesInInteger, char description[])
{
    printf("%s", description);
    for (int i = bitesInInteger - 1; i >= 0; i--)
    {
        printf("%d ", binaryForm[i]);
    }
    printf("\n");
}

int main()
{
    printf("Please, write down two numbers to convert in binary and summarize them:\n");
    int firstOperand = 0;
    int secondOperand = 0;
    scanf("%d %d", &firstOperand, &secondOperand);

    const int bitesInInteger = 8 * sizeof(int);
    int binaryFormOfFirstOperand[bitesInInteger];
    int binaryFormOfSecondOperand[bitesInInteger];
    int binaryFormOfSum[bitesInInteger];
    int decimalSum = 0;
    int carry = 0;
    
    for (int i = 0; i < bitesInInteger; i++)
    {
        binaryFormOfFirstOperand[i] = (firstOperand >> i) & 1;
        binaryFormOfSecondOperand[i] = (secondOperand >> i) & 1;

        binaryFormOfSum[i] = binaryFormOfFirstOperand[i] + binaryFormOfSecondOperand[i] + carry;
        if (binaryFormOfSum[i] >= 2)
        {
            binaryFormOfSum[i] -= 2;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        decimalSum += binaryFormOfSum[i] * (int) pow(2, i);
    }

    printBinaryForm(binaryFormOfFirstOperand, bitesInInteger, "Binary form of first operand is:\n");
    printBinaryForm(binaryFormOfSecondOperand, bitesInInteger, "Binary form of second operand is:\n");
    printBinaryForm(binaryFormOfSum, bitesInInteger, "Binary form of sum is:\n");
    printf("Decimal form of sum operand is:\n%d\n", decimalSum);

    return 0;
}