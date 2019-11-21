#ifndef INC_4_1_CYCLELIST_H
#define INC_4_1_CYCLELIST_H

#include <stdbool.h>
struct CycleList;
typedef struct CycleList CycleList;

bool isEmpty(CycleList* list);
CycleList* createList();
void addItem(CycleList* list, int value);
void goNext(CycleList* list);
void deleteCurrentElement(CycleList* list);
int getValueOfCurrentElement(CycleList* list);
void printCurrentElement(CycleList* list);

#endif //INC_4_1_CYCLELIST_H
