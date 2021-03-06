#ifndef __ARR_STR__
#define __ARR_STR__

#define STACK_SIZE 5

typedef struct arr_stack* ARR_STACK;

// Array stack descriptor
typedef struct arr_stack
{
    int *stack_ptr;
    
    int *stack;

    int *low_end;
    int *high_end;
} arr_stack_t;


#endif