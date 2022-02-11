#include "../include/input.h"

static char allowed_symbols[] = "+-.eE";

void print_scheme()
{
    printf("-----------------------------------------------------------------\n");
    printf("\n%s\n\n", "Multiplication of two real numbers not fitting into the bit grid");
    printf("-----------------------------------------------------------------\n");
    printf("%s\n", "INPUT RULES");
    printf("1) Both numbers should contain +/- sign\n");
    printf("2) Numbers can be given as normal or exponential\n");
    printf("3) If number is an exponential:\n");
    printf("    - Degree of a number must be specified\n");
    printf("    - Degree of a number must contain at least one number\n");
}

void print_grid()
{
    printf("\nPlease input a real number:");
    printf("\n%s %28s\n", "mantissa", "degree");
    printf("%3d %8d %9d %9d %2d %3d\n", 1, 10, 20, 30, 1, 5);
    printf("%s", "+|--------|---------|---------|E+|---|\n");
}

int input_number(char* buffer)
{
    static int first_input = TRUE;

    // First input prints rules
    if (first_input)
    {
        print_scheme();
        first_input = FALSE;
    }

    print_grid();
    
    if (scanf("%100s", buffer) != TRUE)
        return ERROR_INPUT;
    else
        printf("\nReceived input: %s\n", buffer);

    return ERROR_NONE;
}

// Check everything about input
int analyze_input(char* buffer)
{
    // Avoiding empty input
    int digit_detected = FALSE;
    // Check if input contains any unallowed symbols
    for (int i = 0; i < SIZE_BUFF && buffer[i] != '\0'; i++)
    {
        if (!isdigit(buffer[i]))
        {
            int unallowed = TRUE;
            for (int k = 0; k < sizeof(allowed_symbols); k++)
                if (buffer[i] == allowed_symbols[k])
                    unallowed = FALSE;
                
            if (unallowed)
            {
                printf("ERROR: Input contains unallowed symbol\n");
                return ERROR_INPUT;
            }
        }
        else
            digit_detected = TRUE;
    }

    // Check if input contains RIGHT AMOUNT of ALLOWED characters
    int right_dot = 1;
    int right_sign = 2;
    int right_exp = 1;

    // Count amount of figures in a number before/after dot
    int before_exp = TRUE;
    int counter = 0;

    for (int i = 0; i < SIZE_BUFF && buffer[i] != '\0'; i++)
    {
        if (buffer[i] == '.')
            right_dot--;

        if (isdigit(buffer[i]))
            counter++;
        
        if (buffer[i] == '+' || buffer[i] == '-')
        {
            right_sign--;
            if (i != 0 && toupper(buffer[i-1]) != 'E')
            {
                printf("ERROR: Wrong sign placement\n");
                return ERROR_INPUT;
            }
        }

        if (toupper(buffer[i]) == 'E')
        {
            right_exp--;

            if (before_exp == TRUE)
            {
                before_exp = FALSE;
                counter = 0;
            }

            // If degree is not specified (has no figures at all)
            // Or sign is not specified
            if (buffer[i+1] == '+' || buffer[i+1] == '-')
            {
                if (buffer[i+2] == '\0')
                {
                    printf("ERROR: Degree not specified\n");
                    return ERROR_INPUT;      
                }
            }
            else
            {
                printf("ERROR: Degree sign not specified\n");
                return ERROR_INPUT;
            }
        }

        if (counter > SIZE_MANTISSA - 1)
        {
            printf("ERROR: Too many figures in mantissa\n");
            return ERROR_INPUT;
        }
    }

    // Too many dots / exp signs
    if (right_dot < 0 || right_exp < 0)
    {
        printf("ERROR: Too many allowed symbols\n");
        return ERROR_INPUT;
    }

    // If exp part is present and has more than 5 figures in it
    if (before_exp == FALSE && counter > SIZE_DEGREE - 1)
    {
        printf("ERROR: Too many figures in exp\n");
        return ERROR_INPUT;
    }

    // No sign is presented
    if (right_sign > 0)
    {
        if (right_exp == 1 && right_sign == 2)
        {
            printf("ERROR: Sign not specified\n");
            return ERROR_INPUT;
        }
    }

    #if DEBUG
        printf("Input is okay\n");
    #endif

    return ERROR_NONE;
}

// Used to extract degree from the input buff string
int char_to_num(char* num)
{
    float number = 0;
    // Power of 10
    int ten = 0;

    int remember_zero = 0;

    for (int i = 0; isdigit(num[i]) == TRUE; i++)
    {
        number += ((int)num[i] - '0') * pow(10, ten);

        if ((int)num[i] == '0')
            remember_zero++;
        else
            remember_zero = 0;

        ten++;
    }

    // For some reason int number gets broken
    // During string to int conversion
    // Probably precision issue but im not sure
    // So this is a clunky solution :(
    int new_number = (int)number;

    // Block above converts string to a number, but it ends up reversed
    // So we need to reverse it back
    int number_rev = 0;
    int remainder;
    
    while (new_number != 0)
    {
        remainder = new_number % 10;
        number_rev = number_rev * 10 + remainder;
        new_number /= 10;
    }

    number_rev *= pow(10, remember_zero);

    return number_rev;
}

// Moves one symbol at a time
// Copying symbols to destination
// This function just assumes that destination
// is larger than buffer
// Also does normalization of number
int char_to_char(char* buffer, number_t* num)
{
    int last_pos = 0;
    num->before_dot = 0;

    int after_dot = TRUE;

    for (int i = 0, k = 0; isdigit(buffer[i]) == TRUE || buffer[i] == '.'; i++)
    {
        if (buffer[i] == '.')
        {
            after_dot = FALSE;
            continue;
        }

        if (after_dot == TRUE)
            num->before_dot++;

        num->mantissa[k] = buffer[i];
        k++;
        last_pos = k;
    }

    // Adding termination symbol to preserve
    // Meaningful part
    num->mantissa[last_pos] = '\0';

    return last_pos + 1;
}

int convert_number(char* num, number_t* num_t)
{
    num_t->degree = 0;
    num_t->mantissa_sign = 1;
    int sign_checks = 2;
    int mantissa_converted = FALSE;
    int degree_sign = 1;
    for (int i = 0; i < SIZE_BUFF && num[i] != '\0'; i++)
    {
        if (num[i] == '+' || num[i] == '-')
        {
            switch(sign_checks)
            {
                // Mantissa sign
                case 2:
                    if (num[i] == '-')
                        num_t->mantissa_sign = -1;
                    break;
                // Degree sign
                case 1:
                    if (num[i] == '-')
                        degree_sign = -1;
                    break;
                default:
                    printf("This should not happen\n");
                    break;
            }

            sign_checks--;
        }

        
        if (isdigit(num[i]) == TRUE && mantissa_converted == FALSE)
        {
            i = char_to_char(&num[i], num_t);
            mantissa_converted = TRUE;
        }

        if (toupper(num[i]) == 'E')
        {
            if (num[i+1] == '+' || num[i+1] == '-')
                num_t->degree = char_to_num(&num[i+2]);
            else
                num_t->degree = char_to_num(&num[i+1]);
        }
    }

    num_t->degree = num_t->degree * degree_sign + num_t->before_dot;

    return ERROR_NONE;
}