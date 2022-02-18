#ifndef __PRINT__
#define __PRINT__

#include "service_machines.h"

void print_error_code(int err);
void print_param_change_choices(param_t serv_params);
void print_curr_parameters(param_t serv_params);
void print_menu();

#endif