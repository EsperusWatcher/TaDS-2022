#ifndef __MATRIX__
#define __MATRIX__

#include "structure.h"

int create_std_matrix(std_matrix_t **matrix);
int free_std_matrix(std_matrix_t **std_matrix);
int allocate_std_matrix(std_matrix_t **std_matrix, int row, int col);
int fill_std_matrix(std_matrix_t *matrix, int amount);
void reset_std_matrix(std_matrix_t *matrix);
void auto_fill_matrix(std_matrix_t *matrix, int percent);

int allocate_s_matrix(matrix_t **matrix, int row, int col, int nza);
int create_s_matrix(matrix_t **matrix);
int fill_s_matrix(matrix_t **matrix);
int auto_fill_s_matrix(matrix_t **matrix, int density);

int allocate_random_s_matrix(matrix_t *matrix, int A_size, int JA_size);
int free_s_matrix(matrix_t **matrix);

#endif