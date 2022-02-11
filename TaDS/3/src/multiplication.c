#include "../include/multiplication.h"

// General standart matrix multiplication
int matrix_multiplication_std(std_matrix_t *matrix1, std_matrix_t *matrix2)
{
    // Check if two matrices are multipliable (row1 == col2)
    if (matrix1->col != matrix2->row)
    {
        printf("ERROR: Matrices cant be multiplied\n");
        return ERROR_CALC;
    }

    // Resulting matrix
    std_matrix_t *matrix_res;

    // Allocating resulting matrix if matrices are multipliable based
    // on their rows and columns parameters
    if (allocate_std_matrix(&matrix_res, matrix1->col, matrix2->row) != ERROR_NONE)
        return ERROR_MEMORY;

    // Setting all elements to 0
    reset_std_matrix(matrix_res);

    int summ = 0;

    // Matrix multiplication algorithm
    for (int i = 0; i < matrix1->row; i++)
    {
        for (int k = 0; k < matrix2->col; k++)
        {
            for (int j = 0; j < matrix2->row; j++)
                summ += matrix1->matrix[i][j] * matrix2->matrix[j][k];

            matrix_res->matrix[i][k] = summ;
            summ = 0;
        }
    }

    // Result output and freeing memory
    printf("STD MULTIPLICATION RESULT:\n");
    print_matrix(matrix_res);
    free_std_matrix(&matrix_res);
    return ERROR_NONE;
}

int matrix_multiplication_s(matrix_t *matrix1, matrix_t *matrix2)
{

    return ERROR_NONE;
}

// Function to measure the difference in time/memory
// Between standart and sparce matrices
int measure_difference()
{
    // Initialize 2 std matrices
    // Start timer
    // Multiplication algorithm
    // End timer

    // Same for sparse matrices

    return ERROR_NONE;
}

