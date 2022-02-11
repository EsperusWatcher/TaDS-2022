#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define ERROR_NONE 0
#define ERROR_INPUT 1
#define ERROR_OVERFLOW 2
#define ERROR_MEMORY 3

#define SIZE_MANTISSA 31
#define SIZE_DEGREE 6
#define SIZE_BUFF 100 // Used to take number input

#define MAX_DEGREE 99999

#define DEBUG FALSE

typedef struct number_t
{
    int mantissa_sign;
    char mantissa[SIZE_MANTISSA * 2];
    int degree;
    int before_dot; // amount of characters before dot symbol 123.423 (3)
} number_t;
