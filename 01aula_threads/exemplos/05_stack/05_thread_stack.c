#include <pthread.h>
#include <stdio.h>
#define NTHREADS 4
#define N 1000
#define MEGEXTRA 1000000
 
pthread_attr_t attr;
 
//funcao da thread
void *dowork(void *threadid){

    double A[N][N];
    int i,j;
    long tid;
    size_t mystacksize;

    tid = (long)threadid;
    pthread_attr_getstacksize (&attr, &mystacksize);
    printf("Thread %ld: stack size = %li bytes \n", tid, mystacksize);
                            
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            A[i][j] = ((i*j)/3.452) + (N-i);
            pthread_exit(NULL);
}
 
void main(){
       
    pthread_t threads[NTHREADS];
    size_t stacksize;
    int rc;
    long t;
    
    //usa o atributo global para saber informac;oes de stack da thread
    pthread_attr_init(&attr);
    //tamnho de stack total
    pthread_attr_getstacksize (&attr, &stacksize);
    printf("Default stack size = %li\n", stacksize);
    //calcula quanto stack cada thread precisa
    stacksize = sizeof(double)*N*N+MEGEXTRA;
    printf("Amount of stack needed per thread = %li\n",stacksize);
    //seta o tamanho de stack necessario pra executar todas as threads
    pthread_attr_setstacksize (&attr, stacksize);
    printf("Creating threads with stack size = %li bytes\n",stacksize);
    
    //cria as threads
    for(t=0; t<NTHREADS; t++){
        rc = pthread_create(&threads[t], &attr, dowork, (void *)t);
        if(rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    printf("Created %ld threads.\n", t);
    pthread_exit(NULL);
}
