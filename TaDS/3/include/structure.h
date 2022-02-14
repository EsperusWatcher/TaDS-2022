#ifndef __STRUCTURE__
#define __STRUCTURE__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define ERROR_NONE 0
#define ERROR_INPUT 1
#define ERROR_CALC 2
#define ERROR_MEMORY 3

// Max stndart matrix size is limited to 100x100 elements
#define MAX_STD_SIZE 100

#define TRUE 1
#define FALSE 0

#define DEBUG TRUE

// Linked list for tracking elements in sparse matrix
typedef struct node
{
    int index;
    int start_row_ind;
    struct node *next;
} node_t;

typedef struct list
{
    struct node *root;
} list_t;

// sparse vector structure
// vector-column
typedef struct s_vector
{
    int *A; // Non-zero values
    int *JA; // For storing row indexes
    int row; // Overall amount of rows in vector
    int nza; // Amount of non-zero elements
} vector_t;

typedef struct s_matrix
{
    int row;
    int col;

    // Non-zero elements
    int nza;

    int *A; // Non-zero values
    int *JA; // Columns for A elements

    // Linked list containing N elemens
    // N element contains number of A/JA component
    // Describing Nk row and A matrix (???????)
    list_t IA; 
} matrix_t;

// standart matrix
typedef struct std_matr
{
    int **matrix;
    int row;
    int col;
} std_matrix_t;

#endif