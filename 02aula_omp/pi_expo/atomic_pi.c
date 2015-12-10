#include <stdio.h>
#include <omp.h>
#include <time.h>

static long num_steps = 100000; double step;
#define NUM_THREADS 4

void main (){
    int nthreads;
    double pi; step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    double ex_time;
    clock_t begin, end;

    #pragma omp parallel
    {
        int i, id,nthrds; double x, sum;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        
        if (id == 0){ 
            nthreads = nthrds;
        }

        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        
        for (i=id, sum=0.0;i< num_steps; i=i+nthreads){
            x = (i+0.5)*step;
            sum += 4.0/(1.0+x*x);
        }
        
        sum = sum*step;
        
        #pragma atomic
        pi += sum ;
     }

    end=clock();
    ex_time=(double)(end - begin)/CLOCKS_PER_SEC;
    printf("time spent : %f seconds\n or %f milliseconds\n", ex_time, (ex_time*1000));
    printf("pi = %G\n",pi);
}
