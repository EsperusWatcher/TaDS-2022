#ifndef __MATRIX__
#define __MATRIX__

#include "structure.h"

int create_std_matrix(std_matrix_t **matrix);
int free_std_matrix(std_matrix_t **std_matrix);
int allocate_std_matrix(std_matrix_t **std_matrix, int row, int col);
int fill_std_matrix(std_matrix_t *matrix, int amount);
void reset_std_matrix(std_matrix_t *matrix);
void auto_fill_matrix(std_matrix_t *matrix, int percent);
int count_nza(std_matrix_t *matrix);

int allocate_s_matrix(matrix_t **matrix, int row, int col, int nza);
int create_s_matrix(matrix_t **matrix);
int fill_s_matrix(matrix_t **matrix);

int free_s_matrix(matrix_t **matrix);

int std_to_sparse(std_matrix_t *matrix, matrix_t **s_matrix);

int allocate_sparse_vector(vector_t **vector, int nza);
int free_s_vector(vector_t **vector);
int fill_s_vector(vector_t **vector);
int create_s_vector(vector_t **vector);
void auto_fill_s_vector(vector_t **vector);

#endif