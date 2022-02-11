#include "../include/multiply.h"
#include "../include/print.h"
#include "../include/input.h"

#include <string.h>

#define FREE_MEM free_mem(num1, num2)
void free_mem(char* num1, char* num2)
{
    free(num1);
    free(num2);

    #if DEBUG
        printf("Memory free\n");
    #endif
}

int main()
{
    int error_code = ERROR_NONE;

    char *num1 = (char *)malloc(SIZE_BUFF * sizeof(char));
    char *num2 = (char *)malloc(SIZE_BUFF * sizeof(char));
    number_t num1_t, num2_t;
    number_t result_t;

    if (num1 == NULL || num2 == NULL)
    {
        printf("Memory allocation error\n");
        return ERROR_MEMORY;
    }

    input_number(num1);

    if (analyze_input(num1) != ERROR_NONE)
    {
        printf("Analyze error\n");
        FREE_MEM;
        printf("OK\n");
        return ERROR_INPUT;
    }
    
    input_number(num2);
    
    if (analyze_input(num2) != ERROR_NONE)
    {
        printf("Analyze error\n");
        FREE_MEM;
        printf("OK\n");
        return ERROR_INPUT;
    }

    if (convert_number(num1, &num1_t) != ERROR_NONE)
    {
        printf("Number conversion error\n");
        FREE_MEM;
        printf("OK\n");
        return ERROR_INPUT;
    }
    else
        print_num_t(&num1_t);

    if (convert_number(num2, &num2_t) != ERROR_NONE)
    {
        printf("Number conversion error\n");
        FREE_MEM;
        printf("OK\n");
        return ERROR_INPUT;
    }
    else
        print_num_t(&num2_t);
    
    if (multiplication(&num1_t, &num2_t, &result_t) == ERROR_NONE)
    {
        
    }
    else
    {
        printf("Multiplication error\n");
        FREE_MEM;
        printf("OK\n");
        return ERROR_INPUT;
    }

    FREE_MEM;
    printf("OK\n");
    return ERROR_NONE;
}