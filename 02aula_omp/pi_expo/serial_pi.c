#include <stdio.h>
#include <time.h>

static long num_steps = 100000;
double step;


void main(){
    int i;
    double x, pi, sum = 0.0;

    //time measure
    clock_t begin, end;
    double time;
    
    begin=clock();

    step = 1/(double)num_steps;

    for(i=0; i<num_steps;i++){
        x=(i+0.5)*step;
        sum = sum + 4.0/(1.0+x*x);
    }
    
    pi = step*sum;
    end=clock();
    
    //measuring final execution time
    time=(double)(end - begin)/CLOCKS_PER_SEC;

    printf("pi : %G \n", pi);
    printf("time spent : %f seconds\n or %f milliseconds\n", time, (time*1000));
}
