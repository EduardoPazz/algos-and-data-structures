typedef struct aux_floor {
    Node *address;
    struct aux_floor *prev;
} Floor;

typedef struct {
    Floor* top;
    char height;
} Stack;

Stack* initialize_stack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->height = 0;
    return stack;
}

void push(Stack* stack , Node *address) {
    Floor* floor = (Floor*) malloc(sizeof(Floor));
    floor->address = address;
    
    if (stack->height != 0)  floor->prev = stack->top;
    stack->top = floor;
    stack->height++;
}

Node* pop(Stack* stack) {
    Floor* top = stack->top; 

    if (top == NULL) return NULL;

    Node *address = top->address;

    stack->top = top->prev;
    free(top);
    (stack->height)--;

    return address;
}

bool stack_is_empty(Stack *stack) {
    return stack->height == 0;
}

/* void printStack(Stack* stack) {
    printf("Stack: \n");

    Floor* floorAux = stack->top;
    while (floorAux != NULL) {
        printf("\t %d \n", floorAux->address);
        floorAux = floorAux->prev;
    }
    
    printf("\n");
} */