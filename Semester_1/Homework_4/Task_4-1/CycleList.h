//
// Created by Олег on 07.10.2019.
//

#ifndef INC_4_1_CYCLELIST_H
#define INC_4_1_CYCLELIST_H

#include <stdbool.h>
//struct CycleList;
struct ListElement;
//typedef struct CycleList CycleList;
typedef struct ListElement ListElement;

bool isEmpty(ListElement *listElement);
ListElement* createList(int value);
ListElement* addItem(ListElement* listElement, int value);
ListElement* goNext(ListElement* listElement);
ListElement* deleteNextElement(ListElement* listElement);
int getValue(ListElement* listElement);
void printElement(ListElement* listElement);

#endif //INC_4_1_CYCLELIST_H
