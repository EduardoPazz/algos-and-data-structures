#include "./n-nary-tree.h"

Node* create_new_node(int field)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->field = field;
    node->child_node = NULL;
    node->right_node = NULL;

    return node;
}

Node* initialize_n_nary_tree(int field) 
{
    return create_new_node(field);
}


Node* search_field(Node* root, int field) {
    if (root == NULL) return NULL;
    if (root->field == field) return root;
    Node* jumper = root->child_node;
    while (jumper != NULL) 
    {
        Node* returnedAddres = search_field(jumper, field);
        if (returnedAddres != NULL) return returnedAddres;
        jumper = jumper->right_node;
    }
    return NULL;
}

bool insert_node(Node* root, int parent_field, int new_field)
{
    Node* parent_node = search_field(root, parent_field);

    if (parent_node == NULL) return false;

    Node* child_node = create_new_node(new_field);

    Node* jumper_node = parent_node->child_node;

    if (jumper_node != NULL) 
    {
        while (jumper_node->right_node != NULL) jumper_node = jumper_node->right_node;
        jumper_node->right_node = child_node;
    }
    else parent_node->child_node = child_node; // Here, the parent_node doesn't have any child before

    return true;
}

void print_tree(Node* root)
{   
    if (root == NULL) return;
    printf("%d ", root->field);
    Node* jumper = root->child_node;
    while (jumper != NULL)
    {
        print_tree(jumper);
        jumper = jumper->right_node;
    }
}

int main(int argc, char const *argv[])
{
    Node* n_nary_tree = initialize_n_nary_tree(8);
    insert_node(n_nary_tree, 8, 15);
    insert_node(n_nary_tree, 8, 23);
    insert_node(n_nary_tree, 8, 2);
    insert_node(n_nary_tree, 15, 20);
    insert_node(n_nary_tree, 15, 10);
    insert_node(n_nary_tree, 15, 28);
    insert_node(n_nary_tree, 2, 36);
    insert_node(n_nary_tree, 2, 7);
    print_tree(n_nary_tree);

    return 0;
}
