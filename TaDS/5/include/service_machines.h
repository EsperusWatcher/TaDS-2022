#ifndef __SERVICE__
#define __SERVICE__

#include "arr_operations.h"
#include "list_operations.h"

#define STD_T1_LOW 0
#define STD_T1_HIGH 6
#define STD_T2_LOW 1
#define STD_T2_HIGH 8
#define STD_PROBABILITY 0.7

// Functions
int change_service_params(param_t *serv_params);
void set_service_params(param_t *serv_params);
request_t generate_request(param_t serv_params);

#endif