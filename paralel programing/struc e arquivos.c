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
	int x,z,t;
	x = 1;
	PESSOA temp;
	
	for(x = 1; x<p; x++)
	{
		temp = Lista[z];
		z = x;
		t = Lista[z].altura;
		while(t<Lista[z-1].altura)
		{
			Lista[z] = Lista[z-1];
			z = z-1;
		}
		Lista[z] = temp;
		
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
    while (fgets(linha, sizeof(linha), Arq))
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
	insertion_sort_pessoas(Povo,10);
	
	for(j= 0; j<10; j++)
	{
		printf("%s\n",Povo[i].nome);
		printf("%d\n",Povo[i].idade);
		printf("%f\n",Povo[i].altura);
	}
	
	fclose(Arq);
	
}
