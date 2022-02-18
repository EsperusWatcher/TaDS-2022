#include "../include/test.h"

void print_test_menu()
{
    printf("[  ---------------  ]\n");
    printf("[  TESTING  QUEUES  ]\n");
    printf("[  ---------------  ]\n");
    printf("[ 1) Push arr queue ]\n");
    printf("[ 2) Push lst queue ]\n");
    printf("[ 3) Pop arr queue  ]\n");
    printf("[ 4) Pop lst queue  ]\n");
    printf("[ 5) Show arr queue ]\n");
    printf("[ 6) Show lst queue ]\n");
    printf("[     Else EXIT     ]\n");
    printf("[  ---------------  ]\n");
}

int test_loop()
{
    int choice;
    int error_exit = FALSE;

    int error_code = ERROR_NONE;

    param_t service_params;
    set_service_params(&service_params);

    ARR_QUEUE arr_que;

    error_code = arr_init_que(&arr_que);

    if (error_code != ERROR_NONE)
        return error_code;

    while(TRUE)
    {
        if (error_exit != TRUE)
        {
            CLS_CLEAR;
            print_test_menu();
        }

        if (error_exit == TRUE || (scanf(" %d", &choice) != 1))
            choice = EXIT_CODE;

        switch(choice)
        {
            // push arr queeue
            case 1: 
                if (arr_queue_is_full(arr_que))
                    return ERROR_OVFL;
                
                arr_push_que(arr_que, service_params);
                break;
            
            // push list queueue
            case 2:
                printf("in development\n");
                break;

            // pop arr queueue
            case 3:
                if (arr_queue_is_empty(arr_que))
                    printf("WARNING: The queue is empty\n");
                else
                    arr_pop_que(arr_que);

                break;

            // pop list queueue
            case 4:
                printf("In development\n");
                break;

            // Show arr qeueueu
            case 5:
                arr_show_queue(arr_que);
                break;

            // Show list queueue
            case 6:
                printf("In developmnet\n");
                break;

            default:
                // Free mem
                error_code = arr_free_que(&arr_que);
                // Exit
                CLS_CLEAR;
                getchar();
                return error_code;
        }

        if (error_exit != TRUE)
            CLS_PAUSE;
    }

    getchar();
    return error_code;
}