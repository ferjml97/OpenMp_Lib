
/*                                          EJERCICIO 2
 *  Usando la API(OpenMP) hacer un programa que realice lo siguiente:
 * 	    -   Crear la Matrix A de 50 columnas x 50 filas (50x50), inicializada con valores aleatorios.   [✔]
 *      -   Realizar la Transpuesta de la Matrix A.                                                     [✔]
 * 	    -   Obtener la suma de cada renglón de la Matriz Transpuesta de A y guardarlo en un vector.     [✔]
 * 	    -   Devolver el maximo valor del vector anterior y el renglón.                                  [✔]
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

    int     i,z, j,n, f;
    double  mA[NRA][NCA];
    double	mAT[NRA][NCA];
    double sum = 0;
    double mayor =0;
    int u = 1;
    double h[5];

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
           //  Las transpuesta de la Matrix A
            mAT[j][i] = mA[i][j];
		}
	}

    //  Impresion de Matrix A
	printf("******************************************************\n");
	printf(" Matrix A:\n");
	for (i=0; i<NRA; i++)
	{
        for (j=0; j<NCA; j++)
        {
            printf("%6.2f   ", mA[i][j]);
        }
        printf("\n");
	}

	//  Impresion Transpuesta Matrix A
    printf("******************************************************\n");
	printf(" Matrix Transpuesta de A:                     Total\n");
	for (j=0; j<NRA; j++)
	{
        for (i=0; i<NCA; i++)
        {
            printf("%6.2f   ", mAT[j][i]);
            sum = sum + mAT[j][i];  //  Sumatoria
        }
        printf("%6.2f",sum);
        if(j < NRA) // Mayor renglon
        {
            h[j] = sum;
            if( h[j] > mayor)
            {
                mayor = h[j];
                f = j;
            }
        }
        u ++;
        sum = 0;
        printf("\n");
	} //    Fin if
    printf("\n Mayor renglon: %d con sumatoria de: %6.2f \n", f, mayor);

}   //  Fin main
