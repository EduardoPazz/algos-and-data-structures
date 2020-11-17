typedef struct aux_queue {
    Node *node;
    struct aux_queue* next;
    struct aux_queue* prev;
} Element;

typedef struct {
    Element* HEAD;
    unsigned int length;
} Queue;


Queue* initialize_queue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));

    Element* HEAD = (Element*) malloc(sizeof(Element));

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

void in(Queue* queue, Node* node) {
    if (queue == NULL) return;

    Element* new_element = (Element*) malloc(sizeof(Element));
    
    new_element->node = node;

    fixPointers(queue->HEAD, new_element, queue->HEAD->next);

    (queue->length)++;
}

Node* out(Queue* queue) { 
    if (queue->length == 0) return NULL;

    Element* to_exit = queue->HEAD->prev;

    fixPointers(to_exit->prev->prev, to_exit->prev, queue->HEAD);

    Node* node = to_exit->node;

    free(to_exit);

    (queue->length)--;

    return node;
}

bool queue_is_empty(Queue* queue) {
    return queue->length == 0;
}

void reinitializeQueue(Queue* queue) {
    while (queue->length > 0) out(queue);
}