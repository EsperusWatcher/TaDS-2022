#ifndef __LIST_QUE__
#define __LIST_QUE__

#include "structure.h"

typedef struct list_node node_t;

struct list_node
{
    request_t Request;
    node_t *next;
};


typedef struct list_queue
{
    node_t *root;
} l_queue_t;


#endif