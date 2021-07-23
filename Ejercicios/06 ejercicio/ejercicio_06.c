
/*                                          EJERCICIO 6
 *  Hacer un programa en OpenMP que resuelva la siguiente ecuación: y=x3+5x-30 para x de -100 a 100.
 * 	-   Encuentrar el número de raices usando 4 threads con parallel sections.                          [✔]
*/

//  Librerias
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//  Ejecucion main
int main (int argc, char *argv[]) {

    int    r=0;
    int tid, nthreads;
    float x,y,yant=0,yact=0;

//  Establece el numero de subprocesos en las proximas regiones paralelas
omp_set_num_threads(4);

    //  Directiva con constructor PARALLEL con clausula SCHEDULE
    #pragma omp parallel sections private (x,y,yant,yact,tid,nthreads) reduction(+:r)
    {
        //  Devuelve el número de subproceso del subproceso que se ejecuta dentro de su equipo de subprocesos.
        tid = omp_get_thread_num();

        #pragma omp section
        {
            printf(" Thread =%d\n",tid);
            for (x=-100; x <= -51; x+=0.1)
            {
                y=sin(((x*x)/5)/x)*-3;
                yact=y/fabs(y);
                if(x==-100)	yant=yact;

                if (yact!=yant) {   r++; printf(" RAIZ | ");   };
                printf(" x= %2.2f y= %2.2f yant= %2.2f yact= %2.2f\n",x,y,yant,yact);
                yant=yact;
            }
        }

        #pragma omp section
        {
            printf(" Thread =%d\n",tid);
            for (x=-50; x <= 0; x+=0.1)
            {
                y=sin(((x*x)/5)/x)*-3;
                yact=y/fabs(y);
                if(x==-50)	yant=yact;

                if (yact!=yant) {   r++; printf(" RAIZ | ");   };
                printf(" x= %2.2f y= %2.2f yant= %2.2f yact= %2.2f\n",x,y,yant,yact);
                yant=yact;
            }
        }

        #pragma omp section
        {
            printf(" Thread =%d\n",tid);
            for (x=0.2; x <= 50; x+=0.1)
            {
                y=sin(((x*x)/5)/x)*-3;
                yact=y/fabs(y);
                if(x==0.2)	yant=yact;

                if (yact!=yant) {   r++; printf(" RAIZ | ");   };
                printf(" x= %2.2f y= %2.2f yant= %2.2f yact= %2.2f\n",x,y,yant,yact);
                yant=yact;
            }
        }

        #pragma omp section
        {
            printf(" Thread =%d\n",tid);
            for (x=51; x <= 100; x+=0.1)
            {
                y=sin(((x*x)/5)/x)*-3;
                yact=y/fabs(y);
                if(x==51)	yant=yact;

                if (yact!=yant) {   r++; printf(" RAIZ | ");   };
                printf(" x= %2.2f y= %2.2f yant= %2.2f yact= %2.2f\n",x,y,yant,yact);
                yant=yact;
            }
        }
    }   // Fin PARALLEL SECTIONS

    printf("\n Numero de raices = %d\n",r);
}   //  Fin main
