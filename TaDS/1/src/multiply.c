#include "../include/multiply.h"

int char_to_int(char a)
{
    return (int)a - '0';
} 

int get_length(char* arr)
{
    int len = 0;
    for (int i = 0; arr[i] != '\0'; i++)
        len++;
    
    return len;
}

int check_number(number_t *num)
{
    int result = ERROR_NONE;
    for (int i = 0; num->mantissa[i] != '\0'; i++)
        if (i > SIZE_MANTISSA - 1)
        {
            round_number(num, SIZE_MANTISSA - 3, 0);
            num->mantissa[29] = '\0';
        }
    return result;
}

int round_number(number_t *num, int end, int flag)
{
    static int cycles = 0;

    int int_num = num->mantissa[end + 1] - '0';
    int int_num_cur = num->mantissa[end] - '0';

    if (flag)
        num->mantissa[end] = ((int_num_cur + 1) % 10) + '0';

    if (num->mantissa[end + 1] >= '5')
        num->mantissa[end] = ((int_num + 1) % 10) + '0';

    if (num->mantissa[end] == '0' && end != 0)
    {
        cycles++;
        round_number(num, --end, 1);
    }

    return cycles;
}

int multiplication(number_t *num1, number_t *num2, number_t *result)
{
    int num1_len = get_length(num1->mantissa);
    int num2_len = get_length(num2->mantissa);

    if (num1->mantissa_sign == num2->mantissa_sign)
        result->mantissa_sign = '+';
    else
        result->mantissa_sign = '-';

    result->degree = num1->degree + num2->degree;

    if (abs(result->degree) > MAX_DEGREE)
    {
        printf("ERROR: maximum degree overflow\n");
        return ERROR_OVERFLOW;
    }

    int* res = (int*)calloc(sizeof(int), SIZE_MANTISSA * 2); 
    int res_len = SIZE_MANTISSA * 2;

    // Pointers to keep track of res array
    int i_n1 = 0;
    int i_n2 = 0;

    int result_pos = 0;

    for (int i = num2_len - 1; i >= 0; i--)
    {
        int shift = 0;
        int n2 = char_to_int(num2->mantissa[i]);

        i_n2 = 0;

        for (int k = num1_len - 1; k >= 0; k--)
        {
            int n1 = char_to_int(num1->mantissa[k]);

            int sum = n1 * n2 + res[i_n1 + i_n2] + shift;

            shift = sum / 10;
            
            res[i_n1 + i_n2] = sum % 10;
            
            i_n2++;
        }

        if (shift > 0)
            res[i_n1 + i_n2] += shift;

        i_n1++;
    }

    // Ignoring unnecessary right zeroes
    int i = res_len - 1;
    while (i >= 0 && res[i] == 0)
        i--;

    if (i == -1)
    {
        printf("Multiplication error\n");
        return ERROR_OVERFLOW;
    }

    for (int k = i; k >= 0; k--)
    {
        result->mantissa[result_pos] = res[k] + '0';
        result_pos++;
    }

    result->mantissa[result_pos] = '\0';

    free(res);
    printf("OK_multy\n");
    return ERROR_NONE;
}