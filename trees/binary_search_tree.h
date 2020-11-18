#include "common-header.h"

typedef struct aux_node 
{
    int field;
    struct aux_node *left, *right;
} Node;