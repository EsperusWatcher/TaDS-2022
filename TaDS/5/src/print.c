#include "../include/print.h"

void print_error_code(int err)
{
    CLS_CLEAR;

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

    CLS_PAUSE;
}

// Main UI
void print_menu()
{
    printf("1) Change time parameters\n");
    printf("2) Array queue simulation\n");
    printf("3) List queue simulation\n");
    printf("4) Efficiency comparison\n");
    printf("5) Queue testing mode\n");
    printf("X) Anything else - Exit\n");
    printf("Choice: ");
}

// Prints current service parameters:
// - T1 timers (First Machine operaing time)
// - T2 timers (Second Machine operating time)
// - Probability of passing request to Second Machine
void print_curr_parameters(param_t serv_params)
{
    printf("[ CURRENT SERVICE PARAMETERS ]\n");
    printf("T1: %d -> %d\n", serv_params.T1_low, serv_params.T1_high);
    printf("T2: %d -> %d\n", serv_params.T2_low, serv_params.T2_high);
    printf("Passing Probability: %.1lf\n", serv_params.proceed_chance);
    printf("[ -------------------------- ]\n");
}

// Iterface for service parameter changes
void print_param_change_choices(param_t serv_params)
{
    print_curr_parameters(serv_params);
    printf("What would you like to change?\n");
    printf("1) T1 timer (First Machine operating time)\n");
    printf("2) T2 timer (Second Machine operating time)\n");
    printf("3) Probability of passing request\n");
    printf("X) Anything else - Exit\n");
    printf("Choice: ");
}