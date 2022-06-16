/*
Nome: Fernando Machado 
TIA: 32156944
*/
#include<stdio.h>//inclui printf
#include<stdlib.h> // exit

char *buffer="abeda"; 
char lookahead;

void A();
void B();
void C();
void D();

void consome( char atomo );


   
	int main(void)
	{ 
		printf("analisando %s\n",buffer); 
		lookahead = *buffer++;
		
		A(); 
	if( lookahead == '\x0')// fim
		printf("palavra aceita."); 
	else 
		printf("\nerro sintatico."); 
		printf("\nfim de programa.\n"); 
	return 0; 
	}
// A::= abB
//B::= cC | eD
//D::= da
//C::= bC |  

void A()
{
  switch( lookahead ){
    case 'a':
        consome('a'); // consome a
        consome('b');
        B();
        break;
    default:
        printf("Erro sintatico 1.\n");
        exit(1);
  }
}
void B()
{
	switch(lookahead)
	{
		case('c'):
			consome('c');
			C();
			break;
		case('e'):
			consome('e');
			D();
			break;
	default:
        printf("Erro sintatico 1.\n");
        exit(1);
  }
}

void C()
{
	if(lookahead == 'b')
	{
		consome('b');
		C();
	}
	if(lookahead == '\0')
	{
		lookahead = '\x0';
	}
	else
	{
		printf("erro sintatico 1. \n");
		exit(1);
	}
}
void D()
{
	switch(lookahead)
	{
		case('d'):
			consome('d');
			consome('a');
			break;
	default:
        printf("Erro sintatico 1.\n");
        exit(1);
	}
}


void consome( char atomo ){
    if( lookahead == atomo )
        lookahead =*buffer++; // obter_atomo();
    else{
        printf("erro sintatico: esperado [%c] encontrado [%c]\n",atomo,lookahead);
        exit(1);
    }
}

