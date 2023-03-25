#include <stdio.h>
#define N 5
#define M 7

void inicializar(int *mt){
    int i,j;
   
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            *mt = 1+rand()%100;
            printf("%d ", *mt);
            
        }
        printf("\n");
        
    }
    
}



int main()
{
    int i,j;
    int mt[N][M];
    
    inicializar(mt);

   /* for(i = 0;i<N; i++)
    {
    for(j = 0;j<M; j++)
    {
    mt[i][j]=1+rand()%100;
    printf("%d ", mt[i][j]);
    }
    printf("\n");
    }*/

    return 0;
}
