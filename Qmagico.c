/*Fazer um programa que leia uma matriz de 5 linhas x 5 colunas e escreva 1 se a mesma é um quadrado mágico ou 0 caso contrário. 
Uma matriz é um quadrado mágico se a soma dos elementos de cada linha, 
a soma dos elementos de cada coluna e a soma dos elementos das diagonais principal e secundária são todas iguais.  
No exemplo da matriz de 4 linhas por 4 colunas a seguir, todas as somas totalizam 34. Por isso, ela pode ser definida como um quadrado mágico. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 100

void escreve(int m[N][N])
{
    srand(time(NULL));
    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++) 
        {
            m[i][j]=rand()%M;
            //printf("M[%d][%d]: ",i,j);
            //scanf("%d", &m[i][j]);
        }
    }
}

void mostra(int m[N][N])
 {
    int i,j;

     for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
 }

 int calcula(int m[N][N])
 {
    int i,j;
    int lin,col,diaP,diaS;

    for(i=0;i<N;i++)
    {
        lin=0;
        col=0;
        diaP=0;
        diaS=0;
        for(j=0;j<N;j++)
        {
            if(i==j) diaP+=m[i][j];
            diaS+=m[i][N-j];
            lin+=m[i][j];
            col+=m[j][i];
        }
        if(lin!=col && diaP!=diaS && lin!=diaS) return 0;
    }
    return 1;
 }

int main ()
{
    int mat[N][N];

    escreve(mat);
    mostra(mat);

    if(calcula(mat)) printf("\n 1 - quadrado magico");
    else printf("\n 0 - NAO quadrado magico");
}
