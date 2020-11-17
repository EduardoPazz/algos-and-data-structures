#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

#include "binary_search_tree.h"
#include "aux_stack.c"
#include "aux_queue.c"

Node* initialize() { return NULL; }

void add(Node **root, int field) // Here, as I'm using a void function, we need to use the pointer of the pointer of the root node, so it may be confuse the uses of *'s and ()'s.
{
    if (*root == NULL) // Initialize the node
    { 
        *root = (Node*) malloc(sizeof(Node));
        (*root)->field = field;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else
    {
        if (field < (*root)->field) add(&((*root)->left), field);
        else if (field > (*root)->field) add(&((*root)->right), field);

        // If the field is the same, nothing happens
    }
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

    else // When the to_be_removed node has two subnodes
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

void print_tree_pre_order_non_recursive(Node *root)
{
    if (root == NULL) return;

    Stack *node_stack = initialize_stack();

    push(node_stack, root);

    for (Node *actual_node; !stack_is_empty(node_stack); printf("%i ", actual_node->field))
    {
        actual_node = pop(node_stack);

        if (actual_node->right != NULL) push(node_stack, actual_node->right); // We are pushing the right subtree first for the left subtree to be the first to be called in the next iteration
        if (actual_node->left != NULL) push(node_stack, actual_node->left);
    }
    
}

void print_tree_per_level_non_recursive(Node *root)
{
    if (root == NULL) return;

    Queue *node_queue = initialize_queue();

    in(node_queue, root);

    for (Node *actual_node; !queue_is_empty(node_queue); printf("%i ", actual_node->field))
    {
        actual_node = out(node_queue);

        if (actual_node->left != NULL) in(node_queue, actual_node->left);
        if (actual_node->right != NULL) in(node_queue, actual_node->right);
    }
}

int main()
{
    Node* root = initialize();

    add(&root, 40);
    add(&root, 30);
    add(&root, 35);
    add(&root, 70);
    add(&root, 45);
    add(&root, 85);

    print_tree_per_level_non_recursive(root);
    printf("\n");

    return 0;
}