#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct QueueElement
{
    int value;
    char charValue;
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

void push(QueueElement* newElement, Queue* queue)
{
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

void pushToQueue(int value, Queue* queue)
{
    QueueElement* newElement = createQueueElement(value);
    push(newElement, queue);
}

void pushCharToQueue(char charValue, Queue* queue)
{
    QueueElement* newElement = createQueueElement(0);
    newElement->charValue = charValue;
    push(newElement, queue);
}

int size(Queue* queue)
{
    return queue->size;
}

int pop(Queue* queue)
{
    if (isQueueEmpty(queue))
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

bool isQueueEmpty(Queue* queue)
{
    return (queue->size == 0);
}

void printQueue(Queue* queue, int maxNumber)
{
    QueueElement* currentElement = queue->header;
    printf("%d ",  currentElement->value);
    while(currentElement->nextElement != NULL)
    {
        currentElement = currentElement->nextElement;
        if (currentElement->value > maxNumber)
        {
            printf("%c ", (char) (currentElement->value - maxNumber));
        }
        else
        {
            printf("%d ", currentElement->value);
        }
    }
}

char endValue(Queue* queue)
{
    return queue->end->value;
}