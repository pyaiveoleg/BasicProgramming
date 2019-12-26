#include <stdio.h>

int main() {
    int quantityOfUsers = 0;
    int necessaryQuantityOfActions = 0;
    int timeForActions = 0;
    int numberOfActionsOfUser = 0;
    int timeOfCurrentAction = 0;
    int numberOfSuitableActions = 0;
    int numberOfSuitableUsers = 0;

    printf("Please, write down quantity of users, quantity of actions and time for these actions: ");
    scanf("%d %d %d", &quantityOfUsers, &necessaryQuantityOfActions, &timeForActions);

    for (int i = 0; i < quantityOfUsers; i++)
    {
        printf("Please, write down the number of actions of current user: ");
        scanf("%d", &numberOfActionsOfUser);
        printf("Please, write down the list of actions of current user: ");
        for (int j = 0; j < numberOfActionsOfUser; j++)
        {
            scanf("%d", &timeOfCurrentAction);
            if (timeOfCurrentAction <= timeForActions)
            {
                numberOfSuitableActions++;
            }
        }
        if (numberOfSuitableActions == necessaryQuantityOfActions)
        {
            numberOfSuitableUsers++;
        }
        numberOfSuitableActions = 0;
    }

    printf("This is a quantity of users that confirmed %d actions for the last %d minutes: %d", necessaryQuantityOfActions, timeForActions, numberOfSuitableUsers);
    return 0;
}