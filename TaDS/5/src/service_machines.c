#include "../include/service_machines.h"
#include "../include/print.h"

request_t generate_request(param_t serv_params)
{
    request_t req;

    req.service_time_1 = (double)serv_params.T1_low + (double)rand()/(double)(RAND_MAX/serv_params.T1_high);
    req.service_time_2 = (double)serv_params.T2_low + (double)rand()/(double)(RAND_MAX/serv_params.T2_high);

    return req;
}

void set_service_params(param_t *serv_params)
{
    serv_params->T1_low = STD_T1_LOW;
    serv_params->T1_high = STD_T1_HIGH;

    serv_params->T2_low = STD_T2_LOW;
    serv_params->T2_high = STD_T2_HIGH;

    serv_params->proceed_chance = STD_PROBABILITY;
}

int change_service_params(param_t *serv_params)
{
    int choice;

    while (TRUE)
    {
        CLS_CLEAR;
        print_param_change_choices(*serv_params);
        
        if (scanf(" %d", &choice) != 1)
            choice = EXIT_CODE;

        switch(choice)
        {
            // Change T1 timer
            case 1: 
                printf("Input new time borders [x to y]: ");
                if (scanf(" %d%d", &serv_params->T1_low, &serv_params->T1_high) != 2)
                    return ERROR_INPT;
                if (serv_params->T1_low > serv_params->T1_high)
                    return ERROR_INPT;
                break;
            
            // Change T2 timer
            case 2:
                printf("Input new time borders [x to y]: ");
                if (scanf(" %d%d", &serv_params->T2_low, &serv_params->T2_high) != 2)
                    return ERROR_INPT;
                if (serv_params->T2_low > serv_params->T2_high)
                    return ERROR_INPT;
                break;

            // Change Probability chance
            case 3:
                printf("Input new probability in range (0, 1]: ");
                if (scanf(" %f", &serv_params->proceed_chance) != 1)
                    return ERROR_INPT;
                if (serv_params->proceed_chance <= 0 || serv_params->proceed_chance > 1)
                    return ERROR_INPT;
                break;
            
            default:
                getchar();
                return ERROR_NONE;
        }
    }
}