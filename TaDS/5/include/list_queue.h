#ifndef __LIST_QUE__
#define __LIST_QUE__

#include "structure.h"

#define SIZE_LIST_QUE 100;

typedef struct list_node node_t;

struct list_node
{
    request_t Request;
    node_t *next;
};


typedef struct list_queue
{
    int max_size;
    node_t *root;
} l_queue_t;

typedef l_queue_t* LIST_QUEUE;

#endif