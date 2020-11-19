#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

typedef enum { left, right } Side;

typedef struct aux 
{
    int field;
    struct aux *left, *right;
} Node;

Node* find_node(int field, Node *root) 
{
    if (root == NULL) return NULL;

    if (root->field == field) return root;

    Node *aux = find_node(field, root->left);
    if (aux != NULL) return aux;
    return find_node(field, root->right); // Whether it is a valid address or it is a NULL addres
}

Node* create_new_node(int field)
{
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->field = field;
    return new_node;
}

Node *create_root(int field) { return create_new_node(field); }

bool insert_node(Node *root, int new_field, int super_field, Side side)
{
    Node *super_node = find_node(super_field, root);
    if (super_node == NULL) return false;

    Node *new_node = create_new_node(new_field);

    if (side == left) {
        new_node->left = super_node->left;
        super_node->left = new_node;
    } else {
        new_node->left = super_node->right;
        super_node->right = new_node;
    }
}

int main()
{
    Node *root = create_root(40);

    return 0;
}