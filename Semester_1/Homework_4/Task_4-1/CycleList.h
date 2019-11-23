#pragma once

#include <stdbool.h>
struct CycleList;
typedef struct CycleList CycleList;

typedef enum Result
{
    kResult_Ok,
    kResult_Fail,
} Result;

CycleList* createList();

void addItem(CycleList* list, int value);
Result goNext(CycleList* list);
Result deleteCurrentElement(CycleList* list);
Result getValueOfCurrentElement(CycleList* list, int* value);
Result printCurrentElement(CycleList* list);
