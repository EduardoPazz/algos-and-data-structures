#include <stdio.h>
#include <stdlib.h>

typedef struct aux {
    int field;
    struct aux* prev;
} Floor;

typedef struct {
    Floor* top;
    char height;
} Stack;

Stack* initialize() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->height = 0;
    return stack;
}

void push(Stack* stack , int value) {
    Floor* floor = (Floor*) malloc(sizeof(Floor));
    floor->field = value;
    
    if (stack->height != 0)  floor->prev = stack->top;
    stack->top = floor;
    stack->height++;
}

int pop(Stack* stack) {
    Floor* top = stack->top; 

    if (top == NULL) return -1;

    int value = top->field;

    printf("\n Removing %d from top. \n", value);
    stack->top = top->prev;
    free(top);
    stack->height--;

    return value;
}

void printStack(Stack* stack) {
    printf("Stack: \n");

    Floor* floorAux = stack->top;
    while (floorAux != NULL) {
        printf("\t %d \n", floorAux->field);
        floorAux = floorAux->prev;
    }
    
    printf("\n");
}

void main() {
    Stack* stack = initialize();
    //printf("Height: %d", stack->height);
    //printf("Top's adress: %p", stack->top);

    push(stack, 7);
    push(stack, 4);
    push(stack, 8);
    push(stack, 11);
    push(stack, 35);

    printStack(stack);

    pop(stack);
    pop(stack);

    printStack(stack);
}