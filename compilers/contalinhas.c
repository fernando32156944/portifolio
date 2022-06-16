/*
1. Escreva um programa na linguagem C que leia um
arquivo fonte de um programa escrito na linguagem
C e contabilize a quantidade de linhas do arquivo,
ao final seu programa deve imprimir a quantidade de
linhas do arquivo.

*/
#include <stdio.h>

int main(){
    char c;
    int linhas = 1;
    int brancos = 0;
    int ascii;
    int ListaMaiuscula[26];
    int ListaMinuscula[26];
    int ListaNumeros[10];
    int i;
    int j;
    int k;
    int a;
    int b;
    int d;
    
    for(a = 0; a<25; a++)
    {
    	ListaMaiuscula[a] = 0;
	}
	for(b = 0; b<25; b++)
    {
    	ListaMinuscula[b] = 0;
	}
	for(d = 0; d<9; d++)
    {
    	ListaNumeros[d] = 0;
	}
    
    
    // abrir um arquivo
    // https://www.cplusplus.com/reference/cstdio/fopen/
    FILE *fp = fopen("entrada.c","r");
    if( fp == NULL ){
        printf("erro na abertura do arquivo.\n");
        return 1;
    }
    // !feof(fp) testa se o arquivo já chegou ao final
    while(!feof(fp)){
        fscanf(fp,"%c",&c);
        printf("%c",c);
        if( c == '\n')
        {
            linhas++;
    	}
    	else 
		{
			if(c == ' ')
    		{
    			brancos++;
			}
			else
			{
				ascii = (int)c;
				if(90-ascii>=0 && 90-ascii<=25)
				{
					ListaMaiuscula[90-ascii] = ListaMaiuscula[90-ascii]+1;
				}
				else
				{
					if(122-ascii>=0 && 122-ascii<=25)
					{
						ListaMinuscula[122-ascii] = ListaMinuscula[122-ascii]+1;
					}
					else
					{
						if(57-ascii>= 0 && 57-ascii<=9)
						{
							ListaNumeros[57-ascii] = ListaNumeros[57-ascii]+1; 
						}
					}
				}
			}
		}
    }
    for(i = 25; i>0;i--)
    {
    	if(ListaMaiuscula[i]>0)
    	{
    		printf("\n total de %c no arquivo = %d",90-i,ListaMaiuscula[i]);
		}	
	}
	for(j = 25; j>0;j--)
    {
    	if(ListaMinuscula[j]>0)
    	{
    		printf("\n total de %c no arquivo = %d",122-j,ListaMinuscula[j]);
		}	
	}
	for(k = 9; k>0; k--)
	{
		if(ListaNumeros[k]>0)
		{
			printf("\n total de %c no arquivo = %d",57-k,ListaNumeros[k]);
		}
	}
    printf("\n Total de linhas no arquivo=%d",linhas);
    printf("\n Total de brancos no arquivo=%d",brancos);
    // fecha o arquivo
    fclose(fp);
    return 0; // nao tivemos erro
}
