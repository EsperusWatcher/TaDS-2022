#include "../include/test.h"

void matrix_tests()
{
    printf("\nTesting matrix functions...\n");

    printf("test std matrix? y/N\n");
    char choice;

    if (scanf(" %c", &choice) != FALSE && choice == 'y')
    {
        printf("TESTING STD MATRIX CREATION\n");
        
        std_matrix_t *test_matrix;
        create_std_matrix(&test_matrix);

        printf("First matrix:\n");   
        print_matrix(test_matrix);

        std_matrix_t *test_matrix2;
        create_std_matrix(&test_matrix2);
        printf("Second matrix:\n");   
        print_matrix(test_matrix2);

        printf("\nTESTING STD MATRIX MULTIPLICATION\n");

        matrix_multiplication_std(test_matrix, test_matrix2);

        printf("Freeing std matrix: \n");
        free_std_matrix(&test_matrix);
        free_std_matrix(&test_matrix2);
        printf("DONE\n");
    }

    printf("Testing sparse matrix creation...\n");
    matrix_t *test_s_matrix1;

    create_s_matrix(&test_s_matrix1);
    print_s_matrix(test_s_matrix1);
    print_s_matrix_normal_view(test_s_matrix1);

    printf("Testing sparse vector creation...\n");
    vector_t *test_s_vector;
    vector_t *test_s_vector_result;

    create_s_vector(&test_s_vector);
    print_s_vector_std_view(test_s_vector);

    printf("Testing auto-creating vector...\n");
    auto_create_s_vector(&test_s_vector_result, test_s_matrix1->col);
    //print_s_vector_std_view(test_s_vector_result);

    printf("Testing sparse matrix x vector multiplication...\n");
    matrix_multiplication_s(test_s_matrix1, test_s_vector, &test_s_vector_result);

    printf("Result:\n");
    print_s_vector(test_s_vector_result);
    //print_s_vector_std_view(test_s_vector_result);

    printf("Freeing sparse vectors \n");
    free_s_vector(&test_s_vector);
    free_s_vector(&test_s_vector_result);

    printf("Freeing sparse matrix \n");
    free_s_matrix(&test_s_matrix1);
    printf("DONE\n");
}

void list_tests()
{
    printf("Testing list functions...\n");
    
    matrix_t test_matrix;
    
    initialize_IA_list(&test_matrix.IA);
    
    printf("Initial list (empty): ");
    print_list_IA(&test_matrix.IA);
    
    add_node(&test_matrix.IA, 2);
    add_node(&test_matrix.IA, 2);
    add_node(&test_matrix.IA, 4);
    add_node(&test_matrix.IA, 8);
    add_node(&test_matrix.IA, 9);
    add_node(&test_matrix.IA, 12);

    printf("Filled list: ");
    print_list_IA(&test_matrix.IA);

    printf("Getting test values by index: \n");

    for (int i = 0; i < 3; i++)
    {
        int l = value_by_index(&test_matrix.IA, i);
        if (l == FALSE)
        {
            printf("ERROR getting value by index\n");
        }
        else
        {
            printf("IA[%d] = %d\n", i, l);
        }
    }
    
    free_list(&test_matrix.IA);
    
    printf("DONE\n");
}

int tests()
{
    list_tests();
    matrix_tests();

    return ERROR_NONE;
}