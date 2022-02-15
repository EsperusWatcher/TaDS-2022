#include "../include/efficiency.h" 
#include "../include/matrix.h"
#include "../include/list.h"

#include "time.h"

int matrix_multiplication_std_measure(std_matrix_t *matrix1, std_matrix_t *matrix2)
{
    size_t matrices_size;
    matrices_size = sizeof(matrix1);
    matrices_size += sizeof(int) * matrix1->row * matrix1->col;
    matrices_size += sizeof(matrix1->row) + sizeof(matrix1->col);

    matrices_size += sizeof(matrix2);
    matrices_size += sizeof(int) * matrix2->row * matrix2->col;
    matrices_size += sizeof(matrix2->row) + sizeof(matrix2->col);

    if (matrix1->col != matrix2->row)
    {
        printf("ERROR: Matrices cant be multiplied\n");
        return ERROR_CALC;
    }

    std_matrix_t *matrix_res;

    if (allocate_std_matrix(&matrix_res, matrix1->col, matrix2->row) != ERROR_NONE)
        return ERROR_MEMORY;

    reset_std_matrix(matrix_res);

    matrices_size += sizeof(matrix_res);
    matrices_size += sizeof(int) * matrix_res->row * matrix_res->col;
    matrices_size += sizeof(matrix_res->row) + sizeof(matrix_res->col);

    int summ = 0;

    clock_t t = clock();

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

    t = clock() - t;

    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("\nStandart multiplication efficiency\n");
    printf("For matrices [%d x %d] X [%d x %d]\n", matrix1->row, matrix1->col, matrix2->row, 1);
    printf("Time of calculation: %lf\n", time_taken);
    printf("Memory used: %zu\n", matrices_size);

    free_std_matrix(&matrix_res);
    return ERROR_NONE;
}

extern size_t get_list_size(list_t *list);

int matrix_multiplication_s_measure(matrix_t *matrix, vector_t *vector, vector_t **result)
{
    size_t matrices_size;
    matrices_size = sizeof(matrix);
    // Size of A and JA arrays
    matrices_size += sizeof(int) * matrix->nza * 2;
    matrices_size += get_list_size(&matrix->IA);

    matrices_size += sizeof(vector);
    matrices_size += sizeof(int) * vector->nza * 2;

    matrices_size += sizeof(*result);

    if (matrix->col != vector->row)
    {
        printf("ERROR: matrices cant be multiplied\n");
        return ERROR_CALC;
    }

    int curr_sum = 0;
    int IA_index = 1;

    int curr_IA;
    int prev_IA;
    
    int row_nza;

    int first_nza_index;

    int result_nda_index_counter = 0;

    int JA_match = FALSE;
    int vector_index;
    int nza_index;

    int result_JA_counter = 0;


    clock_t t = clock();

    while (value_by_index(&matrix->IA, IA_index) != FALSE)
    {

        curr_IA = value_by_index(&matrix->IA, IA_index);
        prev_IA = value_by_index(&matrix->IA, IA_index - 1);
        
        row_nza = curr_IA - prev_IA;
        first_nza_index = curr_IA - row_nza;

        nza_index = first_nza_index;

        for (int k = nza_index; k < row_nza + first_nza_index; k++)
        {
            for (int i = 0; i < vector->nza; i++)
            {
                if (vector->JA[i] == matrix->JA[k])
                {
                    JA_match = TRUE;
                    vector_index = i;
                    break;
                }
            }

            if (JA_match == TRUE)
            {
                curr_sum += vector->A[vector_index] * matrix->A[k];
                JA_match = FALSE;
            }
        }

        if (curr_sum > 0)
        {
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

    t = clock() - t;

    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("\nSparse multiplication efficiency\n");
    printf("For matrices [%d x %d] X [%d x %d]\n", matrix->row, matrix->col, vector->row, 1);
    printf("Time of calculation: %lf\n", time_taken);
    printf("Memory used: %zu\n", matrices_size);

    correct_vector(result);
    return ERROR_NONE;
}