#include "../include/structure.h"
#include "../include/list_structure.h"
#include "../include/arr_structure.h"
#include "../include/list_operations.h"
#include "../include/arr_operations.h"
#include "../include/print.h"

int main()
{
    int arr_selected = TRUE;
    int choice;
    int value;
    int error_exit = FALSE;

    ARR_STACK arr_stack;
    arr_stack = arr_init_stack();

    while (TRUE)
    {
        switch (arr_selected)
        {
            case TRUE:
            {
                if (error_exit != TRUE)
                {
                    system("cls");
                    arr_print_menu();  
                }

                if ((scanf(" %d", &choice) == FALSE && isdigit(choice) == FALSE) || error_exit == TRUE)
                {
                    choice = 10;
                }

                switch (choice)
                {
                    case 1:

                        printf("Enter the value: ");
                        while (scanf(" %d", &value) == FALSE && isdigit(value) == FALSE)
                        {
                            error_exit = TRUE;
                            DISPLAY_ERROR_INPUT;
                            break;
                        }

                        arr_push(value, arr_stack);
                    
                        break;
                    case 2:
                    
                        if (arr_is_empty(arr_stack) == FALSE)
                            printf("popped: %d\n", arr_pop(arr_stack));
                        else
                            printf("WARNING: Stack is empty\n");

                        break;
                    case 3:

                        if (arr_is_empty(arr_stack) == FALSE)
                            arr_print_stack(arr_stack);
                        else
                            printf("WARNING: Stack is empty\n");

                        break;
                    case 4:

                        if (arr_is_empty(arr_stack) == FALSE)
                            arr_empty_stack(arr_stack);
                        else
                            printf("WARNING: Stack is already empty\n");
                    
                        break;
                    case 5:

                        if (arr_is_empty(arr_stack) == FALSE)
                            printf("top element of the stack is %d\n", arr_top(arr_stack));
                        else
                            printf("WARNING: Stack is empty\n");
                    
                        break;
                    case 6:
                        printf("UNDER CONSTRUCTION\n");
                        break;
                    case 7:
                        arr_selected = FALSE;
                        break;
                    default:
                        system("cls");
                        free(arr_stack);
                        return ERROR_NONE;
                }

                if (error_exit != TRUE)
                    system("pause");
            }

            break;

            default:
            {
                if (error_exit != TRUE)
                {
                    system("cls");
                    list_print_menu();
                }

                if ((scanf(" %d", &choice) == FALSE && isdigit(choice) == FALSE) || error_exit == TRUE)
                {
                    choice = 10;
                }

                //TODO Switch everything to list structure
                switch (choice)
                {
                    case 1:

                        printf("Enter the value: ");
                        while (scanf(" %d", &value) == FALSE && isdigit(value) == FALSE)
                        {
                            error_exit = TRUE;
                            DISPLAY_ERROR_INPUT;
                            break;
                        }

                        arr_push(value, arr_stack);
                    
                        break;
                    case 2:
                    
                        if (arr_is_empty(arr_stack) == FALSE)
                            printf("popped: %d\n", arr_pop(arr_stack));
                        else
                            printf("WARNING: Stack is empty\n");

                        break;
                    case 3:

                        if (arr_is_empty(arr_stack) == FALSE)
                            arr_print_stack(arr_stack);
                        else
                            printf("WARNING: Stack is empty\n");

                        break;
                    case 4:

                        if (arr_is_empty(arr_stack) == FALSE)
                            arr_empty_stack(arr_stack);
                        else
                            printf("WARNING: Stack is already empty\n");
                    
                        break;
                    case 5:

                        if (arr_is_empty(arr_stack) == FALSE)
                            printf("top element of the stack is %d\n", arr_top(arr_stack));
                        else
                            printf("WARNING: Stack is empty\n");
                    
                        break;
                    case 6:
                        printf("UNDER CONSTRUCTION\n");
                        break;
                    case 7:
                        arr_selected = FALSE;
                        break;
                    default:
                        system("cls");
                        free(arr_stack);
                        return ERROR_NONE;
                }

                if (error_exit != TRUE)
                    system("pause");
            }
        }
    }

    return ERROR_NONE;
}