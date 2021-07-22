
/*                                          EJERCICIO 5
 *  Elaborar un programa con OpenMP para calcular el factorial de 15 usando sections.       [✔]
 * 	-   Cada thread calcula un subrango:
 *      Usar 3 threads: T0 = 1-5
 *                      T1 = 6-10
 *                      T2 = 11-15
*/

//  Librerias
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

//  Definiciones
#define CHUNKSIZE   10
#define N       10

//  Ejecucion main
int main (int argc, char *argv[]) {

    int nthreads, tid, i, chunk;

//  Inicialisaciones
    chunk = CHUNKSIZE;
//  Establece el numero de subprocesos en las proximas regiones paralelas
    omp_set_num_threads(3);

    //  Directiva con constructor PARALLEL con clausula SCHEDULE
    #pragma omp parallel shared(nthreads,chunk) private(i,tid)
        {
        tid = omp_get_thread_num();
        int d = 1;

        if (tid == 0)
        {
            nthreads = omp_get_num_threads();
            printf(" Numero de threads = %d\n", nthreads);
        }
        printf("\n Thread %d empezando...\n",tid);

        #pragma omp for schedule(static,chunk)
            for(int b =1; b<=5; b++)
            {	int c = 1;
                 d=d*b;
                int n = d*b;
                printf("\n El factorial de %d es %d ",b,d);
            }
            printf("\n");

        #pragma omp for schedule(static,chunk)
            for(int b =6; b<=10; b++)
            {	int c = 1;
                 d=d*b;
                int n = d*b;
                printf("\n El factorial de %d es %d ",b,d);
            }
            printf("\n");

        #pragma omp for schedule(static,chunk)
            for(int b =11; b<=15; b++)
            {	int c = 1;
                 d=d*b;
                int n = d*b;
                printf("\n El factorial de %d es %d ",b,d);
            }
            printf("\n");

    }// Fin de sección PARALLEL

}   //  Fin main
