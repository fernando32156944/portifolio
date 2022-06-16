/*
Nome: Fernando Mauadie da Silva Machado
TIA: 32156944

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome [20];
    int idade;
    float altura;
}PESSOA;


void insertion_sort_pessoas(PESSOA Lista[],int p)
{
	int x,z;
	float t;
	x = 1;
	PESSOA temp;
	
	for(x = 1; x<p; x++)
	{
		z = x;
		
		strcpy(temp.nome,Lista[z].nome);
		temp.altura = Lista[z].altura;
		temp.idade = Lista[z].idade;
		
		t = Lista[z].altura;
		while(t<Lista[z-1].altura)
		{
			Lista[z] = Lista[z-1];
			z = z-1;
		}
		strcpy(Lista[z].nome,temp.nome);
		Lista[z].altura = temp.altura;
		Lista[z].idade = temp.idade;
		
	}
}

int main()
{
	int contador,temporarioint,i;
	
	contador = 0;
	i = 0;
	int j;
	
	float temporariofloat;
	
	char S1[50];
    PESSOA Povo[10];
    FILE *Arq;
	Arq = fopen("nomes.txt","r+");
	char linha[50];
	
	
	
    while (fgets(linha, sizeof(linha), Arq)!=NULL)
    {
    	if(contador == 0)
    	{
    		strcpy(Povo[i].nome,linha);
    		contador++;
		}
		else
		{
			if(contador == 1)
			{
				temporarioint = atoi(linha);
				Povo[i].idade = (temporarioint);
				contador++;
			}
			else
			{
				if(contador == 2)
				{
					temporariofloat = atof(linha);
					Povo[i].altura = (temporariofloat);
					contador = 0;
					i++;
				}
			}
		}
	}
	insertion_sort_pessoas(Povo,4);
	rewind(Arq);
	for(j= 0; j<4; j++)
	{
		fprintf(Arq,"%s\n",Povo[j].nome);
		fprintf(Arq,"%d\n",Povo[j].idade);
		fprintf(Arq,"%f\n",Povo[j].altura);
		fprintf(Arq," \n");
	}
	
	fclose(Arq);
	
}
