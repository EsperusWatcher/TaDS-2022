#include "../include/print.h"

void print_error_code(int err)
{
    system("cls");
    
    switch(err)
    {
        case ERROR_INPT:
            printf("ERROR: Input error\n");
            break;
        case ERROR_MEMO:
            printf("ERROR: Memory error\n");
            break;
        case ERROR_OVFL:
            printf("ERROR: Overflow error\n");
            break;
        default:
            printf("ERROR: Unspecified error\n");
            break;
    }

    system("pause");
}