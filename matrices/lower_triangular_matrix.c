#include <stdio.h>
#include <stdlib.h>

int main() 
{

    int order = 5;

    int **matrix = (int**) malloc(sizeof(int*) * order);
    
    for (int i = 0, j = 1; i < order; i++, j++)
    {
        matrix[i] = (int*) malloc(sizeof(int) * j);
    }    
 
    for (int i = 0, j = 4; i < order; i++, j--)
    {
        for (int k = 0; k < (order - j); k++)
        {
            srand(rand());
            matrix[i][k] = rand() % 999;
        }
        
    }        

    for (int i = 0, j = 4; i < order; i++, j--)
    {
        for (int k = 0; k < (order - j); k++)
        {
            printf("%d\t", matrix[i][k]);
        }
        printf("\n");
    }  

    return 0;
}