#ifndef __EFFICIENCY__
#define __EFFICIENCY__

#include "arr_structure.h"
#include "arr_operations.h"
#include "list_structure.h"
#include "list_operations.h"
#include "structure.h"

#define STACK_SIZE_TEST_1 50
#define STACK_SIZE_TEST_2 500
#define STACK_SIZE_TEST_3 10000

void measure_efficiency(ARR_STACK arr_stack, LIST_STACK l_stack);
void compare_stacks();


#endif