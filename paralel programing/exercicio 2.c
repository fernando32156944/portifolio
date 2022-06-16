/*

* NOME DO ALUNO: Fernando Mauadie da Silva Machado

* TIA: 32156944

* Escreva um programa que leia 3 notas de um aluno e a média das notas dos exercícios realizados por ele. 
  Calcular a média de aproveitamento, usando a fórmula: MA = (N1 + N2*2 + N3*3 + ME)/7. 
  A partir da média, informar o conceito de acordo com a tabela:
  maior ou igual a 9	A
  maior ou igual a 7.5 e menor que 9	B
  maior ou igual a 6 e menor que 7.5	C
  maior ou igual a 4 e menor que 6	D
  menor que 4	E
*/


#include <stdio.h>
#include <stdlib.h>


void Media(float N1,float N2, float N3, float ME)
{
	float MA;
	MA = (N1 + N2*2 + N3*3 + ME)/7;
	if(MA>=9)
	{
		printf("Conceito A");
	}
		else
		{
			if(MA>=7.5)
			{
				printf("Conceito B");
			}
				else
				{
					if(MA>=6)
					{
						printf("Conceito C");
					}
						else
						{
							if(MA>=4)
							{
								printf("Conceito D");
							}
								else
								{
									printf("Conceito E");
								}
							
						}
					
				}
			
		}
	
}

void main()
{
	Media(4,4,3,4);
}


