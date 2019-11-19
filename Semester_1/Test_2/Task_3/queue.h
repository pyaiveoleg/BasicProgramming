#ifndef REALISATION_OF_QUEUE_QUEUE_H
#define REALISATION_OF_QUEUE_QUEUE_H

#include <stdbool.h>
#include <stdio.h>
struct Queue;

typedef struct Queue Queue;

Queue* createQueue();
void push(int value, Queue* queue);
int size(Queue* queue);
bool isEmpty(Queue* queue);
int pop(Queue* queue);
void fprint(FILE *output, Queue* queue);

#endif
