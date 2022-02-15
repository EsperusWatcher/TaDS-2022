#include "../include/matrix.h"

extern int add_node(list_t *list, int value);

// Memory allocation for standart matrix
int allocate_std_matrix(std_matrix_t **std_matrix, int row, int col)
{
    *std_matrix = (std_matrix_t *)malloc(sizeof(std_matrix_t));
    (*std_matrix)->matrix = (int **)malloc(sizeof(int *) * row);

    if (*std_matrix == NULL || (*std_matrix)->matrix == NULL)
    {
        printf("Error in std matrix memory allocation: NULL pointers\n");
        return ERROR_MEMORY;
    }

    for (int i = 0; i < row; i++)
    {
        (*std_matrix)->matrix[i] = (int *)calloc(sizeof(int), col);

        if ((*std_matrix)->matrix[i] == NULL)
        {
            printf("Error in std matrix memory allocation: NULL pointers\n");
            return ERROR_MEMORY;
        }
    }

    (*std_matrix)->row = row;
    (*std_matrix)->col = col;
    return ERROR_NONE;
}

// freeing allocated memory for standart matrix structure
int free_std_matrix(std_matrix_t **std_matrix)
{
    for (int i = 0; i < (*std_matrix)->row; i++)
    {
        if ((*std_matrix)->matrix[i] == NULL)
        {
            printf("Error in freeing std matrix memory: attempting to free NULL pointer\n");
            return ERROR_MEMORY;
        }

        free((*std_matrix)->matrix[i]);
    }

    if ((*std_matrix)->matrix == NULL)
    {
        printf("Error in freeing std matrix memory: attempting to free NULL pointer\n");
        return ERROR_MEMORY;
    }

    free((*std_matrix)->matrix);
    free(*std_matrix);
    return ERROR_NONE;
}

// Used to unify all std matrix-related creation functions
int create_std_matrix(std_matrix_t **matrix)
{
    int row;
    int col;
    int nza;
    int density = 0;

    printf("Input amount of ROWS: ");
    if (scanf("%d", &row) == FALSE || row < 0)
    {
        printf("ERROR: wrong matrix input\n");
        return ERROR_INPUT;
    }

    printf("Input amount of COLUMNS: ");
    if (scanf("%d", &col) == FALSE || col < 0)
    {
        printf("ERROR: wrong matrix input\n");
        return ERROR_INPUT;
    }

    printf("allocation\n");
    if (allocate_std_matrix(matrix, row, col) != ERROR_NONE)
        return ERROR_MEMORY;

    printf("Would you like to fill matrix by hand (y) / randomize (N): ");
    char choice;

    if (scanf(" %c", &choice) != TRUE)
    {
        printf("ERROR: input error\n");
        return ERROR_INPUT;
    }
    
    switch (choice)
    {
        // Input matrix by user
        case 'y':
            printf("Input amount of ELEMENTS: ");
            if (scanf("%d", &nza) == FALSE || nza < 0 || nza > row * col)
            {
                printf("ERROR: wrong matrix input\n");
                return ERROR_INPUT;
            }

            fill_std_matrix(*matrix, nza);
            
            break;

        // Randomize matrix
        default:
            printf("Input fill density (0-100): ");

            if (scanf("%d", &density) != TRUE || density < 0 || density > 100)
            {
                printf("ERROR: wrong input\n");
                return ERROR_INPUT;
            }

            auto_fill_matrix(*matrix, density);
            
            break;
    }

    return ERROR_NONE;
}

// Takes x, y and assigns value to element of the matrix
int fill_std_matrix(std_matrix_t *matrix, int amount)
{
    int pos_x = -1;
    int pos_y = -1;
    int element;

    for (int i = 0; i < amount; i++)
    {
        printf("Input ROW and COLUMN of the element: ");
        if (scanf("%d%d", &pos_x, &pos_y) != 2 || pos_x < 0 || pos_y < 0)
        {
            printf("ERROR: wrong element input\n");
            return ERROR_INPUT;
        }

        if (pos_x > matrix->row || pos_y > matrix->col)
        {
            printf("ERROR: trying to set value outside matrix bounds\n");
            return ERROR_INPUT;
        }

        printf("matrix[%d][%d] = ", pos_x, pos_y);
        if (scanf("%d", &element) == FALSE)
        {
            printf("ERROR: wrong element input\n");
            return ERROR_INPUT;
        }
        else
            matrix->matrix[pos_x][pos_y] = element;
    }

    return ERROR_NONE;
}

// Function for randomized matrix fill
// According to given density
void auto_fill_matrix(std_matrix_t *matrix, int density)
{ 
    int chance;

    for(int i = 0; i < matrix->row; i++)
        for(int j = 0; j < matrix->col; j++)
        {
            chance = rand() % 100;
            if (chance < density)
                matrix->matrix[i][j] = rand() % 10;
            else
                matrix->matrix[i][j] = 0;
        }
}

// ounts non-zero elements in standart matrix
int count_nza(std_matrix_t *matrix)
{
    int counter = 0;
    for (int i = 0; i < matrix->row; i++)
    {
        for (int k = 0; k < matrix->col; k++)
            if (matrix->matrix[i][k] != 0)
                counter++;
    }

    return counter;
}

int std_to_sparse(std_matrix_t *matrix, matrix_t **s_matrix)
{
    (*s_matrix)->IA.root->start_row_ind = 0;

    // First element of the list is 0
    if (add_node(&(*s_matrix)->IA, 0) != ERROR_NONE)
        return ERROR_MEMORY;

    // For IA list
    int row_nza_counter = 0;
    int last_IA_value_counter;
    int total_nza_counter = 0;
    int zero_row_counter = 0;
    int nza_stored_counter = 0;

    for (int i = 0; i < matrix->row; i++)
    {
        for (int k = 0; k < matrix->col; k++)
        {
            if (matrix->matrix[i][k] > 0)
            {
                row_nza_counter++;
                total_nza_counter++;
            }
        }

        if (row_nza_counter == 0)
        {
            zero_row_counter++;
        }
        else
        {
            for (int k = 0; k < matrix->col; k++)
            {
                if (matrix->matrix[i][k] > 0)
                {
                    (*s_matrix)->A[nza_stored_counter] = matrix->matrix[i][k];
                    (*s_matrix)->JA[nza_stored_counter] = k;
                    nza_stored_counter++;
                }
            }

            for (int k = 0; k < zero_row_counter; k++)
            {
                add_node(&(*s_matrix)->IA, last_IA_value_counter);
            }

            add_node(&(*s_matrix)->IA, total_nza_counter);
            last_IA_value_counter = total_nza_counter;
            zero_row_counter = 0;
        }

        row_nza_counter = 0;
    }

    for (int k = 0; k < zero_row_counter; k++)
    {
        if (add_node(&(*s_matrix)->IA, last_IA_value_counter) != ERROR_NONE)
            return ERROR_MEMORY;
    }

    return ERROR_NONE;
}

// Everything in creating and filling sparse matrix
// Either by user or randomization
int create_s_matrix(matrix_t **matrix)
{
    int row = -1;
    int col = -1;
    int elements;

    printf("Input amount of ROWS: ");
    if (scanf("%d", &row) == FALSE || row < 0)
    {
        printf("ERROR: wrong matrix input\n");
        return ERROR_INPUT;
    }

    printf("Input amount of COLUMNS: ");
    if (scanf("%d", &col) == FALSE || col < 0)
    {
        printf("ERROR: wrong matrix input\n");
        return ERROR_INPUT;
    }

    printf("Would you like to fill matrix by hand (y) or auto (N)?\n");
    char choice;

    if (scanf(" %c", &choice) != TRUE)
    {
        printf("ERROR: input error\n");
        return ERROR_INPUT;
    }

    int nza;

    switch (choice)
    {
        case 'y':
            printf("Input amount of ELEMENTS: ");
            if (scanf("%d", &elements) == FALSE)
            {
                printf("ERROR: wrong matrix input\n");
                return ERROR_INPUT;
            }

            if (allocate_s_matrix(matrix, row, col, elements) != ERROR_NONE)
                return ERROR_MEMORY;

            (*matrix)->row = row;
            (*matrix)->col = col;
            (*matrix)->nza = elements;
            // Fill sparse matrix by hand
            fill_s_matrix(matrix);
            break;
        default:
            // Fill sparse matrix randomly
            printf("Input matrix density(1-100): ");
            int density;

            if (scanf(" %d", &density) == FALSE)
            {
                printf("ERROR: wrong matrix input\n");
                return ERROR_INPUT;
            }

            // We will generate random standart matrix and then convert it
            // to sparse matrix because it is soooooo much easier ._.
            std_matrix_t *tmp_matrix;

            if (allocate_std_matrix(&tmp_matrix, row, col) != ERROR_NONE)
                return ERROR_MEMORY;

            auto_fill_matrix(tmp_matrix, density);

            nza = count_nza(tmp_matrix);

            if (allocate_s_matrix(matrix, row, col, nza) != ERROR_NONE)
                return ERROR_MEMORY;

            if (std_to_sparse(tmp_matrix, matrix) != ERROR_NONE)
                return ERROR_MEMORY;

            free_std_matrix(&tmp_matrix);

            (*matrix)->row = row;
            (*matrix)->col = col;
            (*matrix)->nza = nza;

            break;
    }
    
    return ERROR_NONE;
}


// Filling matrix by hand
int fill_s_matrix(matrix_t **matrix)
{
    // When filling sparse matri we have to input all row values
    // in non-descending order. This is the easiest way to fill IA list
    int last_row_index = 0;
    int row_difference = 0;

    int current_row_sum = 0;
    
    int row_ind = -1;
    int col_ind = -1;

    (*matrix)->IA.root->start_row_ind = 0;

    // First element of the list is 0
    if (add_node(&(*matrix)->IA, 0) != ERROR_NONE)
        return ERROR_MEMORY;

    for (int i = 0; i < (*matrix)->nza; i++)
    {
        printf("Enter row and column of the element: ");
        if (scanf(" %d%d", &row_ind, &col_ind) != FALSE)
        {
            if (row_ind < 0 || col_ind < 0)
            {
                printf("ERROR: wrong input\n");
                return ERROR_INPUT;
            }
            else if (row_ind > (*matrix)->row - 1 || col_ind > (*matrix)->col - 1)
            {
                printf("ERROR: input out of matrix bounds\n");
                return ERROR_INPUT;
            }

            (*matrix)->JA[i] = col_ind;

            while (row_ind < last_row_index)
            {
                printf("Row index must not be lower than its previous input\n");
                printf("Enter new row index: ");

                if (scanf(" %d", &row_ind) == FALSE)
                {
                    printf("ERROR: wrong input\n");
                    return ERROR_INPUT;
                }
            }

            if (row_ind > last_row_index)
            {
                row_difference = row_ind - last_row_index;
                
                // Means one or more rows in matrix dont have any non-zero elements
                // So we have to adjust IA list accordingly
                if (row_difference > 0)
                {
                    //? supposedly this adds previous value?
                    for (int k = 0; k < row_difference; k++)
                    {
                        if (add_node(&(*matrix)->IA, current_row_sum) != ERROR_NONE)
                            return ERROR_MEMORY;
                    }
                }

                last_row_index = row_ind;
                current_row_sum++;
            }
            else
                current_row_sum++; // Counting up if we are still on the current row

            printf("matrix[%d][%d] = ", row_ind, col_ind);
            
            if (scanf(" %d", &(*matrix)->A[i]) == FALSE)
            {
                printf("ERROR: Input error\n");
                return ERROR_INPUT;
            }
        }
        else
        {
            printf("ERROR: input error\n");
            return ERROR_INPUT;
        }
    }

    // Adding empty rows after last row with a non-zero element
    for (int i = last_row_index; i < (*matrix)->row; i++)
        if (add_node(&(*matrix)->IA, current_row_sum) != ERROR_NONE)
            return ERROR_MEMORY;
    
    return ERROR_NONE;
}

// Adding this because we need to allocate IA list inside sparse matrix
extern int initialize_IA_list(list_t *list);

// Allocates the specified amount of elements of the sparse matrix
// nza -> non-zero elements
int allocate_s_matrix(matrix_t **matrix, int row, int col, int nza)
{
    *matrix = (matrix_t *)malloc(sizeof(matrix_t));
    (*matrix)->A = (int *)malloc(sizeof(int) * nza);
    (*matrix)->JA = (int *)malloc(sizeof(int) * nza);

    if ((*matrix)->A == NULL || (*matrix)->JA == NULL)
    {
        printf("ERROR: sparse matrix memory allocation\n");
        return ERROR_MEMORY;
    }

    if (initialize_IA_list(&(*matrix)->IA) != ERROR_NONE)
        return ERROR_MEMORY;

    return ERROR_NONE;
}

// Creating randomized sparse matrix
// Fills matrix with random elements
// The algorithm is the same as in fill_s_matrix
// Just randomized

// Function is used to pre-allocate memory for a randomized sparse matrix
// Called before filling matrix with values

// Function from list.c
// Added because linked list is a part of matrix structure
extern void free_list(list_t *list);

int free_s_matrix(matrix_t **matrix)
{
    if ((*matrix)->A == NULL || (*matrix)->JA == NULL)
    {
        printf("ERROR: freeing sparse matrix: attempting to free NULL pointer\n");
        return ERROR_MEMORY;
    }

    free((*matrix)->A);
    free((*matrix)->JA);

    free_list(&(*matrix)->IA);
    free(*matrix);
    printf("s_matrix free OK\n");
}

// Set all elements in matrix to 0
void reset_std_matrix(std_matrix_t *matrix)
{
    for(int i = 0; i < matrix->row; i++)
        for(int j = 0; j < matrix->col; j++)
            matrix->matrix[i][j] = 0;
}

int allocate_sparse_vector(vector_t **vector, int nza)
{
    *vector = (vector_t *)malloc(sizeof(vector_t));
    
    if (*vector == NULL)
    {
        printf("ERROR: vector memory allocation\n");
        return ERROR_MEMORY;
    }
    
    (*vector)->nza = nza;

    (*vector)->A = (int *)calloc(sizeof(int), (*vector)->nza);
    
    if ((*vector)->A == NULL)
    {
        printf("ERROR: vector memory allocation\n");
        return ERROR_MEMORY;
    }

    (*vector)->JA = (int *)calloc(sizeof(int), (*vector)->nza);

    if ((*vector)->JA == NULL)
    {
        printf("ERROR: vector memory allocation\n");
        return ERROR_MEMORY;
    }

    return ERROR_NONE;
}

int free_s_vector(vector_t **vector)
{
    free((*vector)->A);
    free((*vector)->JA);
    free((*vector));
}

int fill_s_vector(vector_t **vector)
{
    int value;
    int row;
    for (int i = 0; i < (*vector)->nza; i++)
    {
        printf("Input element position(row) in vector: ");

        if (scanf(" %d", &row) == FALSE || row > (*vector)->row)
        {
            printf("ERROR: vector input error\n");
            return ERROR_INPUT;
        }

        printf("sparse vector[%d] = ", row);
        if (scanf(" %d", &value) == FALSE)
        {
            printf("ERROR: vector input error\n");
            return ERROR_INPUT;
        }
        else
        {
            (*vector)->A[i] = value;
            (*vector)->JA[i] = row;
        }
    }

    return ERROR_NONE;
}

extern int print_s_vector(vector_t *vector);

// Used to unite everything related to sparse vector creation
int create_s_vector(vector_t **vector)
{
    printf ("Input size(rows) of column-vector: ");
    int rows;

    if (scanf(" %d", &rows) == FALSE)
    {
        printf("ERROR: vector creation input error\n");
        return ERROR_INPUT;
    }

    printf("Would you like to input vector by hand(y) or randomize(N): ");
    char choice;

    if (scanf(" %c", &choice) == FALSE)
    {
        printf("ERROR: vector creation input error\n");
        return ERROR_INPUT;
    }

    int nza;

    switch(choice)
    {
        case 'y':
            printf("Input amount of non-zero elements in vector: ");

            if (scanf(" %d", &nza) == FALSE || nza > rows)
            {
                printf("ERROR: vector creation input error\n");
                return ERROR_INPUT;
            }

            if (allocate_sparse_vector(vector, nza) != ERROR_NONE)
                return ERROR_MEMORY;

            (*vector)->row = rows;

            if (fill_s_vector(vector) != ERROR_NONE)
                return ERROR_INPUT;
            break;

        default:
            printf("Input fill density(1-100): ");
            int density;

            if (scanf(" %d", &density) == FALSE || density < 1 || density > 100)
            {
                printf("ERROR: vector creation input error\n");
                return ERROR_INPUT;
            }

            // Estimation of non-zero elements amount
            // (Rounded up)
            nza = (rows * density + 100 - 1) / 100;

            if (allocate_sparse_vector(vector, rows) != ERROR_NONE)
                return ERROR_MEMORY;

            (*vector)->row = rows;
            (*vector)->nza = nza;

            auto_fill_s_vector(vector);
            break;
    }

    if (rows < 100)
        print_s_vector(*vector);

    return ERROR_NONE;
}

void auto_create_s_vector(vector_t **vector, int size)
{
    int rows = size;

    printf("auto vector size: %d\n", rows);

    int nza = size;

    allocate_sparse_vector(vector, nza);

    (*vector)->row = size;

    if (size < 100)
        print_s_vector(*vector);
}

void auto_fill_s_vector(vector_t **vector)
{
    //estimation of non-zero elements amount
    int fill_JA;
    int fill_A;

    // Elements won't be organized but we dont need them to be
    // Since this is a vector used in multiplication
    // We only care for values, not their order

    for (int i = 0; i < (*vector)->nza; i++)
    {
        fill_JA = rand() % (*vector)->row;
        fill_A = rand() % 10;

        (*vector)->A[fill_JA] = fill_A;
        (*vector)->JA[i] = fill_JA;
    }
}

// Called on result vector after multiplication to
// Get rid of unneded elements
void correct_vector(vector_t **vector)
{
    int z_counter = 0;
    for (int i = 0; i < (*vector)->nza; i++)
    {
        if ((*vector)->A[i] == 0)
            z_counter++;
    }

    (*vector)->nza -= z_counter;
    (*vector)->A = (int *)realloc((*vector)->A, sizeof(int) * (*vector)->nza);
    (*vector)->JA = (int *)realloc((*vector)->JA, sizeof(int) * (*vector)->nza);
}