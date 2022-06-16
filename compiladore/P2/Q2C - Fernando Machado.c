/*
A::= B*A | B
B ::= C{> C}
C ::=  D {< D}
D ::= E | ~E
E ::= a | ( A )
*/

//NOME: FERNANDO MAUADIE DA SILVA MACHADO
//TIA: 32156944

#include<stdio.h>
#include<stdlib.h> 

char *buffer="a>~a*a*a";
char lookahead;

void A();
void B();
void C();
void D();
void E();


void consome( char atomo );


int main(void){ 
printf("analisando %s\n",buffer); 
lookahead = *buffer++;
A(); 
if( lookahead == '\x0')// fim de buffer 
   printf("palavra aceita."); 
else 
   printf("\nerro sintatico."); 
printf("\nfim de programa.\n"); 
return 0; 
}
void A()
{
	B();
	if(lookahead == '*')
	{
		consome('*');
		A();
	}
}
void B()
{
	C();
	if(lookahead == '>')
	{
		consome('>');
		C();
	}
}
void C()
{
	D();
	if(lookahead == '<')
	{
		consome('<');
		D();
	}
}
void D()
{
	if(lookahead == '~')
	{
		consome('~');
	}
	E();
}
void E()
{
	if(lookahead == '(')
	{
		consome('(');
		A();
		consome(')');
	}
	else
	{
		consome('a');
	}
	
}
void consome( char atomo ){
    if( lookahead == atomo )
        lookahead =*buffer++; 
    else{
        printf("erro sintatico: esperado [%c] encontrado [%c]\n",atomo,lookahead);
        exit(1);
    }
}

