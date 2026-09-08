#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const int table_width = 5;

int* matrix_input(int lines, int columns);
void print_matrix(int* matrix, int lines, int columns);
int* calculating_result_matrix(int** matrix_pointers, int lines, int columns, int number_matrixes);

int main(void)
{
    printf("How many matrixes do you wanna fold?: ");
    int number_matrixes = 0;
    scanf("%d", &number_matrixes);
    assert(number_matrixes >= 2);

    printf("Enter number of lines in each matrix: ");
    int lines = 0;
    scanf("%d", &lines);
    printf("Enter number of columns in each  matrix: ");
    int columns = 0;
    scanf("%d", &columns);

    int** matrix_pointers = (int**)calloc(number_matrixes, sizeof(int*));

    for (int i = 0; i < number_matrixes; i++)
    {
        printf("\nMatrix %d: \n", i + 1);
        matrix_pointers[i] = matrix_input(lines, columns); 
    }
    for (int i = 0; i < number_matrixes; i++)
    {
        printf("Matrix %d \n", i + 1);
        print_matrix(matrix_pointers[i], lines, columns);
    }

    printf("Result of folding all matrixes: \n");

    int* result_pointer = calculating_result_matrix(matrix_pointers, lines, columns, number_matrixes);
    print_matrix(result_pointer, lines, columns);
    free(result_pointer);

    for (int i = 0; i < number_matrixes; i++)
        free(matrix_pointers[i]);
    free(matrix_pointers);

}

int* matrix_input(int lines, int columns)
{
    int* matrix = (int*)calloc(lines * columns, sizeof(int));

    printf("Enter matrix coefficents: \n");
    for (int y = 0; y < lines; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            printf("[%d][%d]: ", y + 1, x + 1);
            scanf("%d", matrix + y * columns + x);
        }
    }
    return matrix;
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

int* calculating_result_matrix(int** matrix_pointers, int lines, int columns, int number_matrixes)
{
    int* matrix_result = (int*)calloc(lines * columns, sizeof(int));
    for (int i = 0; i < number_matrixes; i++)
    {
        for (int y = 0; y < lines; y++)
        {
            for (int x = 0; x < columns; x++)
            { 
                *(matrix_result + y * columns + x) += *(matrix_pointers[i] + y * columns + x);
            }
        }
    }
    return matrix_result;
}
