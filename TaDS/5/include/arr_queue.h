#ifndef __ARR_QUE__
#define __ARR_QUE__

#include "structure.h"

#define SIZE_ARR_QUE 100

typedef struct arr_queue
{
    // Current queue size
    int queue_size;

    request_t *p_in;
    request_t *p_out;

    request_t *queue;
} arr_que_t;

typedef arr_que_t* ARR_QUEUE;

#endif