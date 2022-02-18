#include "../include/efficiency.h"

void measure_efficiency(ARR_STACK arr_stack, LIST_STACK l_stack)
{
    printf("\n[ -- EFFICIENCY TESTING -- ]\n");
    printf("[ -------------------------]\n");
    printf("[ SIZE OF STACK: %9d ]\n", l_stack->max_size);
    printf("[ -------------------------]\n");
    printf("[                          ]\n");
    printf("[ ------ ARRAY--TESTS -----]\n");
    printf("[ -------------------------]\n");
    time_t final_time;
    time_t start_time = clock();
    
    arr_fill_stack(arr_stack);
    
    final_time = clock() - start_time;

    double time_taken = ((double)final_time) / CLOCKS_PER_SEC;
    
    printf("[ FILL TIME: %.11lf ]\n", time_taken);

    start_time = clock();

    arr_empty_stack(arr_stack);

    final_time = clock() - start_time;

    time_taken = ((double)final_time) / CLOCKS_PER_SEC;

    printf("[ EMPTY TIME: %.10lf ]\n", time_taken);
    
    size_t stack_size = sizeof(arr_stack);
    stack_size += sizeof(arr_stack->stack) * l_stack->max_size;

    printf("[ MEMORY USED: %11zu ]\n", stack_size);
    printf("[ -------------------------]\n");
    printf("[                          ]\n");
    printf("[ ------ LIST - TESTS -----]\n");
    printf("[ -------------------------]\n");

    start_time = clock();

    list_fill_stack(l_stack);

    final_time = clock() - start_time;

    time_taken = ((double)final_time) / CLOCKS_PER_SEC;

    printf("[ FILL TIME: %.11lf ]\n", time_taken);

    stack_size = sizeof(l_stack);
    list_stack_size(l_stack, &stack_size);
    
    start_time = clock();
    
    list_empty_stack(l_stack);

    final_time = clock() - start_time;

    time_taken = ((double)final_time) / CLOCKS_PER_SEC;

    printf("[ EMPTY TIME: %.10lf ]\n", time_taken);
    printf("[ MEMORY USED: %11zu ]\n", stack_size);
    printf("[ -------------------------]\n\n");
}

void compare_stacks()
{
    ARR_STACK arr_stack_50;
    arr_stack_50 = arr_init_stack(STACK_SIZE_TEST_1);
    ARR_STACK arr_stack_500;
    arr_stack_500 = arr_init_stack(STACK_SIZE_TEST_2);
    ARR_STACK arr_stack_10000;
    arr_stack_10000 = arr_init_stack(STACK_SIZE_TEST_3);

    LIST_STACK l_stack_50;
    list_init_stack(&l_stack_50, STACK_SIZE_TEST_1);
    LIST_STACK l_stack_500;
    list_init_stack(&l_stack_500, STACK_SIZE_TEST_2);
    LIST_STACK l_stack_10000;
    list_init_stack(&l_stack_10000, STACK_SIZE_TEST_3);

    measure_efficiency(arr_stack_50, l_stack_50);
    measure_efficiency(arr_stack_500, l_stack_500);
    measure_efficiency(arr_stack_10000, l_stack_10000);

    printf("OK list\n");
    list_free_stack(&l_stack_50);
    printf("OK list\n");

    list_free_stack(&l_stack_500);
    printf("OK list\n");
    list_free_stack(&l_stack_10000);
    printf("OK list\n");

    arr_free_stack(&arr_stack_50);
    arr_free_stack(&arr_stack_500);
    arr_free_stack(&arr_stack_10000);
    printf("OK arr\n");
}