#ifndef __PRINT__
#define __PRINT__

#define MAX_SPARSE_PRINT_ROW 30
#define MAX_SPARSE_PRINT_COL 30

void print_arr(int *arr, int size);
void print_matrix(std_matrix_t *matrix);
void print_list_IA(list_t *list);
int check_in(int *list, int list_size, int element);
void print_s_matrix_normal_view(matrix_t *matrix);
void print_s_matrix(matrix_t *matrix);

#endif