#include "../include/arr_operations.h"
#include "../include/arr_queue.h"

int arr_init_que(ARR_QUEUE *queue)
{
    *queue = (ARR_QUEUE)malloc(sizeof(arr_que_t));
    
    if (queue == NULL)
        return ERROR_MEMO;

    (*queue)->queue_size = 0;
    (*queue)->queue = (request_t *)malloc(sizeof(request_t) * SIZE_ARR_QUE);

    if ((*queue)->queue == NULL)
        return ERROR_MEMO;

    (*queue)->p_in = (*queue)->queue;
    (*queue)->p_out = (*queue)->queue;

    return ERROR_NONE;
}

int arr_free_que(ARR_QUEUE *queue)
{
    free((*queue)->queue);

    if (*queue != NULL)
        free(*queue);
    else
        return ERROR_MEMO;

    return ERROR_NONE;
}

// Check if queueu is full
// TRUE - full
// FALSE - not full
int arr_queue_is_full(ARR_QUEUE queue)
{
    if (queue->queue_size == SIZE_ARR_QUE)
        return TRUE;


    printf("not full\n");
    return FALSE;
}

int arr_queue_is_empty(ARR_QUEUE queue)
{
    return queue->queue_size == 0;
}

extern request_t generate_request(param_t serv_params);
int arr_push_que(ARR_QUEUE queue, param_t serv_params)
{
    // Check if Queue is full
    if (arr_queue_is_full(queue))
    {
        printf("Overflow\n");
        CLS_PAUSE;
        return ERROR_OVFL;
    }

    // Here we generate random values for Request element
    // T1 & T2, then add it into the que
    *queue->p_in = generate_request(serv_params);

    // Used only in testing
    (*queue->p_in).index = rand() % 10;

    queue->p_in++;

    queue->queue_size++;

    // Check if Queue has moved over its bounds
    // If it did, move Pin to the beginning of queue
    if (queue->p_in == (queue->queue + sizeof(request_t) * (SIZE_ARR_QUE - 1)))
    {
        queue->p_in = queue->queue;
        printf("moved\n");
    }
    return ERROR_NONE;
}

request_t arr_pop_que(ARR_QUEUE queue)
{
    request_t ret = *queue->p_out;

    queue->p_out++;

    queue->queue_size--;

    // If pointer goes above queueu border
    // Reassign it to the beginning of queue
    if (queue->p_out == (queue->queue + sizeof(request_t) * (SIZE_ARR_QUE - 1)))
        queue->p_out = queue->queue;

    return ret;
}

// Only in testing to display elements of the queue
void arr_show_queue(ARR_QUEUE queue)
{
    request_t *scroll = queue->p_out;

    while(scroll != queue->p_in)
    {
        printf("Index: %d\n", (*scroll).index);
        printf("T1 time: %lf\n", (*scroll).service_time_1);
        printf("T2 time: %lf\n", (*scroll).service_time_1);
        printf(" --------------- \n");
        scroll++;

        if (scroll >= (queue->queue + sizeof(request_t) * SIZE_ARR_QUE))
            scroll = queue->queue;
    }
}