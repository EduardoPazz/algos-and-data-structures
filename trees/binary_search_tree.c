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

bool find(Node* root, int key)
{
    bool found = false;

    if (root == NULL) return found;

    if (root->left != NULL && key < root->field) found = find(root->left, key);
    if (root->right != NULL && key > root->field) found = find(root->right, key);
    else if (key == root->field) found = true;

    return found;
}

int count(Node* root)
{
    if (root != NULL) return (
        1 + 
        count(root->left) + 
        count(root->right)
    );
    
    return 0;
}

void print_tree(Node* root)
{
    // Order of print: left subtree / root / right subtree

    if (root->left != NULL) print_tree(root->left);
    printf("%i ", root->field);
    if (root->right != NULL) print_tree(root->right);
}

int main()
{
    Node* root = initialize();

    add(&root, 15);
    add(&root, 14);
    add(&root, 16);

    print_tree(root);

    printf("\n%i", find(root, 16));
    printf("\n%i", find(root, 17));

    printf("There is %i\n", count(root));

    add(&root, 20);

    printf("There is %i\n", count(root));

    return 0;
}