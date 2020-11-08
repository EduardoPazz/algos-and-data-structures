#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef int INDEX;

typedef struct{
  INDEX index;
  int num;
  // other fields
} CELL; // A cell is a point in memory that holds some information. Also called "register".

typedef struct {
  CELL cell[MAX-1]; // Here we create a array of maximum 50 items.
  int length;
} QUEUE;

QUEUE* initialize() {
	QUEUE* queue = (QUEUE*) malloc(sizeof(QUEUE));
	queue->length = 0;
    return queue;
}

int getLength(QUEUE* queue) {
	return queue->length;
}

void insert(QUEUE* queue, INDEX index, int num) {
    int length = getLength(queue);
    if (queue == NULL || length == MAX || index < 0 || index > length) { 
        printf("Insertion failed. \n");
    }  else

    for (int i = length; i > index; i--) {
        queue->cell[i].num = queue->cell[i-1].num;
    }

    queue->cell[index].num = num;
    queue->cell[index].index = index;

    queue->length++;
}

void printQueue(QUEUE* queue) {
	int maxIterations = queue->length;

	for (int i = 0; i < maxIterations; i++) {
		printf("Cell[%d]: \t %d \n", i, queue->cell[i].num);
	}
    printf("\n");
}

void exclude(QUEUE* queue, INDEX index) { 
    int length = getLength(queue);
    if (queue == NULL || index < 0 || index >= length) { 
        printf("Exclusion failed. \n");
    }  else

    for (int i = index; i < length; i++) {
        queue->cell[i].num = queue->cell[i+1].num;
    }

    queue->length--;
}

INDEX find(QUEUE* queue, INDEX key) {
    for (int i = 0; i < getLength(queue); i++) {
       if (queue->cell[i].index == key) {
          printf("Element found on index %d \n", i); 
          return i;
       } 
    }
    return -1;
}

void main() {
	QUEUE* queue = initialize();

	insert(queue, 0, 3);
	insert(queue, 1, 5);
	insert(queue, 2, 7);

	printf("Your queue has %d items storaged.\n", getLength(queue));

	printQueue(queue);
	
    insert(queue, 1, 2);

	printQueue(queue);

    exclude(queue, 1);
	printQueue(queue);

    //   find(queue, 2);
}
