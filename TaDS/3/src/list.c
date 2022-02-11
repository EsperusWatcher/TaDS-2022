#include "../include/list.h"

// Initializing root of the list and setting 
// First pointer to NULL
int initialize_IA_list(list_t *list)
{
    list->root = (node_t *)malloc(sizeof(node_t));
    list->root->next = NULL;

    if (list->root == NULL)
    {
        printf("Memory error initializing IA list\n");
        return ERROR_MEMORY;
    }

    list->root->start_row_ind = 0;

    return ERROR_NONE;
}

int value_by_index(list_t *list, int index)
{
    node_t *point = list->root;

    while (point != NULL)
    {
        if (point->index == index)
            return point->start_row_ind;

        point = point->next;
    }

    return FALSE;
}

void free_list(list_t *list)
{
    node_t *point = list->root;
    node_t *tmp;

    while (point != NULL)
    {
        tmp = point;
        point = point->next;
        free(tmp);
    }

    printf("list mem OK\n");
}

int add_node(list_t *list, int value)
{
    node_t* point = list->root;

    // counts amount of nodes before we insert the new one
    // Then this value is assigned as node number to it
    int counter = 0;
    
    // Cycling through list to get to its end
    while (point->next != NULL)
    {
        counter++;
        point = point->next;
    }

    // Add a new node and value
    point->next = (node_t *)malloc(sizeof(node_t));

    if (point->next == NULL)
    {
        printf("Memory error adding new node\n");
        return ERROR_MEMORY;
    }

    point->next->start_row_ind = value;
    point->next->index = counter;

    // Marking new node's next pointer as the end of list
    point->next->next = NULL;

    return ERROR_NONE;
}