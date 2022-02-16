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

    ARR_STACK arr_stack;
    arr_stack = arr_init_stack();

    while (TRUE)
    {
        switch (arr_selected)
        {
            case TRUE:
            {
                system("cls");
                arr_print_menu();  

                while (scanf(" %d", &choice) == FALSE && isdigit(choice) == FALSE)
                {
                    system("cls");
                    arr_print_menu();            
                };

                switch (choice)
                {
                    case 1:

                        while (scanf(" %d", &value) == FALSE)
                            printf("Wrong input, try again: ");

                        arr_push(value, arr_stack);
                    
                        break;
                    case 2:
                    
                        if (arr_is_empty(arr_stack) == FALSE)
                            printf("popped: %d\n", arr_pop(arr_stack));
                        else
                            printf("Stack is empty\n");

                        break;
                    case 3:

                        if (arr_is_empty(arr_stack) == FALSE)
                            arr_print_stack(arr_stack);
                        else
                            printf("Stack is empty\n");

                        break;
                    case 4:

                        if (arr_is_empty(arr_stack) == FALSE)
                            arr_empty_stack(arr_stack);
                        else
                            printf("Stack is already empty\n");
                    
                        break;
                    case 5:

                        if (arr_is_empty(arr_stack) == FALSE)
                            printf("top element of stack is %d\n", arr_top(arr_stack));
                        else
                            printf("Stack is empty\n");
                    
                        break;
                    case 6:
                        printf("UNDER CONSTRUCTION\n");
                        break;
                    case 7:
                        arr_selected = FALSE;
                        break;
                    default:
                        free(arr_stack);
                        return ERROR_NONE;

                }

                system("pause");
            }

            break;

            default:
            {
                system("cls");


                system("pause");
            }
        }
    }

    return ERROR_NONE;
}