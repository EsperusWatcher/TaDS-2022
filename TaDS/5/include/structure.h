#ifndef __STRUCTURE__
#define __STRUCTURE__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define ERROR_NONE 0
#define ERROR_MEMO 1
#define ERROR_INPT 2
#define ERROR_OVFL 3

#define TRUE 1
#define FALSE 0

#define SYSTEM LINUX

#if SYSTEM == LINUX
#define CLS_PAUSE getchar();getchar();
#define CLS_CLEAR system("clear");
#elif SYSTEM == WINDOWS
#define CLS_PAUSE system("pause");
#define CLS_CLEAR system("cls");
#endif

#define EXIT_CODE 999

// Max amount of currently in-system requests
#define MAX_REQUEST 100

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
    int index; // Used only in queue testing
    double service_time_1;
    double service_time_2;
};

struct serving_parameters
{
    // Borders for service time of First Machine
    int T1_low;
    int T1_high;

    // Borders for service time of Second Machine
    int T2_low;
    int T2_high;

    // Chance of request going through First Machine into Second Machine
    float proceed_chance;
};

#endif