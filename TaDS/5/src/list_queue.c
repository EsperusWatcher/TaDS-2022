#include "../include/list_queue.h"

int list_init_que(LIST_QUEUE *queue)
{
    *queue = (LIST_QUEUE)malloc(sizeof(l_queue_t));

    if (queue == NULL)
        return ERROR_MEMO;

    (*queue)->root = (node_t *)malloc(sizeof(node_t));
    
    if ((*queue)->root == NULL)
        return ERROR_MEMO;

    (*queue)->root->next = NULL;

    return ERROR_NONE;    
}

int list_push_que(LIST_QUEUE queue);