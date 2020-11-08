/*  TODO
    [X] Inicializar a estrutura
    [X] Exibir elementos
    [X] Inserir elementos
    [X] Excluir elementos
    [ ] Reinicializar estrutura
*/

#include <stdio.h>
#include <malloc.h>

#define back 0
#define front 1
#define true 1
#define false 0

typedef char bool;
typedef char POSITION;

typedef struct aux {
    int field;
    struct aux* p2Prev; // "Pointer to"
    struct aux* p2Next;
} Element;

typedef struct {
    Element* HEAD;
    unsigned char size;
} Deck;

Deck* initialize() {
    Deck* deck = (Deck*) malloc(sizeof(Deck));

    deck->HEAD = (Element*) malloc(sizeof(Element));
    deck->HEAD->p2Prev = deck->HEAD;
    deck->HEAD->p2Next = deck->HEAD;
    deck->HEAD->field = -1;

    return deck;
}

void printDeck(Deck* deck) {
    Element* jumper = deck->HEAD->p2Next;

    printf("Printing Deck:");
    while (jumper != deck->HEAD) {
        printf(" %i", jumper->field);
        jumper = jumper->p2Next;
    }
    printf(" .\n");
}

void insert(Deck* deck, int newField, POSITION position) {

    Element* newElement = (Element*) malloc(sizeof(Element));
    newElement->field = newField;

    switch (position) {

        case back:
            newElement->p2Next = deck->HEAD->p2Next; // It makes the new first points to old first
            newElement->p2Prev = deck->HEAD;
            newElement->p2Next->p2Prev = newElement; // It makes the old first points to new first
            deck->HEAD->p2Next = newElement;
        break;

        case front:
            newElement->p2Next = deck->HEAD;
            newElement->p2Prev = deck->HEAD->p2Prev; // It makes the new last points to old last
            newElement->p2Prev->p2Next = newElement; // It makes the old last points to new last
            deck->HEAD->p2Prev = newElement;
    }

    deck->size++;
}

bool exclude(Deck* deck, POSITION position) {

    if (deck->HEAD->p2Next = deck->HEAD) {
        return false;
    }

    Element* toBeRemoved = NULL;

    switch (position) {

        case back:
            toBeRemoved = deck->HEAD->p2Next;
            toBeRemoved->p2Next->p2Prev = deck->HEAD; // It makes the old second (i.e., the new first) points to HEAD
            deck->HEAD->p2Next = toBeRemoved->p2Next; // It makes the HEAD points to the new first
        break;

        case front:
            toBeRemoved = deck->HEAD->p2Prev;
            toBeRemoved->p2Prev->p2Next = deck->HEAD; // It makes the old penult (i.e., the new last) points to HEAD
            deck->HEAD->p2Prev = toBeRemoved->p2Prev; // It makes the HEAD points to the new last
    }

    free(toBeRemoved);
    deck->size++;
    return true;
}

int main() {

    Deck* deck = initialize();

    exclude(deck, back);

    insert(deck, 4, front);
    insert(deck, 7, front);

    printDeck(deck);

    printDeck(deck);

    printDeck(deck);
    return 0;
}
