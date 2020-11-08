#include <stdio.h>
#include <malloc.h>

int main() 
{

    int **matrix = (int**) malloc(sizeof(int*) * 2);
    
    for (int i = 0; i < 2; i++)
    {
        matrix[i] = (int*) malloc(sizeof(int) * 2);
    }    

    matrix[0][0] = 46587;
    matrix[0][1] = 4587;
    matrix[1][0] = 5874;
    matrix[1][1] = 483;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("%p\n", matrix);
    printf("%p\n", &matrix);
    printf("%p\n", &matrix[0][0]);

    return 0;
}