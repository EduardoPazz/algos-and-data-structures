#include "../common-header.h"

typedef struct aux_avl 
{
    int field;
    struct aux_alv* left_child;
    struct aux_alv* right_child;
    unsigned int height;
} AVL;