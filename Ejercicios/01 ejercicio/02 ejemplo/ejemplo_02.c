
/*                                          EJERCICIO 1
 *  Ejemplo 2
 *  Usando la API(OpenMP) hacer un programa que realice lo siguiente:
 * 	    -   Crear la Matrix A de 50 columnas x 50 filas (50x50), inicializada con valores aleatorios. [✔]
*/

//  Librerias
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

//  Definiciones
#define CHUNKSIZE   10
#define N       10
#define NRA 5               //  numero de filas en matrix A
#define NCA 5               //  numero de columnas en matrix A


//  Metodo para obtener numeros random
long Random(long li, long ls)
{
    long n;
    n=li+rand()%(ls-li+1);
    return n;
}

//  Ejecucion del programa
int main (int argc, char *argv[]) {

    int     i, j;
    double	mA[NRA][NCA];

//  Establece el numero de subprocesos en las proximas regiones paralelas
omp_set_num_threads(2);

//  Directiva con constructor PARALLEL FOR con clausula SCHEDULE
#pragma omp parallel for schedule( static,10)

    for (i=0; i<NRA; i++)
    {
        for (j=0; j<NCA; j++)
        {
            //  Creacion de Matrix A con numeros aleatorios
            mA[i][j]= Random(1,20);
		}
	}

    //  Impresion de Matrix A
	printf("******************************************************\n");
	printf("Matrix A:\n");
	for (i=0; i<NRA; i++)
	{
        for (j=0; j<NCA; j++)
        {
            printf("%6.2f   ", mA[i][j]);
        }
        printf("\n");
	}

}   //  Fin main
