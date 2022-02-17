#include "../include/structure.h"
#include "../include/arr_structure.h"
#include "../include/arr_operations.h"

ARR_STACK arr_init_stack(int stack_size)
{
    ARR_STACK stack;

    stack = (ARR_STACK)malloc(sizeof(arr_stack_t));
    
    if (stack == NULL)
    {
        printf("ERROR: arr stack creation memory error\n");
        return NULL;
    }

    stack->stack = (int *)malloc(sizeof(int) * stack_size);

    if (stack->stack == NULL)
    {
        printf("ERROR: arr stack creation memory error\n");
        return NULL;
    }

    // At the start
    stack->low_end = stack->stack;
    stack->stack_ptr = stack->stack;
    // One element "above" stack
    stack->high_end = stack->stack;

    for (int i = 0; i < stack_size; i++)
        stack->high_end++;

    return stack;
}

// Adding new element into the arr stack
int arr_push(int element, ARR_STACK stack)
{
    if (stack->stack_ptr == stack->high_end)
        return ERROR_OVERFLOW;

    stack->stack_ptr++;

    *stack->stack_ptr = element;

    return ERROR_NONE;
}

void arr_fill_stack(ARR_STACK stack)
{
    while(stack->stack_ptr != stack->high_end)
    {
        arr_push(rand() % 10, stack);
    }
}

// Removes value from stack and returns it
int arr_pop(ARR_STACK stack)
{
    int ret = *stack->stack_ptr;

    stack->stack_ptr--;

    return ret;
}

void arr_print_stack(ARR_STACK stack)
{
    int *scroll;
    scroll = stack->stack_ptr;

    printf("[ ARR STACK ]:\n");
    while(scroll >= stack->low_end + 1)
    {
        printf("      %d\n", *scroll);
        scroll--;
    }
}

int arr_is_empty(ARR_STACK stack)
{
    if (stack->stack_ptr == stack->low_end)
        return TRUE;
    
    return FALSE;
}

int arr_top(ARR_STACK stack)
{
    return *stack->stack_ptr;
}

void arr_empty_stack(ARR_STACK stack)
{
    while (stack->stack_ptr != stack->low_end)
        arr_pop(stack);
}

void arr_free_stack(ARR_STACK *stack)
{
    free((*stack)->stack);
    free(*stack);
}