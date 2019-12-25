#pragma once

bool convertInfixToPostfix(char *inputExpression, int resultingArray[],
        int* currentIndexInResultingArray, int shiftForOperators);

void convertResultingArrayToString(int* resultingArray, int sizeOfResultingArray, int shiftForOperators,
                                   size_t stringLength, char* resultingString);
bool isOperator(char symbol);
bool isDigit(char symbol);