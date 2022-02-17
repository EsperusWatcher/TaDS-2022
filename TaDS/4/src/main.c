#include "../include/structure.h"
#include "../include/list_structure.h"
#include "../include/arr_structure.h"
#include "../include/list_operations.h"
#include "../include/arr_operations.h"
#include "../include/print.h"


int main()
{
    // Switching interface between list/array stack commands
    int arr_selected = TRUE;

    int choice;

    // Used in push() functions
    int value;

    // Flag to exit the loop in case of error
    int error_exit = FALSE;

    ARR_STACK arr_stack;
    arr_stack = arr_init_stack();

    LIST_STACK l_stack;
    if (list_init_stack(&l_stack) != ERROR_NONE)
        display_error(ERROR_MEMORY);

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

                if (error_exit == TRUE || (scanf(" %d", &choice) == FALSE && isdigit(choice) == FALSE))
                    choice = EXIT_CODE;

                switch (choice)
                {
                    case 1:
                        printf("Enter the integer value: ");
                        while (scanf(" %d", &value) == FALSE && isdigit(value) == FALSE)
                        {
                            error_exit = TRUE;
                            display_error(ERROR_INPUT);
                            break;
                        }
                        
                        if (arr_push(value, arr_stack) != ERROR_NONE)
                        {
                            error_exit = TRUE;
                            display_error(ERROR_OVERFLOW);
                        }
                    
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
                        arr_free_stack(&arr_stack);
                        list_free_stack(&l_stack);
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

                if (error_exit == TRUE || (scanf(" %d", &choice) == FALSE && isdigit(choice) == FALSE))
                {
                    choice = 10;
                }

                switch (choice)
                {
                    case 1:
                        printf("Enter the integer value: ");
                        while (scanf(" %d", &value) == FALSE && isdigit(value) == FALSE)
                        {
                            error_exit = TRUE;
                            display_error(ERROR_INPUT);
                            break;
                        }
                        
                        if (list_push(l_stack, value) != ERROR_NONE)
                        {
                            error_exit = TRUE;
                            display_error(ERROR_OVERFLOW);
                            break;
                        }
                    
                        break;
                    case 2:
                    
                        if (!list_is_stack_empty(l_stack))
                            printf("popped: %d\n", list_pop(l_stack));
                        else
                            printf("WARNING: Stack is empty\n");

                        break;
                    case 3:

                        if (!list_is_stack_empty(l_stack))
                            list_show_stack(l_stack);
                        else
                            printf("WARNING: Stack is empty\n");

                        break;
                    case 4:

                        if (!list_is_stack_empty(l_stack))
                            list_empty_stack(l_stack);
                        else
                            printf("WARNING: Stack is already empty\n");
                    
                        break;
                    case 5:

                        if (!list_is_stack_empty(l_stack))
                            printf("top element of the stack is %d\n", list_top(l_stack));
                        else
                            printf("WARNING: Stack is empty\n");
                    
                        break;
                    case 6:
                        printf("UNDER CONSTRUCTION\n");
                        break;
                    case 7:
                        arr_selected = TRUE;
                        break;
                    default:
                        system("cls");
                        arr_free_stack(&arr_stack);
                        list_free_stack(&l_stack);
                        return ERROR_NONE;
                }

                if (error_exit != TRUE)
                    system("pause");
            }
        }
    }

    return ERROR_NONE;
}