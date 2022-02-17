#ifndef __LIST_STR__
#define __LIST_STR__

#define STACK_SIZE 5

typedef struct list_stack *LIST_STACK;
typedef struct list_node node_t;

// An element of stack
struct list_node
{
    int *address;
    int value;
    node_t *next;
};


typedef struct list_stack
{
    int curr_size;
    node_t *PS;
    node_t *root;
} list_stack_t;



#endif