#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    const int maxStringLength = 1000;
    const int lengthOfDate = 10;
    const int codeOfZero = (int) '0';

    FILE *input;
    input = fopen("input.txt", "r");

    char inputString[maxStringLength];
    int dayInMinDate = 99;
    int monthInMinDate = 99;
    int yearInMinDate = 9999;

    if (!input)
    {
        printf("Error. Cannot open file.");
        return 0;
    }
    while (!feof(input))
    {
        fscanf(input, "%s", inputString);
        if ((strcmp(inputString, "00.00.0000") >= 0) && (strcmp(inputString, "99.99.9999") <= 0) && (strlen(inputString) == lengthOfDate))//если дата
        {
            int dayInCurrentDate = 10 * (inputString[0] - codeOfZero) + inputString[1] - codeOfZero;
            int monthInCurrentDate = 10 * (inputString[3] - codeOfZero) + inputString[4] - codeOfZero;
            int yearInCurrentDate = 0;
            for (int i = 1; i <= 4; i++)
            {
                yearInCurrentDate += (inputString[lengthOfDate - i] - codeOfZero) * (int) pow(10, i - 1);
            }

            if ((yearInCurrentDate < yearInMinDate) || ((yearInCurrentDate == yearInMinDate) && (monthInCurrentDate < monthInMinDate))
            || ((yearInCurrentDate == yearInMinDate) && (monthInCurrentDate == monthInMinDate) && (dayInCurrentDate < dayInMinDate)))
            {
                dayInMinDate = dayInCurrentDate;
                monthInMinDate = monthInCurrentDate;
                yearInMinDate = yearInCurrentDate;
            }
        }
    }
    fclose(input);

    printf("The least date in input file is: %d.%d.%d", dayInMinDate, monthInMinDate, yearInMinDate);

    return 0;
}