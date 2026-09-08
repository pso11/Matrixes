#include <stdio.h>
#include <stdlib.h>

void print_matrix(int* matrix, int lines, int columns);
int* multiplication_2_matrix(int* matrix1, int* matrix2);

const int lines_1 = 5, columns_1 = 5, lines_2 = 5, columns_2 = 5, table_width = 5;

int main(void)
{
     if (columns_1 != lines_2)
    {
        printf("Error!!!! Wrong data");
        exit(EXIT_SUCCESS);
    }

    int matrix1[lines_1][columns_1] =
    {
        {1, 2, 3, 4, 5},
        {11, 12, 13, 14, 15}, 
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35},
        {41, 42, 43, 44, 45}
    };
    int matrix2[lines_2][columns_2] =
    {
        {2, 3, 4, 5, 6},
        {12, 13, 14, 15, 16}, 
        {22, 23, 24, 25, 25},
        {32, 33, 34, 35, 36},
        {42, 43, 44, 45, 46}
    };

    printf("Matrix 1\n\n");
    print_matrix((int*)matrix1, lines_1, columns_1);

    printf("Matrix 2\n\n");
    print_matrix((int*)matrix2, lines_2, columns_2);

    printf("Result of folding to matrixes:\n\n");
    print_matrix( multiplication_2_matrix((int*)matrix1, (int*)matrix2), lines_1, columns_2);
    return 0;
}

void print_matrix(int* matrix, int lines, int columns)
{
    for (int y = 0; y < lines; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            printf("%*d ", table_width, *(matrix + y * columns + x));
        }
        printf("\n");
    }
    printf("\n");
}

int* multiplication_2_matrix(int* matrix1, int* matrix2)
{
    static int matrix_result[lines_1][columns_2] = {};
    for (int y = 0; y < lines_1; y++)
    {
        for (int x = 0; x < columns_2; x++)
        { 
            for (int k = 0; k < columns_1; k++)
            {
                matrix_result[y][x] += (*(matrix1 + y * columns_1 + k) * *(matrix2 + k * columns_2 + x));
            }
        }
    }
    return (int*)matrix_result;
}

