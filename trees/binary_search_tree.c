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

Node* initialize() { return NULL; }

void add(Node **root, int field) // Here, as I'm using a void function, we need to use the pointer of the pointer of the root node, so it may be confuse the uses of *'s and ()'s.
{
    if (*root == NULL) // Initialize the nodes
    { 
        *root = (Node*) malloc(sizeof(Node));
        (*root)->field = field;
        (*root)->left = NULL;
        (*root)->right = NULL;

        return;
    }

    if (field < (*root)->field) add(&((*root)->left), field);
    else if (field > (*root)->field) add(&((*root)->right), field);
    // If the field is the same, nothing happens
}

void print_tree(Node* root)
{
    if (root->left != NULL) print_tree(root->left);
    if (root->right != NULL) print_tree(root->right);
    printf("%i ", root->field);
}

int main()
{
    Node* root = initialize();

    add(&root, 15);
    add(&root, 14);
    add(&root, 16);

    print_tree(root);

    return 0;
}