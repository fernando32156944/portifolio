/*

* NOME DO ALUNO: Fernando Mauadie da Silva Machado

* TIA: 32156944

* Crie uma função capaz de somar os elementos das linhas L1 e L2 de uma matriz. O resultado deve ser colocado na linha L2. 
  Faça o mesmo com a multiplicação..
*/

#include <stdio.h>

void somar(int tam1,int tam2, int matriz[tam1][tam2])
{
	int a,b,L,i,k;	
	for(i = 0;i<tam2;i++)
	{
		matriz[1][i] = matriz[0][i]+matriz[1][i];
	}
	for(L = 0; L<tam1; L++)
	{
		for(k = 0; k<tam2; k++)
		{
			printf("[%d]",matriz[L][k]);
		}
		printf("\n");
	}
		
}


void multiplicar(int tam1,int tam2, int matriz[tam1][tam2])
{
	int a,b,L,i,k;	
	for(i = 0;i<tam2;i++)
	{
		matriz[1][i] = matriz[0][i]*matriz[1][i];
	}
	for(L = 0; L<tam1; L++)
	{
		for(k = 0; k<tam2; k++)
		{
			printf("[%d]",matriz[L][k]);
		}
		printf("\n");
	}
		
}

void main()
{
	int matrix[3][3] = {53,64,13,56,100,79,62,74,2};
	somar(3,3,matrix);
	printf("\n");
	int matrix2[3][3] = {53,64,13,56,100,79,62,74,2};
	multiplicar(3,3,matrix2);
}
