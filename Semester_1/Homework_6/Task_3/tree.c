#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

struct TreeElement
{
    int value;
    TreeElement* leftChild;
    TreeElement* rightChild;
};

struct Tree
{
    TreeElement* root;
};

Tree* createTree()
{
    Tree* newTree = malloc (sizeof(TreeElement));
    newTree->root = NULL;
    return newTree;
}

TreeElement* createTreeElement(int value)
{
    TreeElement* newTreeElement = (TreeElement *) malloc (sizeof(TreeElement));
    newTreeElement->value = value;
    newTreeElement->leftChild = NULL;
    newTreeElement->rightChild = NULL;
    return newTreeElement;
}

void addElement(Tree* tree, int value)
{
    TreeElement* newTreeElement = createTreeElement(value);

    if (isTreeEmpty(tree))
    {
        tree->root = newTreeElement;
        return;
    }

    TreeElement* currentElement = tree->root;

    while (true)
    {
        if (currentElement->value < value)
        {
            if (currentElement->rightChild == NULL)
            {
                currentElement->rightChild = newTreeElement;
                return;
            }
            currentElement = currentElement->rightChild;
        }
        else if (currentElement->value > value)
        {
            if (currentElement->leftChild == NULL)
            {
                currentElement->leftChild = newTreeElement;
                return;
            }
            currentElement = currentElement->leftChild;
        }
        else
        {
            return;
        }
    }
}

bool isTreeEmpty(Tree* tree)
{
    return tree->root == NULL;
}

void processSymmetricOrder(TreeElement* treeElement, int *array, int* sizeOfArray)
{
    if (treeElement == NULL)
    {
        return;
    }
    processSymmetricOrder(treeElement->leftChild, array, sizeOfArray);
    array[*sizeOfArray] = treeElement->value;
    (*sizeOfArray)++;
    processSymmetricOrder(treeElement->rightChild, array, sizeOfArray);
}

void getSymmetricOrder(Tree* tree, int array[], int* sizeOfArray)
{
    processSymmetricOrder(tree->root, array, sizeOfArray);
}

bool findElement(Tree* tree, int value)
{
    TreeElement* currentElement = tree->root;
    while (true)
    {
        if (currentElement == NULL)
        {
            return false;
        }
        else if (value == currentElement->value)
        {
            return true;
        }
        else if (value < currentElement->value)
        {
            currentElement = currentElement->leftChild;
        }
        else
        {
            currentElement = currentElement->rightChild;
        }
    }
}

void deleteElement(Tree* tree, int value)
{
    TreeElement* parentElement = NULL;
    TreeElement* currentElement = tree->root;

    while (true)
    {
        if (currentElement == NULL)
        {
            return;
        }

        if (value == currentElement->value)
        {
            break;
        }
        else
        {
            parentElement = currentElement;
            currentElement = (value < currentElement->value) ? currentElement->leftChild : currentElement->rightChild;
        }
    }

    bool isLeftChild = parentElement->value > currentElement->value;

    if (currentElement->leftChild == NULL)
    {
        if (currentElement->rightChild == NULL)
        {
            if (isLeftChild)
            {
                parentElement->leftChild = NULL;
            }
            else
            {
                parentElement->rightChild = NULL;
            }
        }
        else
        {
            if (isLeftChild)
            {
                parentElement->leftChild = currentElement->rightChild;
            }
            else
            {
                parentElement->rightChild = currentElement->rightChild;
            }
        }
    }
    else if (currentElement->rightChild == NULL)
    {
        if (currentElement->leftChild == NULL)
        {
            if (isLeftChild)
            {
                parentElement->leftChild = NULL;
            }
            else
            {
                parentElement->rightChild = NULL;
            }
        }
        else
        {
            if (isLeftChild)
            {
                parentElement->leftChild = currentElement->leftChild;
            }
            else
            {
                parentElement->rightChild = currentElement->leftChild;
            }
        }
    }

    free(currentElement);
}