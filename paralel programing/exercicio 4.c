/*

* NOME DO ALUNO: Fernando Mauadie da Silva Machado

* TIA: 32156944

* Crie um progama capaz de ler dois nomes de pessoas e imprimi-los em ordem alfabética. Faça isto com string de C e de C++
  
  
  não consegui fazer pois não sei como transformar char em ascii da forma correta

*/

#include <stdio.h>
#include <string.h>

char comparar_nomes(char nome1 [],char nome2 [])
{
	int maior_tamanho,i,j;
	char resposta [strlen(nome1)+strlen(nome2)+3];
	
	i = 0;
	
	
	if(strlen(nome1)>strlen(nome2))
	{
		maior_tamanho = strlen(nome1);
	}
	else
	{
		maior_tamanho = strlen(nome2);
	}
	
	char maior [maior_tamanho];
	maior = nome1;
	
	while(i<maior_tamnaho && nome1[i]>nome2[i])
	{
		i++;
	}
	if(i == maior_tamanho)
	{
		for(j = 0;j<strlen(nome1),j++)
		{
			resposta[j] = nome1[j];
		}
		resposta[strlen(nome1)] = " ";
		resposta[strlen(nome1)+1] = ",";
		resposta[strlen(nome1)+2] = " ";
		for(j = strlen(nome1)+3;j<strlen(nome2),j++)
		{
			resposta[j] = nome2[j];
		}
	}
	else
	{
		for(j = 0;j<strlen(nome2),j++)
		{
			resposta[j] = nome2[j];
		}
		resposta[strlen(nome2)] = " ";
		resposta[strlen(nome2)+1] = ",";
		resposta[strlen(nome2)+2] = " ";
		for(j = strlen(nome2)+3;j<strlen(nome1),j++)
		{
			resposta[j] = nome1[j];
		}
	}
	print();
}


void main()
{
	comparar_nomes()
}
