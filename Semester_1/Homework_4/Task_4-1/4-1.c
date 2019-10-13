#include <stdio.h>
#include "CycleList.h"

int main() {
    int quantityOfWarriors = 0;
    int distanceForKilling = 0;
    ListElement* listOfWarriors;
    listOfWarriors = createList(1);

    printf("Please, write down quantity of warriors (N) and distance between killing warrriors (M):\n");
    scanf("%d %d", &quantityOfWarriors, &distanceForKilling);

    for (int i = 2; i <= quantityOfWarriors; i++)
    {
        listOfWarriors = addItem(listOfWarriors, i);
    }

    while (quantityOfWarriors != 1)
    {
        for (int i = 1; i < distanceForKilling; i++)
        {
            listOfWarriors = goNext(listOfWarriors);
        }
        listOfWarriors = deleteNextElement(listOfWarriors);
        quantityOfWarriors--;
    }

    printf("This is the number of last warrior:\n%d", getValue(listOfWarriors));

    return 0;
}