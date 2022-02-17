#include "../include/structure.h"
#include "../include/arr_structure.h"
#include "../include/list_structure.h"
#include "../include/print.h"

void display_error(int code)
{
    system("cls");

    switch(code)
    {
        case ERROR_INPUT:
            printf("ERROR: Input error\n");
            break;
        case ERROR_MEMORY:
            printf("ERROR: Memory error\n");
            break;
        case ERROR_OVERFLOW:
            printf("ERROR: Overflow error\n");
            break;
        default:
            printf("ERROR\n");
            break;
    }

    system("pause");
}

int input_check(char *msg, int *input)
{
    printf("%s ", msg);

    if (scanf(" %d", &*input) != FALSE && isdigit(*input))
        return TRUE;
    
    return FALSE;
}

void arr_print_menu()
{
    printf("[ ARRAY STACK MENU ]\n");
    printf("1) Push arr stack\n");
    printf("2) Pop arr stack\n");
    printf("3) Show arr stack\n");
    printf("4) Empty arr stack\n");
    printf("5) Top arr stack\n");
    printf("6) Compare arr & list stacks efficiency\n");
    printf("7) Switch to list stack\n");
    printf("Or anything else to Exit\n");
    printf("Choose: ");
}

void list_print_menu()
{
    printf("[ LIST STACK MENU ]\n");
    printf("1) Push list stack\n");
    printf("2) Pop list stack\n");
    printf("3) Show list stack\n");
    printf("4) Empty list stack\n");
    printf("5) Top list stack\n");
    printf("6) Compare arr & list stacks efficiency\n");
    printf("7) Switch to arr stack\n");
    printf("8) Reverse array of ascanding numbers\n");
    printf("Or anything else to Exit\n");
    printf("Choose: ");
}