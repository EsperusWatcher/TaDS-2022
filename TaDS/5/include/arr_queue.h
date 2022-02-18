#ifndef __ARR_QUE__
#define __ARR_QUE__

#include "structure.h"

struct arr_queue
{
    request_t *Pin;
    request_t *Pout;

    request_t *Queue;
};


#endif