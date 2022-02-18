#ifndef __STRUCTURE__
#define __STRUCTURE__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define ERROR_NONE 0
#define ERROR_MEMO 1
#define ERROR_INPT 2
#define ERROR_OVFL 3

typedef struct serving_request request_t;
typedef struct serving_parameters param_t;

// On request creation it receives
// time of service in First Machine
// time of service in Second Machine
// Chance of getting into Second Machine after service in First
// If chance doesnt proc service time 1 gets reassigned and
// Process repeats 
struct serving_request
{
    double service_time_1;
    double service_time_2;
    float proceed_chance;
};

struct serving_parameters
{
    // Borders for service time of First Machine
    float T1_low;
    float T1_high;

    // Borders for service time of Second Machine
    float T2_low;
    float T2_high;
};

#endif