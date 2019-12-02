#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "CycleList.h"

typedef struct ListElement ListElement;

struct ListElement
{
    int value;
    ListElement* next;
    ListElement* previous;
};

struct CycleList
{
    ListElement* current;
};

CycleList* createList()
{
    CycleList* newList = (CycleList*) malloc(sizeof(CycleList));
    newList->current = NULL;
    return newList;
}

bool isEmpty(CycleList* list)
{
    return list->current == NULL;
}

void addItem(CycleList* list, int value)
{
    ListElement* addedItem = (ListElement*) malloc(sizeof(ListElement));
    addedItem->value = value;

    if (isEmpty(list))
    {
        list->current = addedItem;
        list->current->next = list->current;
        list->current->previous = list->current;
        return;
    }

    ListElement* previousRoot = list->current;
    ListElement* temporary = previousRoot->next;
    list->current = addedItem;
    previousRoot->next = addedItem;
    addedItem->previous = previousRoot;
    addedItem->next = temporary;
    temporary->previous = addedItem;
}

Result goNext(CycleList* list)
{
    if (isEmpty(list))
    {
        return  fail;
    }
    list->current = list->current->next;
    return success;
}

Result deleteCurrentElement(CycleList* list)
{
    if (isEmpty(list))
    {
        return fail;
    }

    ListElement* previousElement = list->current->previous;
    ListElement* nextElement = list->current->next;
    ListElement* deletedElement = list->current;

    list->current = previousElement;
    nextElement->previous = previousElement;
    previousElement->next = nextElement;

    free(deletedElement);
    return success;
}

Result getValueOfCurrentElement(CycleList* list, int* value)
{
    if (isEmpty(list))
    {
        return fail;
    }
    *value = list->current->value;
    return  success;
}

Result printCurrentElement(CycleList* list)
{
    if (isEmpty(list))
    {
        return fail;
    }
    printf("%d", list->current->value);
    return success;
}