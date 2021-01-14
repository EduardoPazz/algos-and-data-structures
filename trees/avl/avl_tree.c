#include "./avl_tree.h"

AVL* create_avl_node(int field) {
    AVL* root = (AVL*) malloc(sizeof(AVL));

    root->field = field;
    root->left_child = NULL;
    root->right_child = NULL;
    root->height = 0;

    return root;
}

AVL* initialize_avl_tree(int field) 
{
    return create_alv_node(field);
}

/* 
    Função que checa o balanceamento: recebe o endereço de um nó

    Calcula a altura dos seus filhos à esquerda e direita.
    Subtrai a direita pela esquerda

    retorna a diferença
*/

/* 
    Função de Checar Integridade: endereço de um nó

    Deve começa a partir da raiz;

    balanceamento = Função que checa o balanceamento

    if (balanceamento < 0) { // Pela esquerda
        if (balanceamento < -1) {
            Função rotação a esquerda
        } else {
            Função de Checar Integridade(filho à esquerda)
        }
    } else if (balanceamento > 0) { // Pela direita
        if (balanceamento > 1) {
            Função rotação à direita
        } else {
            Função de Checar Integridade(filho à direita)
        }
    }

*/


void insert_avl_node(AVL **root, int field) // Here, as I'm using a void function, we need to use the pointer of the pointer of the root node, so it may be confuse the uses of *'s and ()'s.
{
    if (*root == NULL) {
        *root = create_alv_node(field);
        // Checa a integridade da árvore
    }
    else
    {
        if (field < (*root)->field) insert_avl_node(&((*root)->left_child), field);
        else if (field > (*root)->field) insert_avl_node(&((*root)->right_child), field);

        // If the field is the same, nothing happens
    }
}