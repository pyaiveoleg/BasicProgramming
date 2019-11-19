#ifndef REALISATION_OF_QUEUE_QUEUE_H
#define REALISATION_OF_QUEUE_QUEUE_H

#include <stdbool.h>
struct Queue;

typedef struct Queue Queue;

Queue* createQueue();
void push(int value, Queue* queue);
int size(Queue* queue);
bool isEmpty(Queue* queue);
int pop(Queue* queue);
void print(Queue* queue);

#endif
