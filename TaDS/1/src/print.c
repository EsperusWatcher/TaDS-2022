#include "../include/print.h"

void print_number(number_t *num)
{
    for (int i = 0; i < sizeof(num->mantissa); i++)
    {
        printf("%c |", num->mantissa[i]);
    }
    printf("\n");
}

void print_num_t(number_t *num)
{
    printf("\n");
    printf("Number: ");
    switch(num->mantissa_sign)
    {
        case -1:
            printf("-0. ");
            break;
        default:
            printf("+0. ");
            break;
    }
    printf("%s E ", num->mantissa);
    printf("%d\n", num->degree);
    printf("\n");
}