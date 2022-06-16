/*

* NOME DO ALUNO: Fernando Mauadie da Silva Machado

* TIA: 32156944

* Faça uma função que retorne a posição de um dado caracter dentro de uma string.

*/

#include <stdio.h>
#include <stdlib.h>
int * encontrar_caracter(char a[],char busca[],int tam)
{
	static int pos [30];
	int i,b,c;
	b = 0;
	
	for(c = 0; c<30;c++)
	{
		pos[c] = -1;
	}
	
	for(i = 0; i<tam; i++)
	{
		if(a[i] == busca[0])
		{
			pos [b] = i;
			b++;
		}
	}
	return pos;
}

void main()
{
	int f;
	int * resultado;
	char teste[10] = "aasdasdvfs";
	char aux[1] = "a";
	resultado = encontrar_caracter(teste,aux,10);
	printf("posicoes do caracter escolhido: \n");
	for(f = 0;f<10;f++)
	{
		if(resultado[f] != -1)
		{
			printf("%d\n",resultado[f]);
		}
	}
}
