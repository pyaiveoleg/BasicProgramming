#pragma once

#include <stdbool.h>

typedef struct Tree Tree;
typedef struct TreeElement TreeElement;

typedef enum Result
{
    success,
    fail,
} Result;

Tree* createTree();
Result addElement(Tree* tree, int value);
Result getSymmetricOrder(Tree* tree, int array[], int* sizeOfArray, int* maxSizeOfArray);
Result findElement(Tree* tree, int value, bool* existenceOfElement);
Result deleteElement(Tree* tree, int value);
Result printInABCOrder(Tree* tree, bool* isTreeEmpty);
Result deleteTree(Tree** tree);
