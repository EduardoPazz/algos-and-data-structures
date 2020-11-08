#include <stdio.h>
#include <stdlib.h>

int* alloc(int n) {
	return (int*) malloc(sizeof(int) * n);
}

void insertRand(int* arr, int size) {
	int* auxPointer = arr;

	for(int i = 0; i < size; i++) {
		*auxPointer = rand();
		auxPointer++;
	}
}

void print(int* arr, int size) {
	int* auxPointer = arr;

	for(int i = 0; i < size; i++) {
		printf("arr[%i] = %i \n", i, *auxPointer);
		auxPointer++;
	}
}

void main() {
	int size = 3;
	int* arr = alloc(size);
	insertRand(arr, size);
	print(arr, size);

	free(arr);
}
