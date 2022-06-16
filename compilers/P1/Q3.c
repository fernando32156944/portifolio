/*

  NOME: Fernando Machado
  TIA:32156944

*/
#include<stdio.h>//inclui printf
#include<ctype.h>

// Para implementar o analisador lexico considere que a cadeia a ser analisada
// esta armazenada na variavel *cadeia declarada globalmente e ja lida.
char *cadeia = "123,42E2";

int reconheceNum(void);

int main( void )
{
	int i;
    char *iniCadeia = cadeia;
    i = reconheceNum();
    if(i == 1)
        printf("Palavra aceita ", cadeia);
    else
        printf("Palavra NAO aceita ", cadeia);



}
// funcao retorna 1 caso a cadeia faca parte da linguagem
// ou 0 caso contrario
int reconheceNum(void){

r0: // estado inicial
    if( *cadeia == '+' || *cadeia == '-'){
        cadeia++;
        goto r1;
    }
    if( isdigit(*cadeia)){
        cadeia++;
        goto r2;
    }
    // caso não seja + ou - ou digito retorna 0 (nao)
    return 0;
r1:
    if( isdigit(*cadeia)){
        cadeia++;
        goto r2;
    }
    // caso não seja digito retorna 0 (nao)
    return 0;

r2: // estado final

    if( isdigit(*cadeia)){
        cadeia++;
        goto r2;
    }
    else
    {
    	if(*cadeia == ',')
    	{
    		cadeia++;
    		goto r3;
		}
	}
    return 0;
    
r3:
	if(isdigit(*cadeia))
	{
		cadeia++;
		goto r3;
	}
	else
	{
		if(*cadeia == 'e' || *cadeia == 'E')
		{
			cadeia++;
			goto r4;
		}
	}
	// caso não seja digito retorna e tenha chegado ao final da palavra retorna 1 (sim)
    return 1;
r4:
	if(*cadeia == '+' || *cadeia == '-'||isdigit(*cadeia))
	{
		cadeia++;
		goto r5;
	}
	return 0;
r5:
	if(isdigit(*cadeia))
	{
		cadeia++;
		goto r5;
	}
	return 1;
}

