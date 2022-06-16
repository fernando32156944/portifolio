/*

* NOME DO ALUNO: Fernando Mauadie da Silva Machado

* TIA: 32156944

* Crie um programa capaz de ler os dados de uma matriz quadrada de inteiros.
  Ao final da leitura o programa deverá imprimir o número da linha que contém o menor dentre todos os números lidos.
*/

#include <stdio.h>

int Menor_Elemento_Matriz(int tam1,int matriz[tam1][tam1])
{
	int L,i,menor,linha;
	linha = 0;
	menor = matriz[0][0];
	for(L = 0;L<tam1;L++)
	{
		for(i = 0;i<tam1;i++)
		{
			if(menor>matriz[L][i])
			{
				menor = matriz[L][i];
				linha = L;
			}
		}
	}
	return linha;
	
}

void main()
{
	int resultado;
	int matrix[3][3] = {53,64,13,56,100,79,62,74,2};
	resultado = Menor_Elemento_Matriz(3,matrix);
	printf("linha com o menor numero: %d",resultado);
}
