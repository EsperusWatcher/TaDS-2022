#ifndef __MULTI__
#define __MULTI__

#include "structure.h"
#include "matrix.h"
#include "print.h"

int matrix_multiplication_std(std_matrix_t *matrix1, std_matrix_t *matrix2);
int matrix_multiplication_s(matrix_t *matrix, vector_t *vector, vector_t *result);
int measure_difference();

#endif