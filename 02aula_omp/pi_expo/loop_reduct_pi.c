#include <stdio.h>
#include <omp.h>
#include <time.h>

static long num_steps = 100000; double step;

void main(){ 
    int i; double x, pi, sum = 0.0;
    step = 1.0/(double) num_steps;

    double ex_time;
    clock_t begin, end;

    begin=clock();
    
    #pragma omp parallel
    {
        double x;
        
        #pragma omp for reduction(+:sum)
        for (i=0;i< num_steps; i++){
            x = (i+0.5)*step;
            sum = sum + 4.0/(1.0+x*x);
        }
    }
    pi = step * sum;

    end=clock();
    ex_time=(double)(end - begin)/CLOCKS_PER_SEC;
    printf("time spent : %f seconds\n or %f milliseconds\n", ex_time, (ex_time*1000));
    printf("pi = %G\n",pi);
}
