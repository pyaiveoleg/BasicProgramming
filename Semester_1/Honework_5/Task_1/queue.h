#ifndef REALISATION_OF_QUEUE_QUEUE_H
#define REALISATION_OF_QUEUE_QUEUE_H

#include <stdbool.h>
struct Queue;
struct QueueElement;
typedef struct Queue Queue;
typedef struct QueueElement QueueElement;

Queue* createQueue();
void pushToQueue(int value, Queue* queue);
void pushCharToQueue(char charValue, Queue* queue);
int size(Queue* queue);
bool isQueueEmpty(Queue* queue);
int pop(Queue* queue);
void printQueue(Queue* queue, int maxNumber);
char endValue(Queue* queue);

#endif
