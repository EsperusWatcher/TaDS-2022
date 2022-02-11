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

void print_s_matrix_normal_view(matrix_t *matrix)
{
    int JA_counter = 0;
    int A_counter = 0;
    int IA_counter = 0;
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            
        }
    }
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