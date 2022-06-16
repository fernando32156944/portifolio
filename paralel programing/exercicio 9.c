/*

* NOME DO ALUNO: Fernando Mauadie da Silva Machado

* TIA: 32156944

* Crie uma função capaz de substituir todos os números negativos de uma matriz por seu módulo.
*/
#include <stdio.h>


void Modulos(int tam1,int tam2, int matriz[tam1][tam2])
{
    int L,i,j,k,a;
    
    for(L = 0;L<tam1;L++)
    {
        for(i = 0;i<tam2;i++)
        {
            if(matriz[L][i]<0)
            {
                matriz[L][i] = matriz[L][i]*-1;
            }
        }
    }
    printf("nova matriz\n");
    for(j = 0;j<tam1;j++)
    {
        for(k = 0;k<tam2;k++)
        {
            printf("[%d] ",matriz[j][k]);
        }
        printf("\n");
    }
    
    
}

void main()
{
    int matriz[3][3] = {53,64,13,-56,2,79,-62,74,86};
    Modulos(3,3, matriz);
}
