#include "../include/multiplication.h"
#include "../include/list.h"

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

    if (matrix_res->col < 500 && matrix_res->row < 500)
        print_matrix(matrix_res);
        
    free_std_matrix(&matrix_res);
    return ERROR_NONE;
}

// Multiplying two sparse matrices
int matrix_multiplication_s(matrix_t *matrix, vector_t *vector, vector_t **result)
{
    // Condition for matrix multiplication
    if (matrix->col != vector->row)
    {
        printf("ERROR: matrices cant be multiplied\n");
        return ERROR_CALC;
    }

    int curr_sum = 0;
    int IA_index = 1;

    int curr_IA;
    int prev_IA;
    
    // Amount of elements in non-zero row
    int row_nza;

    // First index of non-zero element in a row
    int first_nza_index;

    int result_nda_index_counter = 0;

    int JA_match = FALSE;
    int vector_index;
    int nza_index;

    int result_JA_counter = 0;

    while (value_by_index(&matrix->IA, IA_index) != FALSE)
    {

        curr_IA = value_by_index(&matrix->IA, IA_index);
        prev_IA = value_by_index(&matrix->IA, IA_index - 1);
        
        row_nza = curr_IA - prev_IA;
        first_nza_index = curr_IA - row_nza;

        nza_index = first_nza_index;

        // Going through all elements of non-zero row
        for (int k = nza_index; k < row_nza + first_nza_index; k++)
        {
            // Look if there are any non-zero multiplications
            // (only if JA values are matched)
            for (int i = 0; i < vector->nza; i++)
            {
                //printf("Comparing %d to %d\n", vector->JA[i], matrix->JA[k]);
                if (vector->JA[i] == matrix->JA[k])
                {
                    JA_match = TRUE;
                    vector_index = i;
                }
            }
            // There is a non-zero multiplication
            // So we add the result to sum
            if (JA_match == TRUE)
            {
                curr_sum += vector->A[vector_index] * matrix->A[k];
                //printf("Adding %d * %d to curr_summ\n", vector->A[vector_index], matrix->A[k]);
                JA_match = FALSE;
            }
        }

        // result vector will have the same amount of rows as vector we use for multiplication
        if (curr_sum > 0)
        {
            //printf("Writing %d to vector\n", curr_sum);
            (*result)->A[result_nda_index_counter] = curr_sum;
            (*result)->JA[result_nda_index_counter] = result_JA_counter; 

            result_nda_index_counter++;
            result_JA_counter++;
            curr_sum = 0;
        }
        else
            result_JA_counter++;

        IA_index++;
    }

    correct_vector(result);
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

