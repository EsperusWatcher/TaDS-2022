#include "../include/structure.h"
#include "../include/list_structure.h"
#include "../include/list_operations.h"

address_t freed_mem;

int list_init_stack(LIST_STACK *stack, int stack_size)
{
    *stack = (LIST_STACK)malloc(sizeof(list_stack_t));

    if (*stack == NULL)
        return ERROR_MEMORY;

    (*stack)->root = (node_t *)malloc(sizeof(node_t));

    if ((*stack)->root == NULL)
        return ERROR_MEMORY;

    (*stack)->curr_size = 0;

    (*stack)->root->address = (int *)&(*stack)->root;

    (*stack)->root->next = NULL;

    (*stack)->PS = (*stack)->root;

    (*stack)->max_size = stack_size;

    freed_mem.last_index = 0;

    return ERROR_NONE;
}

void list_stack_size(LIST_STACK stack, size_t *size)
{
    size_t result = 0;

    node_t *tmp = stack->root->next;

    while(tmp != NULL)
    {
        result += (sizeof(node_t) - sizeof(int *));
        tmp = tmp->next;
    }

    *size += result;
}

int list_push(LIST_STACK stack, int value)
{
    if (stack->curr_size == stack->max_size)
        return ERROR_OVERFLOW;

    node_t *tmp = stack->root;

    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = (node_t *)malloc(sizeof(node_t));

    if (tmp->next == NULL)
        return ERROR_MEMORY;

    tmp->next->address = (int *)&tmp->next;
    tmp->next->value = value;
    tmp->next->next = NULL;

    stack->PS = tmp->next;

    stack->curr_size++;

    return ERROR_NONE;
}

void save_memory_info(int *mem_address)
{
    int save_flag = TRUE;
    if (freed_mem.last_index < FREE_ADDRESS_STORAGE - 1)
    {
        for (int i = 0; i < freed_mem.last_index; i++)
            if (mem_address == freed_mem.free_addresses[i])
                save_flag = FALSE;
        
        if (save_flag == TRUE)
        {
            freed_mem.free_addresses[freed_mem.last_index] = mem_address;
            freed_mem.last_index++;
        }
    }
}

int list_pop(LIST_STACK stack)
{
    node_t *tmp1 = stack->root;
    node_t *tmp2 = NULL;

    while(tmp1->next != NULL)
    {
        tmp2 = tmp1;
        tmp1 = tmp1->next;
    }

    int ret = tmp1->value;

    save_memory_info(tmp1->address);

    free(tmp1);

    stack->curr_size--;

    if (tmp2 != NULL)
    {
        stack->PS = tmp2;
        tmp2->next = NULL;
    }

    return ret;
}

void list_empty_stack(LIST_STACK stack)
{
    while (stack->curr_size > 0)
        list_pop(stack);
}

int list_is_stack_empty(LIST_STACK stack)
{
    return (stack->root->next == NULL);
}

void list_free_stack(LIST_STACK *stack)
{
    list_empty_stack(*stack);
    free((*stack)->root);
    free(*stack);
}

int list_top(LIST_STACK stack)
{
    return stack->PS->value;
}

// Fills stack to full with random values
void list_fill_stack(LIST_STACK stack)
{
    while(stack->curr_size < stack->max_size)
    {
        list_push(stack, rand() % 10);
    }
}

void list_show_stack(LIST_STACK stack)
{
    node_t *tmp = stack->root->next;
    
    printf("[ LIST STACK ]: \n");
    while(tmp != NULL)
    {
        printf("       %d (%p)\n", tmp->value, tmp->address);
        tmp = tmp->next;
    }

    printf("\n");
    printf("PREVIOUSLY USED MEM: ");
    for (int i = 0; i < freed_mem.last_index; i++)
        printf("%p ", freed_mem.free_addresses[i]);
    printf("\n");
}
