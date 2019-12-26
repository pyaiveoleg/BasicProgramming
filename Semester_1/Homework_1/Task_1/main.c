#include <stdio.h>

int main()
{
	int variableX = 0;

	printf("Please, write down X: ");
	scanf("%d", &variableX);

	long long squareOfX = variableX * variableX;
	long long formulaValue = (squareOfX + variableX) * (squareOfX + 1) + 1;

	printf("The value of x^4 + x^3 + x^2 + x + 1: %d", formulaValue);

	return 0;
}
