#ifndef __MULTI__
#define __MULTI__

#include "structure.h"
#include "matrix.h"
#include "print.h"

int matrix_multiplication_std(std_matrix_t *matrix1, std_matrix_t *matrix2);
int matrix_multiplication_s(matrix_t *matrix1, matrix_t *matrix2);
int measure_difference();

#endif



    /*
  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d", &m, &n);
  printf("Enter elements of first matrix\n");
 
  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      scanf("%d", &first[c][d]);
 
  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &q);
 
  if (n != p)
    printf("The multiplication isn't possible.\n");
  else
  {
    printf("Enter elements of second matrix\n");
 
    for (c = 0; c < p; c++)
      for (d = 0; d < q; d++)
        scanf("%d", &second[c][d]);
 
    m - row1
    n - col1
    p - row 2
    q - col2
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
        for (k = 0; k < p; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
 
        multiply[c][d] = sum;
        sum = 0;
      }
    }
    */