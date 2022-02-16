#ifndef __LIST_STR__
#define __LIST_STR__

#define MAX_STACK_SIZE 256

typedef struct list_node node_t;

// An element of stack
struct list_node
{
    int value;
    node_t *next;
};


typedef struct list_stack
{
    node_t *PS;
    node_t *root;
} list_stack_t;



#endif