#ifndef STRUCTURE
    #include "structure.h"
    #define STRUCTURE
#endif

int char_to_num(char* num);
int char_to_char(char* buffer, number_t* num);
int convert_number(char* num, number_t* num_t);

int input_number(char* buffer);
int analyze_input(char* buffer);

void print_grid();
void print_scheme();