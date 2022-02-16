#include "../include/arr_structure.h"
#include "../include/arr_operations.h"
#include "../include/structure.h"

ARR_STACK arr_init_stack()
{
    ARR_STACK stack;

    stack = (ARR_STACK)malloc(sizeof(arr_stack_t));
    
    if (stack == NULL)
    {
        printf("ERROR: arr stack creation memory error\n");
        return NULL;
    }

    stack->stack = (int *)malloc(sizeof(int) * STACK_SIZE);

    if (stack->stack == NULL)
    {
        printf("ERROR: arr stack creation memory error\n");
        return NULL;
    }

    // At the start
    stack->low_end = &stack->stack;
    stack->stack_ptr = stack->stack;
    // One element "above" stack
    stack->high_end = &stack->stack;

    for (int i = 0; i < STACK_SIZE + 1; i++)
        stack->high_end++;

    stack->size = 0;

    return stack;
}

// Adding new element into the arr stack
int arr_push(int element, ARR_STACK stack)
{
    stack->stack_ptr++;

    if (stack->stack_ptr == *stack->high_end)
    {
        printf("ERROR: stack overflow\n");
        return ERROR_OVERFLOW;
    }

    *stack->stack_ptr = element;

    return ERROR_NONE;
}

// Removes value from stack and returns it
//TODO Fix this
int arr_pop(ARR_STACK stack)
{
    if (stack->stack_ptr == *stack->low_end)
        printf("The stack is empty\n");
    else
    {
        int ret = *stack->stack_ptr;
        
        stack->stack_ptr--;

        return ret;
    }    
}

void arr_print_stack(ARR_STACK stack)
{
    if (stack->stack_ptr == *stack->low_end)
    {
        printf("The stack is empty\n");
        return;
    }

    int *scroll;
    scroll = ++*stack->low_end;

    printf("ARR STACK:\n");
    while(scroll <= stack->stack_ptr)
    {
        printf("%d\n", *scroll);
        scroll++;
    }
}

int arr_is_empty(ARR_STACK stack)
{
    if (stack->stack_ptr == *stack->low_end)
        return TRUE;
    
    return FALSE;
}

int arr_top(ARR_STACK stack)
{
    if (stack->stack_ptr == *stack->low_end)
    {
        printf("The stack is empty\n");
        return 0;
    }

    return *stack->stack_ptr;
}

void arr_empty_stack(ARR_STACK stack)
{
    while (stack->stack_ptr != *stack->low_end)
        arr_pop(stack);
    printf("The stack emptied successfully\n");
}

void arr_free_stack(ARR_STACK *stack)
{
    free((*stack)->stack);
    free(*stack);
}