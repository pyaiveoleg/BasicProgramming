#include <stdbool.h>

#ifndef BINARY_SEARCH_TREE_TREE_H
#define BINARY_SEARCH_TREE_TREE_H

typedef struct Tree Tree;
typedef struct TreeElement TreeElement;

Tree* createTree();
void addElement(Tree* tree, int value);
bool isTreeEmpty(Tree* tree);
void getSymmetricOrder(Tree* tree, int array[], int* sizeOfArray);
bool findElement(Tree* tree, int value);
void deleteElement(Tree* tree, int value);
void printInABCOrder(Tree* tree);

#endif //BINARY_SEARCH_TREE_TREE_H
