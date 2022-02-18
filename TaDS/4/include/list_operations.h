#ifndef __LIST_OP__
#define __LIST_OP__

#include "structure.h"

int list_init_stack(LIST_STACK *stack, int stack_size);
int list_push(LIST_STACK stack, int value);
int list_pop(LIST_STACK stack);
void list_empty_stack(LIST_STACK stack);
int list_is_stack_empty(LIST_STACK stack);
void list_free_stack(LIST_STACK *stack);
int list_top(LIST_STACK stack);
void list_show_stack(LIST_STACK stack);
void list_fill_stack(LIST_STACK stack);
void list_stack_size(LIST_STACK stack, size_t *size);
void list_reverse_asc_arr();

#endif