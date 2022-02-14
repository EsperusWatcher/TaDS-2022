#include "../include/structure.h"
#include "../include/list.h"
#include "../include/print.h"

void print_arr(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    printf("]\n");
}

// Printnig out default matrix
void print_matrix(std_matrix_t *matrix)
{
    printf("----------------------------------------\n");

    printf("Standart matrix output:\n");
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            printf("%d ", matrix->matrix[i][j]);
        }

        printf("\n");
    }

    printf("----------------------------------------\n");
}

void print_list_IA(list_t *list)
{
    node_t *point = list->root->next;
    printf("IA: [");

    while (point != NULL)
    {
        if (point->next == NULL)
            printf("%d", point->start_row_ind);
        else
            printf("%d, ", point->start_row_ind);

        point = point->next;
    }

    printf("]\n");
}

// Checks if given element is in the given list (array)
int check_in(int *list, int list_size, int element)
{
    for (int i = 0; i < list_size; i++)
    {
        if (list[i] == element)
            return TRUE;
    }

    return FALSE;
}

extern int value_by_index(list_t *list, int index);
void print_s_matrix_normal_view(matrix_t *matrix)
{
    printf("\nSPARSE MATRIX IN STANDART VIEW\n\n");
 
    if (matrix->row > MAX_SPARSE_PRINT_ROW || matrix->col > MAX_SPARSE_PRINT_COL)
    {
        printf("The sparse matrix is too big to be printed in standart view\n");
        return;
    }
    // We start at the second element because
    // The first one is 0 and is used only to enable comparison
    int IA_index = 1;

    int JA_index = 0;
    int A_index = 0;

    // Stores row_index value
    int IA_previous;

    // Cycle through each row and look if it has any non-zero values in it
    // If it does (we can check by comparing current IA element with a previous one)
    // We go through (index_difference) to print them along 0's
    // If not we only print 0's
    for (int i = 0; i < matrix->row; i++, IA_index++)
    {
        // If true, that means we reached non-zero row, else just fill ouput with 0's
        if (value_by_index(&matrix->IA, IA_index) > value_by_index(&matrix->IA, IA_index - 1))
        {
            // This means the amount of non-zero elements in current row
            int diff = value_by_index(&matrix->IA, IA_index) - value_by_index(&matrix->IA, IA_index - 1);

            // Going through each column of non-zero row
            for (int k = 0; k < matrix->col; k++)
            {
                if (k == matrix->JA[JA_index] && diff > 0)
                {
                    printf("%d ", matrix->A[A_index]);
                    
                    // They can be replaced with one variable essentially
                    // Since there is the same amount of values to row indexes
                    // But I'll leave it like this for clarity
                    A_index++;
                    JA_index++;

                    diff--;
                }
                else
                    printf("0 ");
            }
        }
        else
            // Row has no non-zero elements so we just fill it with 0's
            for (int k = 0; k < matrix->col; k ++)
                printf("0 ");
        
        printf("\n");
    }

    printf("\n");
    printf("----------------------------------------\n");
}

// Printning out sparse matrix
void print_s_matrix(matrix_t *matrix)
{
    printf("-------------------------\n");
    printf("Sparse matrix output:\n");
    printf("A: ");
    print_arr(matrix->A, matrix->nza);
    printf("JA: ");
    print_arr(matrix->JA, matrix->nza);
    print_list_IA(&matrix->IA);
    printf("-------------------------\n");
    
}

void print_s_vector(vector_t *vector)
{
    printf("----------------------\n");
    printf("SPARSE VECTOR\n");

    printf("A: ");
    print_arr(vector->A, vector->nza);
    printf("JA: ");
    print_arr(vector->JA, vector->nza);
    printf("-------------------------\n");
}

void print_s_vector_std_view(vector_t *vector)
{
    printf("----------------------\n");
    printf("SPARSE VECTOR IN STD VIEW\n");

    int prev_JA = 0;
    for (int i = 0; i < vector->nza; i++)
    {
        if (vector->JA[i] - vector->JA[prev_JA] > 0)
        {
            int diff = vector->JA[i] - vector->JA[prev_JA];
            for (int k = 0; k < diff - 1; k++)
            {
                printf("0\n");
            }
        }

        printf("%d\n", vector->A[i]);        
    }
    printf("----------------------\n");
}