#include <stdio.h>
#include <stdlib.h>

#include "CycleList.h"

int main() 
{
    int quantityOfWarriors = 0;
    int distanceForKilling = 0;
    CycleList* listOfWarriors = createList();

    printf("Please, write down quantity of warriors (N) and distance between killing warrriors (M):\n");
    scanf("%d %d", &quantityOfWarriors, &distanceForKilling);

    for (int i = 1; i <= quantityOfWarriors; i++)
    {
        addItem(listOfWarriors, i);
    }

    while (quantityOfWarriors > 1)
    {
        for (int i = 0; i < distanceForKilling; i++)
        {
            goNext(listOfWarriors);
        }
        deleteCurrentElement(listOfWarriors);
        quantityOfWarriors--;
    }

    int numberOfLastWarrior = 0;
    getValueOfCurrentElement(listOfWarriors, &numberOfLastWarrior);
    printf("This is the number of last warrior:\n%d", numberOfLastWarrior);

    free(listOfWarriors);
    return 0;
}
