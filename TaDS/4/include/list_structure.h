#ifndef __LIST_STR__
#define __LIST_STR__

#define STACK_SIZE 5

#define FREE_ADDRESS_STORAGE 50

typedef struct list_stack *LIST_STACK;
typedef struct list_node node_t;

// An element of stack
struct list_node
{
    int *address;
    int value;
    node_t *next;
};

typedef struct free_addresses
{
    int *free_addresses[FREE_ADDRESS_STORAGE];
    int last_index;
} address_t;

typedef struct list_stack
{
    int curr_size;
    node_t *PS;
    node_t *root;
} list_stack_t;



#endif