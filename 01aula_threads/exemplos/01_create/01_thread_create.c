#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

void *threadTask(void *threadid){
       
    long tid;
    tid = (long)threadid;
             
    printf("thread no:#%ld!\n", tid);
    pthread_exit(NULL);
}

void main(){
    
    //cria uma variavel thread
    pthread_t threads[NUM_THREADS];

    int rc;
    long t;
    
    for(t=0;t<NUM_THREADS;t++){
        printf("Na main: criando thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, threadTask, (void *)t);
        if (rc){
            printf("ERROR; pthread_create() retornou o erro %d\n", rc);
            exit(-1);
        }
    }

    /* ultima coisa que a main deve fazer */
    pthread_exit(NULL);
}
