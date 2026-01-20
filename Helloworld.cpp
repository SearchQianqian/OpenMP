#include <iostream>
#include <omp.h>
#define qianqian main

int qianqian()
{

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int total = omp_get_num_threads();
        if (id == 0)
        {
            printf("The total thread for this task is %d\n", total);
        }
#pragma omp for
        for (int i = 0; i < 8; i++)
        {
            printf("Thread %d take the task i = %d\n", id, i);
        }
    }
    return 0;
}