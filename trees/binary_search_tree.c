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

Node* findAux(Node *root, int key, Node **above)
{
    Node *actual = root;
    *above = NULL;

    while (actual != NULL)
    {
        if (actual->field == key) return actual;

        *above = actual;
        if (key < actual->field) actual = actual->left;
        else actual = actual->right;
    }

    return NULL; // Node not found
}

Node* greater_left(Node *actual, Node **above)
{
    *above = actual;
    actual = actual->left;
    while (actual->right) {
        *above = actual;
        actual = actual->right;
    }
    return(actual);    
}

int removeNode(Node **root, int key)
{
    Node *above_to_be_removed = NULL, 
    *to_be_removed = NULL, 
    *above_substitute = NULL, 
    *substitute = NULL;

    to_be_removed = findAux(*root, key, &above_to_be_removed);

    if (to_be_removed == NULL) return false;

    // It begins the pointers nightmare...


    if (!((to_be_removed->left != NULL) && (to_be_removed->right != NULL))) // When the to_be_removed node has one or none subnode
    {
        if (to_be_removed->left != NULL) substitute = to_be_removed->left;
        else substitute = to_be_removed->right; // It may be NULL too
        
        if (above_to_be_removed == NULL) *root = substitute; // When the to_be_removed is the root
        else
        { // It makes the node above the to_be_removed points to the subtitute node
            if (above_to_be_removed->left == to_be_removed) above_to_be_removed->left = substitute;
            else above_to_be_removed->right = substitute;
        }
        free(to_be_removed);
    } 

    else // When the to_be_removed node has one or none subnode
    { 
        substitute = greater_left(to_be_removed, &above_substitute);
        to_be_removed->field = substitute->field;
        if (above_substitute->left == substitute) above_substitute->left = substitute->left;
        else above_substitute->right = substitute->left;
        free(substitute);

        // Here, the substitute takes the place of to_be_removed and its previous addres is freed.
    }
    
    return true;
}

bool find(Node *root, int key)
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

void print_tree_pre_order(Node* root)
{
    // Order of print: root - left subtree - right subtree

    if (root == NULL) return;

    printf("%i ", root->field);
    print_tree_pre_order(root->left);
    print_tree_pre_order(root->right);
}

void print_tree_in_order(Node* root)
{
    // Order of print: left subtree - root - right subtree

    if (root == NULL) return;

    print_tree_in_order(root->left);
    printf("%i ", root->field);
    print_tree_in_order(root->right);
}

void print_tree_post_order(Node* root)
{
    // Order of print: left subtree - right subtree - root

    if (root == NULL) return;

    print_tree_post_order(root->left);
    print_tree_post_order(root->right);
    printf("%i ", root->field);
}

int main()
{
    Node* root = initialize();

    add(&root, 15);
    add(&root, 10);
    add(&root, 5);
    add(&root, 20);
    add(&root, 14);
    add(&root, 25);
    add(&root, 19);
    add(&root, 17);
    add(&root, 18);

    print_tree_pre_order(root);
    printf("\n");
    print_tree_in_order(root);
    printf("\n");
    print_tree_post_order(root);

    

    return 0;
}