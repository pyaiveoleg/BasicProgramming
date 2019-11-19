#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct QueueElement QueueElement;

struct QueueElement
{
    int value;
    QueueElement* nextElement;
};

struct Queue
{
    QueueElement* header;
    QueueElement* end;
    int size;
};

Queue* createQueue()
{
    Queue* queue = malloc(sizeof(Queue));
    queue->header = NULL;
    queue->end = NULL;
    queue->size = 0;
    return queue;
}

QueueElement* createQueueElement(int value)
{
    QueueElement* newElement = (QueueElement*) malloc(sizeof(struct QueueElement));
    newElement->value = value;
    newElement->nextElement = NULL;
}

void push(int value, Queue* queue)
{
    QueueElement* newElement = createQueueElement(value);
    if (queue->size == 0)
    {
        queue->header = newElement;
    }
    else
    {
        queue->end->nextElement = newElement;
    }
    queue->end = newElement;
    queue->size++;
}

int size(Queue* queue)
{
    return queue->size;
}

int pop(Queue* queue)
{
    if (isEmpty(queue))
    {
        return 0;
    }

    if (queue->size == 1)
    {
        queue->end = NULL;
    }

    QueueElement* poppedElement = queue->header;
    int value = poppedElement->value;
    queue->header = poppedElement->nextElement;
    free(poppedElement);
    queue->size--;
    return value;
}

bool isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

void print(Queue* queue)
{
    QueueElement* currentElement = queue->header;
    for (int i = 0; i < queue->size; i++)

    {
        printf("%d ", currentElement->value);
        currentElement = currentElement->nextElement;
    }
}