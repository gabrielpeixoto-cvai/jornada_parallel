#include <omp.h>
#define CHUNKSIZE 10
#define N     100

void main ()  
{

    int i, chunk;
    float a[N], b[N], c[N];

    /* Some initializations */
    for (i=0; i < N; i++)
          a[i] = b[i] = i * 1.0;
    chunk = CHUNKSIZE;

#pragma omp parallel shared(a,b,c,chunk) private(i)
      {

            #pragma omp for schedule(dynamic,chunk) nowait
            for (i=0; i < N; i++){
                    c[i] = a[i] + b[i];
                    printf("%f\n",c[i]);
                  }

              }  /* end of parallel section */  
}     