#ifndef __LIST__
#define __LIST__

#include "structure.h"

int initialize_IA_list(list_t *list);
void print_list_IA(list_t *list);
void free_list(list_t *list);
int add_node(list_t *list, int value);
int value_by_index(list_t *list, int index);
size_t get_list_size(list_t *list);
#endif