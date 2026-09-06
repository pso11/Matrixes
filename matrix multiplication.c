#include <stdio.h>
#include <stdlib.h>

void print_matrix(int* matrix);
void multiplication_2_matrix(int* matrix1, int* matrix2);

const int lines = 5, columns = 4;

int main(void)
{
    int matrix1[5][4] =
    {
        {1, 2, 3, 4},
        {11, 12, 13, 14}, 
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44}
    };
    int matrix2[4][5] =
    {
        {2, 3, 4, 5, 6},
        {12, 13, 14, 15. 16}, 
        {22, 23, 24, 25, 25},
        {32, 33, 34, 35, 36}
    };

    printf("Matrix 1\n\n");
    print_matrix((int*)matrix1, lines, columns);

    printf("Matrix 2\n\n");
    print_matrix((int*)matrix2, lines, columns);

    printf("Result of folding to matrixes:\n\n");
    multiplication_2_matrix((int*)matrix1, (int*)matrix2, lines, columns);
    return 0;
}

void print_matrix(int* matrix, int lines, int columns)
{
    for (int y = 0; y < lines; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            for (int sum = 0, i = 0; i < 5; i++)
            {
                
            }
            printf("%5d ", *(matrix + y * columns + x));
        }
        printf("\n");
    }
    printf("\n");
}

void multiplication_2_matrix(int* matrix1, int* matrix2, int lines, int columns)
{
    int matrix_result[5][5] = {};
    for (int y = 0; y < lines; y++)
    {
        for (int x = 0; x < columns; x++)
        { 
            matrix_result[y][x] = *(matrix1 + y * columns + x) + *(matrix2 + y * columns + x);
        }
    }

    for (int y = 0; y < lines; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            printf("%5d ", *((int*)matrix_result + y * columns + x));
        }
        printf("\n");
    }
}

