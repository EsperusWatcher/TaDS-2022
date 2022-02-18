#include "../include/service_machines.h"
#include "../include/print.h"
#include "../include/test.h"

int main()
{
    int choice;
    int error_exit = FALSE;

    // Only for fluff
    int test_exit = FALSE;

    int error_code = ERROR_NONE;

    param_t service_params;
    set_service_params(&service_params);

    while(TRUE)
    {
        test_exit = FALSE;

        if (error_exit != TRUE)
        {
            CLS_CLEAR;
            print_menu();
        }

        if (error_exit == TRUE || (scanf(" %d", &choice) != 1))
            choice = EXIT_CODE;

        switch(choice)
        {
            // Change time parameters
            case 1: 
                error_code = change_service_params(&service_params);
                
                if (error_code != ERROR_NONE)
                {
                    error_exit = TRUE;
                    print_error_code(error_code);
                }

                break;
            
            // Service Machine on Array queue
            case 2:
                printf("in development\n");
                break;

            // Service Machine on List queue
            case 3:
                printf("In development\n");
                break;

            // Compare Array vs List algorithm efficiency
            case 4:
                printf("In development\n");
                break;

            case 5:
                error_code = test_loop();

                if (error_code != ERROR_NONE)
                {
                    error_exit = TRUE;
                    print_error_code(error_code);
                }

                test_exit = TRUE;

                break;
            default:
                // Free mem
                // Exit
                CLS_CLEAR;
                return ERROR_NONE;
        }

        if (error_exit != TRUE)
            if (test_exit == FALSE)
                CLS_PAUSE;

    }

    return ERROR_NONE;
}