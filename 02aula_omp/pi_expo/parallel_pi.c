#include <stdio.h>
#include <omp.h>
#include <time.h>

static long num_steps = 100000;
#define NUM_THREADS 400

void main(){
    int i, nthreads;
    double pi, step, sum [NUM_THREADS];
    double ex_time;
    clock_t begin, end;

    step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    omp_set_dynamic(0);
    
    begin=clock();
    #pragma omp parallel
    {
        int i, id,nthrds;
        double x;
        
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        
        if (id == 0){
            nthreads = nthrds;
        }

        for (i=id, sum[id]=0.0;i< num_steps; i=i+nthrds) {
            x = (i+0.5)*step;
            sum[id] += 4.0/(1.0+x*x);
        }
    }
    
    for(i=0, pi=0.0;i<nthreads;i++){
        pi += sum[i] * step;
    }
    end=clock();
    ex_time=(double)(end - begin)/CLOCKS_PER_SEC;
    printf("time spent : %f seconds\n or %f milliseconds\n", ex_time, (ex_time*1000));
    printf("pi = %G\n",pi);
}
