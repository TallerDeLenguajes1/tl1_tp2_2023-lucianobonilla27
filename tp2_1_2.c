#include <stdio.h>
#define N 20

void inicializar(double *vt){
   for (int i = 0; i < N; i++)
   {
     *vt = 1+rand()%100;
     printf("%.2f\n", *vt);
     vt++;
   }
   

}

int main()
{
   int i;
    double vt[N];

    inicializar(vt);

    
    return 0;
}
