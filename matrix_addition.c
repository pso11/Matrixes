#include <stdio.h>
#include <stdlib.h>

void print_matrix(int* matrix);
int* addition_2_matrix(int* matrix1, int* matrix2);

const int lines = 5, columns = 4;

int main(void)
{
    int matrix1[lines][columns] =
    {
        {0, 2, 3, 4},
        {11, 12, 13, 14}, 
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44}
    };
    int matrix2[lines][columns] =
    {
        {2, 3, 4, 5},
        {12, 13, 14, 15}, 
        {22, 23, 24, 25},
        {32, 33, 34, 35},
        {42, 43, 44,45}
    };

    printf("Matrix 1\n\n");
    print_matrix((int*)matrix1);

    printf("Matrix 2\n\n");
    print_matrix((int*)matrix2);

    printf("Result of folding to matrixes:\n\n");
    print_matrix( addition_2_matrix((int*)matrix1, (int*)matrix2) );

    return 0;
}

void print_matrix(int* matrix)
{
    for (int y = 0; y < lines; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            printf("%5d ", *(matrix + y * columns + x));
        }
        printf("\n");
    }
    printf("\n");
}

int* addition_2_matrix(int* matrix1, int* matrix2)
{
    static int matrix_result[lines][columns] = {};
    for (int y = 0; y < lines; y++)
    {
        for (int x = 0; x < columns; x++)
        { 
            matrix_result[y][x] = *(matrix1 + y * columns + x) + *(matrix2 + y * columns + x);
        }
    }
    return (int*)matrix_result;
}
