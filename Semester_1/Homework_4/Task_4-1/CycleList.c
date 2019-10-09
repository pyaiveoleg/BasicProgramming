//
// Created by Олег on 07.10.2019.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "CycleList.h"


struct ListElement
{
    int value;
    ListElement* next;
};

ListElement* createList(int value)
{
    ListElement* newList = (ListElement*) malloc(sizeof(ListElement));
    newList->next = newList;
    newList->value = value;
    return newList;
}

bool isEmpty(ListElement *listElement)
{
    return listElement->next == listElement;
}

ListElement* addItem(ListElement* listElement, int value)
{
    ListElement* temporary = listElement->next;
    ListElement* addedItem = (ListElement*) malloc(sizeof(ListElement));
    listElement->next = addedItem;
    addedItem->next = temporary;
    addedItem->value = value;
    return addedItem;
}

ListElement* goNext(ListElement* listElement)
{
    return listElement->next;
}

ListElement* deleteNextElement(ListElement* listElement)
{
    ListElement* nextElement = listElement->next;
    listElement->next = nextElement->next;
    free(nextElement);
    return(listElement);
}

int getValue(ListElement* listElement)
{
    return listElement->value;
}

void printElement(ListElement* listElement)
{
    printf("%d", listElement->value);
}