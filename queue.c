#include <stdio.h>
#include <malloc.h>

typedef struct {
    int num;
} Field;

typedef struct aux {
    Field field;
    int id;
    struct aux* next;
    struct aux* prev;
} Element;

typedef struct {
    Element* HEAD;
    unsigned int length;
    int idCounter;
} Queue;


Queue* initializeQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));

    Element* HEAD = (Element*) malloc(sizeof(Element));

    HEAD->id = -1;

    HEAD->prev = HEAD;
    HEAD->next = HEAD;

    queue->HEAD = HEAD;

    return queue;
}

void fixPointers(Element* prev, Element* actual, Element* next) {
    prev->next = actual;

    actual->prev = prev;
    actual->next = next;

    next->prev = actual;
}

int in(Queue* queue, int num) {
    Element* newElement = (Element*) malloc(sizeof(Element));
    
    newElement->field.num = num;
    newElement->id = ++(queue->idCounter);

    fixPointers(queue->HEAD, newElement, queue->HEAD->next);

    (queue->length)++;

    return newElement->id;
}

int out(Queue* queue) { 
    if (queue->length == 0) return -1;

    Element* toExit = queue->HEAD->prev;

    fixPointers(toExit->prev->prev, toExit->prev, queue->HEAD);

    int num = toExit->field.num;

    free(toExit);

    (queue->length)--;

    return num;
}

void reinitializeQueue(Queue* queue) {
    while (queue->length > 0) out(queue);
}

void printQueue(Queue* queue) {
    printf("\nPrinting Queue: [");
    for (
        Element* jumper = queue->HEAD->next;
        jumper->id != -1;
        jumper = jumper->next
    ) printf("\n Index: %d \t Field: %d \n", jumper->id, jumper->field.num);
    printf("]\n");
}

int main() {
    Queue* queue = initializeQueue();

    printQueue(queue);

    in(queue, 7);

    printQueue(queue);

    in(queue, 2);

    printQueue(queue);

    in(queue, 8);

    printQueue(queue);

    reinitializeQueue(queue);

    printQueue(queue);

    return 0;
}