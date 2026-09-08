#include <stdio.h>
#include <stdlib.h>

void print_matrix(int* matrix, int lines, int columns);
int* addition_2_matrix(int* matrix1, int* matrix2);

const int lines_1 = 5, columns_1 = 4, lines_2 = 5, columns_2 = 4, table_width = 5;

int main(void)
{
    if (lines_1 != lines_2 && columns_1 != columns_2)
    {
        printf("You entered wrong data");
        exit(EXIT_SUCCESS);
    }

    int matrix1[lines_1][columns_1] =
    {
        {0, 2, 3, 4},
        {11, 12, 13, 14}, 
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44}
    };
    int matrix2[lines_2][columns_2] =
    {
        {2, 3, 4, 5},
        {12, 13, 14, 15}, 
        {22, 23, 24, 25},
        {32, 33, 34, 35},
        {42, 43, 44,45}
    };

    printf("Matrix 1\n\n");
    print_matrix((int*)matrix1, lines_1, columns_1);

    printf("Matrix 2\n\n");
    print_matrix((int*)matrix2, lines_2, columns_2);

    printf("Result of folding to matrixes:\n\n");
    print_matrix( addition_2_matrix((int*)matrix1, (int*)matrix2), lines_1, columns_1 );

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

int* addition_2_matrix(int* matrix1, int* matrix2)
{
    static int matrix_result[lines_1][columns_1] = {};
    for (int y = 0; y < lines_1; y++)
    {
        for (int x = 0; x < columns_1; x++)
        { 
            matrix_result[y][x] = *(matrix1 + y * columns_1 + x) + *(matrix2 + y * columns_1 + x);
        }
    }
    return (int*)matrix_result;
}
