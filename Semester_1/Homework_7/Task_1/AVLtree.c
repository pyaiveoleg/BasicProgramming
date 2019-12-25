#include "AVLtree.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct TreeElement
{
    int value;
    int height;
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
    newTreeElement->height = 0;
    return newTreeElement;
}

bool isTreeEmpty(Tree* tree)
{
    return tree->root == NULL;
}

void processSymmetricOrder(TreeElement* treeElement, int *array, int* sizeOfArray, int* maxSizeOfArray)
{
    if (treeElement == NULL)
    {
        return;
    }
    processSymmetricOrder(treeElement->leftChild, array, sizeOfArray, maxSizeOfArray);

    if (*sizeOfArray == *maxSizeOfArray - 1)
    {
        (*maxSizeOfArray) *= 2;
        array = (int*) realloc(array, *maxSizeOfArray);
    }

    array[*sizeOfArray] = treeElement->value;
    (*sizeOfArray)++;
    processSymmetricOrder(treeElement->rightChild, array, sizeOfArray, maxSizeOfArray);
}

Result getSymmetricOrder(Tree* tree, int array[], int* sizeOfArray, int* maxSizeOfArray)
{
    if (tree == NULL)
    {
        return fail;
    }
    if (tree->root == NULL)
    {
        return success;
    }
    processSymmetricOrder(tree->root, array, sizeOfArray, maxSizeOfArray);
    return success;
}

Result findElement(Tree* tree, int value, bool* existenceOfElement)
{
    if (tree == NULL)
    {
        return fail;
    }
    TreeElement* currentElement = tree->root;
    while (true)
    {
        if (currentElement == NULL)
        {
            *existenceOfElement = false;
            return success;
        }
        else if (value == currentElement->value)
        {
            *existenceOfElement = true;
            return success;
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

void printElementsInABCOrder(TreeElement* treeElement)
{
    printf("(%d ", treeElement->value);

    if (treeElement->leftChild == NULL)
    {
        printf("null");
    }
    else
    {
        printElementsInABCOrder(treeElement->leftChild);
    }

    printf(" ");

    if (treeElement->rightChild == NULL)
    {
        printf("null");
    }
    else
    {
        printElementsInABCOrder(treeElement->rightChild);
    }

    printf(")");
}

Result printInABCOrder(Tree* tree, bool* isTreeEmpty)
{
    if (tree == NULL)
    {
        return fail;
    }
    if (tree->root == NULL)
    {
        *isTreeEmpty = true;
        return success;
    }
    printElementsInABCOrder(tree->root);
    return success;
}

int getHeight(TreeElement* treeElement)
{
    return (treeElement == NULL) ? -1 : treeElement->height;;
}

int getBalanceFactor(TreeElement* treeElement)
{
    return getHeight(treeElement->rightChild) - getHeight(treeElement->leftChild);
}

void updateHeight(TreeElement* treeElement)
{
    int leftHeight = getHeight(treeElement->leftChild);
    int rightHeight = getHeight(treeElement->rightChild);
    treeElement->height = (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

TreeElement* rotateRight(TreeElement* root, Tree* tree, TreeElement* parentElement)
{
    TreeElement* pivot = root->leftChild;
    root->leftChild = pivot->rightChild;
    pivot->rightChild = root;
    updateHeight(root);
    updateHeight(pivot);
    if (root == tree->root)
    {
        tree->root = pivot;
    }
    else if (parentElement->value > pivot->value)
    {
        parentElement->leftChild = pivot;
    }
    else
    {
        parentElement->rightChild = pivot;
    }
    return pivot;
}

TreeElement* rotateLeft(TreeElement* root, Tree* tree, TreeElement* parentElement)
{
    TreeElement* pivot = root->rightChild;
    root->rightChild = pivot-> leftChild;
    pivot->leftChild = root;
    updateHeight(root);
    updateHeight(pivot);
    if (root == tree->root)
    {
        tree->root = pivot;
    }
    else if (parentElement->value > pivot->value)
    {
        parentElement->leftChild = pivot;
    }
    else
    {
        parentElement->rightChild = pivot;
    }
    return pivot;
}

TreeElement* balance(TreeElement* treeElement, Tree* tree, TreeElement* parentElement)
{
    updateHeight(treeElement);
    if (getBalanceFactor(treeElement) == 2)
    {
        if (getBalanceFactor(treeElement->rightChild) < 0)
        {
            treeElement->rightChild = rotateRight(treeElement->rightChild, tree, parentElement);
        }
        return rotateLeft(treeElement, tree, parentElement);
    }
    else if (getBalanceFactor(treeElement) == -2)
    {
        if (getBalanceFactor(treeElement->leftChild) > 0)
        {
            treeElement->leftChild = rotateLeft(treeElement->leftChild, tree, parentElement);
        }
        return rotateRight(treeElement, tree, parentElement);
    }
    return treeElement;
}

void insert(TreeElement* treeElement, int value, Tree* tree, TreeElement* parentElement)
{
    if (value < treeElement->value)
    {
        if (treeElement->leftChild == NULL)
        {
            TreeElement* newTreeElement = createTreeElement(value);
            treeElement->leftChild = newTreeElement;
        }
        else
        {
            insert(treeElement->leftChild, value, tree, treeElement);
        }
    }
    else if (value > treeElement->value)
    {
        if (treeElement->rightChild == NULL)
        {
            TreeElement* newTreeElement = createTreeElement(value);
            treeElement->rightChild = newTreeElement;
        }
        else
        {
            insert(treeElement->rightChild, value, tree, treeElement);
        }
    }
    balance(treeElement, tree, parentElement);
}

Result addElement(Tree* tree, int value)
{
    if (tree == NULL)
    {
        return fail;
    }

    if (tree->root == NULL)
    {
        TreeElement* newTreeElement = createTreeElement(value);
        tree->root = newTreeElement;
    }
    else
    {
        insert(tree->root, value, tree, NULL);
    }
    return success;
}

int findMaxInSubTree(TreeElement* currentElement)
{
    return currentElement->rightChild == NULL ? currentElement->value : findMaxInSubTree(currentElement->rightChild);
}

void parseLeaf(TreeElement* currentElement, Tree* tree, bool isLeftChild, TreeElement* parentElement)
{
    if (currentElement == tree->root)
    {
        tree->root = NULL;
    }
    else if (isLeftChild)
    {
        parentElement->leftChild = NULL;
    }
    else
    {
        parentElement->rightChild = NULL;
    }
}

void parseLeftNULL(TreeElement* currentElement, Tree* tree, bool isLeftChild, TreeElement* parentElement)
{
    if (currentElement == tree->root)
    {
        tree->root = currentElement->rightChild;
    }
    else if (isLeftChild)
    {
        parentElement->leftChild = currentElement->rightChild;
    }
    else
    {
        parentElement->rightChild = currentElement->rightChild;
    }
}

void parseRightNULL(TreeElement* currentElement, Tree* tree, bool isLeftChild, TreeElement* parentElement)
{
    if (currentElement == tree->root)
    {
        tree->root = currentElement->leftChild;
    }
    if (isLeftChild)
    {
        parentElement->leftChild = currentElement->leftChild;
    }
    else
    {
        parentElement->rightChild = currentElement->leftChild;
    }
}

void delete(TreeElement* currentElement, int value, Tree* tree, TreeElement* parentElement)
{
    if (value < currentElement->value)
    {
        delete(currentElement->leftChild, value, tree, currentElement);
    }
    else if (value > currentElement->value)
    {
        delete(currentElement->rightChild, value, tree, currentElement);
    }
    else if (value == currentElement->value)
    {
        bool isLeftChild = false;
        if (currentElement != tree->root)
        {
            isLeftChild = parentElement->value > currentElement->value;
        }

        if ((currentElement->leftChild == NULL) && (currentElement->rightChild == NULL))
        {
            parseLeaf(currentElement, tree, isLeftChild, parentElement);
        }
        else if (currentElement->leftChild == NULL)
        {
            parseLeftNULL(currentElement, tree, isLeftChild, parentElement);
        }
        else if (currentElement->rightChild == NULL)
        {
            parseRightNULL(currentElement, tree, isLeftChild, parentElement);
        }
        else //внутренняя вершина
        {
            int newValueForElement = findMaxInSubTree(currentElement->leftChild);
            delete(currentElement->leftChild, findMaxInSubTree(currentElement->leftChild), tree, currentElement);
            currentElement->value = newValueForElement;
        }
    }

    balance(currentElement, tree, parentElement);
    if (value == currentElement->value)
    {
        free(currentElement);
    }
}

Result deleteElement(Tree* tree, int value, bool* exists)
{
    if (tree == NULL)
    {
        return fail;
    }

    if (tree->root == NULL)
    {
        printf("Tree is already empty.\n");
        *exists = false;
        return success;
    }
    else
    {
        bool elementExists = false;
        findElement(tree, value, &elementExists);
        if (elementExists)
        {
            delete(tree->root, value, tree, NULL);
        }
        else
        {
            *exists = false;
            printf("There aren't such element.\n");
        }
    }

    return success;
}

void deleteAllElementsInTree(TreeElement* treeElement)
{
    if (treeElement->rightChild != NULL)
    {
        deleteAllElementsInTree(treeElement->rightChild);
    }
    if (treeElement->leftChild != NULL)
    {
        deleteAllElementsInTree(treeElement->leftChild);
    }
    free(treeElement);
}

Result deleteTree(Tree** tree)
{
    if (tree == NULL)
    {
        return fail;
    }

    if (!isTreeEmpty(*tree))
    {
        deleteAllElementsInTree((*tree)->root);
    }
    free(*tree);

    return success;
}