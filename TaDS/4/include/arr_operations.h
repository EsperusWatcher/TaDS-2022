#ifndef __ARR_OP__
#define __ARR_OP__

#include "arr_structure.h"

ARR_STACK arr_init_stack();
int arr_push(int element, ARR_STACK stack);
int arr_pop(ARR_STACK stack);
void arr_print_stack(ARR_STACK stack);
int arr_top(ARR_STACK stack);
void arr_empty_stack(ARR_STACK stack);
void arr_free_stack(ARR_STACK *stack);
int arr_is_empty(ARR_STACK stack);

#endif