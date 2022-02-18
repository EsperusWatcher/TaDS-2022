#ifndef __ARR_OP__
#define __ARR_OP__

#include "arr_queue.h"

// Functions
int arr_init_que(ARR_QUEUE *queue);
int arr_queue_is_full(ARR_QUEUE queue);
int arr_queue_is_empty(ARR_QUEUE queue);
int arr_push_que(ARR_QUEUE queue, param_t serv_params);
request_t arr_pop_que(ARR_QUEUE queue);
void arr_show_queue(ARR_QUEUE queue);
int arr_free_que(ARR_QUEUE *queue);

#endif