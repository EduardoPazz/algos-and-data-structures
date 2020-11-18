#include "common-header.h"

typedef struct aux_n_nary_tree
{
    int field;
    struct aux_n_nary_tree* child_node;
    struct aux_n_nary_tree* right_node;
} Node;