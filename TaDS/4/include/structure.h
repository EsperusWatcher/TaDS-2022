#ifndef __STRUCTURE__
#define __STRUCTURE__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define ERROR_NONE 0
#define ERROR_INPUT 1
#define ERROR_CALC 2
#define ERROR_MEMORY 3
#define ERROR_OVERFLOW 4
#define ERROR_EMPTY 5

#define BUFFER_SIZE 256
#define STACK_SIZE 128

#define TRUE 1
#define FALSE 0

#define DISPLAY_ERROR_INPUT \
    system("cls"); \
    printf("ERROR: Wrong input\n"); \
    system("pause"); \

#endif