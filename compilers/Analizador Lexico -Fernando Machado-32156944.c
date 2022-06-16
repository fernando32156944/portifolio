/*
NOME: Fernando Machado
TIA 32156944
analisador lexico.

*/
#include<stdio.h>//inclui printf
#include<ctype.h>
#include<stdlib.h> // exit
#include<string.h>
#include <math.h>//inclui pow

// como temos vários tipos de atomos, teremos uma constante numerica
// para representar cada atomo

// Definicao de constantes para os atomos da linguagem
typedef enum{
    ERRO, // constante erro lexico
    //identifiador
    IDENTIFICADOR,
    //atomos simples
    ABRE_PAR,
    ATRIBUICAO,
    FECHA_PAR,
    PONTO,
    PONTO_VIRGULA,
    VIRGULA,
    //Operadores aritimeticos
    SUBTRACAO,
    ADICAO,
    DIVISAO,
    MULTIPLICACAO,
    //Operadores relacionais
    OP_RELACIONAL,
    //Comentario
    COMENTARIO,
    //Constantes com valores inteiros e reais
    NUMERO_INTEIRO,
    NUMERO_REAL,
    //Constante caractere
    CARACTERE,
    // palavras reservadas
    AND,
    BEGIN,
    END,
    BOOLEAN,
    CHAR,
    DO,
    ELSE,
    FALSE,
    IF,
    INTEGER,
    MOD,
    NOT,
    OR,
    PROGRAM,
    READ,
    REAL,
    THEN,
    TRUE,
    WHILE,
    WRITE,
    EOS // fim de buffer
}TAtomo;

typedef enum
{
	ME,
    MEI,
    IG,
    DI,
    MA,
    MAI
}OPradores;


// estrutura para retornar o atomo e suas informacoes
typedef struct{
  TAtomo atomo;
  int linha;
  int atributo_numero;
  float atributo_real;
  char atributo_ID[15];
  OPradores atributoOP;
}TInfoAtomo;



char *buffer;
TInfoAtomo lookahead;
int linha = 1;
int contador = 0;
int sentinela = 0;


// reconhecer o atomo e retornar sua constante numerica
TInfoAtomo obter_atomo(void);
TInfoAtomo obteratomo1(void);
char *le_arquivo(char *nome_arquivo);
void reconhece_id(TInfoAtomo * info_atomo);
void reconhece_num(TInfoAtomo * info_atomo);
void Reconhece_Comentario(TInfoAtomo * info_atomo);
void programa();
void bloco();
void declaracao_de_variaveis();
void tipo();
void variaveis();
void comando_composto();
void comando();
void comando_atribuicao();
void comando_condicional();
void comando_repeticao();
void comando_saida();
void comando_entrada();
void expressao();
void expressao_simples();
void termo();
void fator();
void operador_termo();
void operador_simples();
void consome(TAtomo atomo);

int main( void )
{
    // le o arquivo e armazenada todo o arquivo em bloco na memoria e
    // atribui o inicio do bloco ponteiro buffer.
    buffer = le_arquivo("entrada.pas");

    char *iniBuffer = buffer;
    lookahead = obteratomo1();
    programa();
    
    
    printf("\nFim de programa.\n");
    // no final da analise lexica libera a memoria alocada
    free(iniBuffer);


}
// obtem UM E SOMENTE UM atomo do arquivo texto POR VEZ.
//analisador lexico
TInfoAtomo obter_atomo(){
    TInfoAtomo info_atomo;
    info_atomo.atomo = ERRO;
    // ignora espaco em branco e contagem de linha
    while( *buffer == ' ' || *buffer=='\n' || *buffer == '\t'){
        if( *buffer =='\n')
            linha++;
        buffer++;
    }
    info_atomo.linha = linha;
    if( *buffer == '\x0')
        info_atomo.atomo  = EOS;
    // identificador
    if( isalpha(*buffer))
        reconhece_id(&info_atomo);
    // numero inteiro
    else if( isdigit(*buffer))
        reconhece_num(&info_atomo);
    // atomos simples
    else if( *buffer == ':' && *(buffer+1)=='='){
        info_atomo.atomo = ATRIBUICAO;
        buffer+=2;
    }
    else if(*buffer == '(')
    {
    	info_atomo.atomo = ABRE_PAR;
    	buffer++;
	}
	else if(*buffer == ')')
	{
		info_atomo.atomo = FECHA_PAR;
    	buffer++;
	}
	else if(*buffer == '.')
	{
		info_atomo.atomo = PONTO;
    	buffer++;
	}
	else if(*buffer == ';')
	{
		info_atomo.atomo = PONTO_VIRGULA;
    	buffer++;
	}
	else if(*buffer == ',')
	{
		info_atomo.atomo = VIRGULA;
    	buffer++;
	}
	//operadores aritimeticos
	else if(*buffer == '-')
    {
    	info_atomo.atomo = SUBTRACAO;
    	buffer++;
	}
	else if(*buffer == '+')
    {
    	info_atomo.atomo = ADICAO;
    	buffer++;
	}
	else if(*buffer == '/')
    {
    	info_atomo.atomo = DIVISAO;
    	buffer++;
	}
	else if(*buffer == '*')
    {
    	info_atomo.atomo = MULTIPLICACAO;
    	buffer++;
	}
	//operadores relacionais
	else if(*buffer == '<' && *(buffer+1) == '=' )
    {
    	info_atomo.atomo = OP_RELACIONAL;
    	info_atomo.atributoOP = MEI;
    	buffer+=2;
	}
	else if(*buffer == '<')
    {
    	info_atomo.atomo = OP_RELACIONAL;
    	info_atomo.atributoOP = ME;
    	buffer++;
	}
	else if(*buffer == '=')
    {
    	info_atomo.atomo = OP_RELACIONAL;
    	info_atomo.atributoOP = IG;
    	buffer++;
	}
	else if(*buffer == '!' && *(buffer+1) == '=' )
    {
    	info_atomo.atomo = OP_RELACIONAL;
    	info_atomo.atributoOP = DI;
    	buffer+=2;
	}
	else if(*buffer == '>' && *(buffer+1) == '=' )
    {
    	info_atomo.atomo = OP_RELACIONAL;
    	info_atomo.atributoOP = MAI;
    	buffer+=2;
	}
	else if(*buffer == '>')
    {
    	info_atomo.atomo = OP_RELACIONAL;
    	info_atomo.atributoOP = MA;
    	buffer++;
	}
	
	else if(*buffer == '#')
	{
		Reconhece_Comentario(&info_atomo);
	}
	else if(*buffer == '{')
	{
		Reconhece_Comentario(&info_atomo);
	}
	else if(*buffer == '\'')
	{
		if(*(buffer+2) == '\'')
		{
			info_atomo.atomo = CARACTERE;

			info_atomo.atributo_ID[0] = *(buffer+1);
			buffer+=3;
		}
	}
	//prints
	if( info_atomo.atomo == IDENTIFICADOR )
        printf("Reconhecido IDENTIFICADOR [%s] na linha %d. \n",info_atomo.atributo_ID,info_atomo.linha);
    //numeros
    else if( info_atomo.atomo == NUMERO_INTEIRO )
        printf("Reconhecido NUMERO_INTEIRO [%d] na linha %d. \n",info_atomo.atributo_numero, info_atomo.linha);
    else if( info_atomo.atomo == NUMERO_REAL )
        printf("Reconhecido NUMERO_REAL [%f] na linha %d. \n",info_atomo.atributo_real, info_atomo.linha);
    //atomos simples
    else if( info_atomo.atomo == ABRE_PAR)
        printf("Reconhecido ABRE_PAR na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == ATRIBUICAO )
        printf("Reconhecido ATRIBUICAO na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == FECHA_PAR )
        printf("Reconhecido FECHA_PAR na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == PONTO )
        printf("Reconhecido PONTO na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == PONTO_VIRGULA )
        printf("Reconhecido PONTO_VIRGULA na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == VIRGULA )
        printf("Reconhecido VIRGULA na linha %d. \n",info_atomo.linha);
    //palavras reservadas
    else if( info_atomo.atomo == AND )
        printf("Reconhecido AND na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == BEGIN )
        printf("Reconhecido BEING na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == END )
        printf("Reconhecido END na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == BOOLEAN )
        printf("Reconhecido BOOLEAN na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == CHAR )
        printf("Reconhecido CHAR na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == DO )
        printf("Reconhecido DO na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == ELSE )
        printf("Reconhecido ELSE na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == FALSE )
        printf("Reconhecido FALSE na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == IF )
        printf("Reconhecido IF na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == INTEGER )
        printf("Reconhecido INTEGER na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == MOD )
        printf("Reconhecido MOD na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == NOT )
        printf("Reconhecido NOT na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == OR )
        printf("Reconhecido OR na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == PROGRAM )
        printf("Reconhecido PROGRAM na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == READ )
        printf("Reconhecido READ na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == REAL )
        printf("Reconhecido REAL na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == THEN )
        printf("Reconhecido THEN na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == TRUE )
        printf("Reconhecido TRUE na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == WRITE )
        printf("Reconhecido WRITE na linha %d. \n",info_atomo.linha);
	else if( info_atomo.atomo == WHILE )
        printf("Reconhecido WHILE na linha %d. \n",info_atomo.linha);
	//operadores aritimeticos
	else if( info_atomo.atomo == SUBTRACAO )
        printf("Reconhecido SUBTRACAO na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == ADICAO )
        printf("Reconhecido ADICAO na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == DIVISAO )
        printf("Reconhecido DIVISAO na linha %d. \n",info_atomo.linha);
    else if( info_atomo.atomo == MULTIPLICACAO )
        printf("Reconhecido MULTIPLICACAO na linha %d. \n",info_atomo.linha);
    //operadores relacionais
    else if( info_atomo.atomo == OP_RELACIONAL && info_atomo.atributoOP == ME)
        printf("Reconhecido OP_RELACIONAL na linha %d e com o atributo ME.  \n",info_atomo.linha);
    else if( info_atomo.atomo == OP_RELACIONAL && info_atomo.atributoOP == MEI)
        printf("Reconhecido OP_RELACIONAL na linha %d e com o atributo MEI.  \n",info_atomo.linha);
    else if( info_atomo.atomo == OP_RELACIONAL && info_atomo.atributoOP == IG)
        printf("Reconhecido OP_RELACIONAL na linha %d e com o atributo IG.  \n",info_atomo.linha);
    else if( info_atomo.atomo == OP_RELACIONAL && info_atomo.atributoOP == DI)
        printf("Reconhecido OP_RELACIONAL na linha %d e com o atributo DI.  \n",info_atomo.linha);
    else if( info_atomo.atomo == OP_RELACIONAL && info_atomo.atributoOP == MA )
        printf("Reconhecido OP_RELACIONAL na linha %d e com o atributo MA.  \n",info_atomo.linha);
    else if( info_atomo.atomo == OP_RELACIONAL && info_atomo.atributoOP == MAI)
        printf("Reconhecido OP_RELACIONAL na linha %d e com o atributo MAI.  \n",info_atomo.linha);
    //COMENTARIO
    else if( info_atomo.atomo == COMENTARIO )
        printf("Reconhecido COMENTARIO na linha %d. \n",info_atomo.linha);
    //Caractere
    else if( info_atomo.atomo == CARACTERE )
        printf("Reconhecido CARACTERE [%c] na linha %d. \n",info_atomo.atributo_ID[0],info_atomo.linha);
	//erro
    else if( info_atomo.atomo == ERRO ){
        printf("Erro lexico na linha %d. \n",info_atomo.linha);
        exit(1);
    }
    else if( info_atomo.atomo == EOS ){
        printf("Fim de analise lexica na linha %d. \n",linha);
        
    }
    return info_atomo;
}
void reconhece_id(TInfoAtomo * info_atomo){
    char *iniID=buffer;
    int controle;
    char copiadora[200];
id0:
    if( isalpha(*buffer)){
        buffer++;
        goto id1;
    }
    info_atomo->atomo = ERRO;
    return;
id1:
    if( isalpha(*buffer) || isdigit(*buffer)|| *buffer == '_'){
        buffer++;
        goto id1;
    }
    goto id2;

id2:
    // recorta o identificador do buffer
    // http://www.cplusplus.com/reference/cstring/strncpy/
    strncpy(info_atomo->atributo_ID,iniID,buffer-iniID);
    if(strlen(info_atomo->atributo_ID)<=19)
    {

    	for(controle = 0; controle<strlen(info_atomo->atributo_ID);controle++ )
    	{
    		copiadora[controle] = info_atomo->atributo_ID[controle];
    		copiadora[controle] = tolower(copiadora[controle]);
		}
		copiadora[buffer-iniID] = '\x0';
    	info_atomo->atributo_ID[buffer-iniID] = '\x0';

    	if(strcmp(copiadora,"and")==0)
        	info_atomo->atomo = AND;
    	else if(strcmp(copiadora,"begin")==0)
        	info_atomo->atomo = BEGIN;
        else if(strcmp(copiadora,"end")==0)
        	info_atomo->atomo = END;
    	else if(strcmp(copiadora,"boolean")==0)
        	info_atomo->atomo = BOOLEAN;
    	else if(strcmp(copiadora,"char")==0)
        	info_atomo->atomo = CHAR;
    	else if(strcmp(copiadora,"do")==0)
        	info_atomo->atomo = DO;
    	else if(strcmp(copiadora,"else")==0)
        	info_atomo->atomo = ELSE;
    	else if(strcmp(copiadora,"false")==0)
        	info_atomo->atomo = FALSE;
    	else if(strcmp(copiadora,"if")==0)
        	info_atomo->atomo = IF;
    	else if(strcmp(copiadora,"integer")==0)
        	info_atomo->atomo = INTEGER;
    	else if(strcmp(copiadora,"mod")==0)
        	info_atomo->atomo = MOD;
    	else if(strcmp(copiadora,"not")==0)
        	info_atomo->atomo = NOT;
   		else if(strcmp(copiadora,"or")==0)
        	info_atomo->atomo = OR;
    	else if(strcmp(copiadora,"program")==0)
        	info_atomo->atomo = PROGRAM;
    	else if(strcmp(copiadora,"read")==0)
        	info_atomo->atomo = READ;
    	else if(strcmp(copiadora,"real")==0)
        	info_atomo->atomo = REAL;
    	else if(strcmp(copiadora,"then")==0)
        	info_atomo->atomo = THEN;
    	else if(strcmp(copiadora,"true")==0)
        	info_atomo->atomo = TRUE;
    	else if(strcmp(copiadora,"while")==0)
        	info_atomo->atomo = WHILE;
    	else if(strcmp(copiadora,"write")==0)
        	info_atomo->atomo = WRITE;
    	else
        	info_atomo->atomo = IDENTIFICADOR;
    }
    else
    {
    	info_atomo->atomo = ERRO;
	}
}

void reconhece_num(TInfoAtomo * info_atomo){
    char *iniNum=buffer;
    float nump;//numero parcial
    int intp;//interio parcial
    int intps;//inteiro parcial com sinal
    char *iniNum2;
    char strNUM[15];
    char strNUM2[15];
    char simbolo[1];

    simbolo[0] = '+';

n0:
    if( isdigit(*buffer)){
        buffer++;
        goto n1;
    }
    info_atomo->atomo = ERRO;
    return;
n1:
    if(isdigit(*buffer)){
        buffer++;
        goto n1;
    }
    if(isalpha(*buffer)){
        info_atomo->atomo = ERRO;
        return;
    }
    if(*buffer == '.' && (*(buffer+1) == 'e' || *(buffer+1) == 'E'))
    {
    	strncpy(strNUM,iniNum,buffer-iniNum);
    	strNUM[buffer-iniNum] = '\x0';
    	buffer+=2;
    	nump = atof(strNUM);
    	iniNum2 = buffer;
    	goto n3;
	}
    // [outro]
    if(*buffer != '.')
	{
		goto n2;
	}
	else
	{
		info_atomo->atomo = ERRO;
		return;
	}
    

n2:
    // recorta o numero do buffer
    // http://www.cplusplus.com/reference/cstring/strncpy/
    strncpy(strNUM,iniNum,buffer-iniNum);
    strNUM[buffer-iniNum] = '\x0';
    // converte vetor de char para numero inteiro
    info_atomo->atributo_numero = atoi(strNUM);
    info_atomo->atomo = NUMERO_INTEIRO;
    return;

n3:
	if(*buffer == '-')
	{
		simbolo[0] = '-';
		buffer++;
		iniNum2 = buffer;
	}
	if(*buffer == '+')
	{
		buffer++;
		iniNum2 = buffer;
	}
	if(isalpha(*buffer))
	{
		info_atomo->atomo = ERRO;
		return;
	}
	goto n4;
n4:
	if(isdigit(*buffer)){
        buffer++;
        goto n4;
    }
    if(isalpha(*buffer)){
        info_atomo->atomo = ERRO;
        return;
    }
    goto n5;
n5:
	strncpy(strNUM2,iniNum2,buffer-iniNum2);
    strNUM2[buffer-iniNum2] = '\x0';
    intp = atoi(strNUM2);
    if(simbolo[0] == '-')
    {
    	intps = intp * -1;
	}
	else
	{
		intps = intp;
	}
    info_atomo->atomo = NUMERO_REAL;
    info_atomo->atributo_real = nump*(pow(10,intps));

}
// le o arquivo e armazenada todo o arquivo em bloco na memoria e
// atribui o inicio do bloco ponteiro buffer.


void Reconhece_Comentario(TInfoAtomo * info_atomo)
{
	if(*buffer == '#')
	{
		goto l0;
	}
	else
	{
		goto l1;
	}

	l0:
		while(*buffer!='\n')
	{
        buffer++;
	}
	info_atomo->atomo = COMENTARIO;
	info_atomo->linha = linha;
	return;
	l1:
		while(*buffer != '}')
		{
			if(*buffer == '\n')
			{
				linha++;
			}
			if(*buffer == '\x0')
			{
				info_atomo->atomo = ERRO;
				break;
			}
			buffer++;
		}
		if(*buffer == '}')
		{
			info_atomo->atomo = COMENTARIO;
			info_atomo->linha = linha;
			buffer++;
		}
		return;
}

void programa()
{
	consome(PROGRAM);
	consome(IDENTIFICADOR);
	consome(PONTO_VIRGULA);
	bloco();
	consome(PONTO_VIRGULA);
}
void bloco()
{
	declaracao_de_variaveis();
	comando_composto();
}
void declaracao_de_variaveis()
{
	if(lookahead.atomo == INTEGER || lookahead.atomo == REAL || lookahead.atomo == CHAR || lookahead.atomo == BOOLEAN )
	{
		tipo();
		variaveis();
		consome(PONTO_VIRGULA);
		if(lookahead.atomo == INTEGER || lookahead.atomo == REAL || lookahead.atomo == CHAR || lookahead.atomo == BOOLEAN )
		{
			declaracao_de_variaveis();
		}
	}
}
void tipo()
{
	if(lookahead.atomo == INTEGER)
	{
		consome(INTEGER);
	}
	else if(lookahead.atomo == REAL)
	{
		consome(REAL);
	}
	else if(lookahead.atomo == CHAR)
	{
		consome(CHAR);
	}
	else if(lookahead.atomo == BOOLEAN)
	{
		consome(BOOLEAN);
	}
}
void variaveis()
{
	consome(IDENTIFICADOR);
	if(lookahead.atomo == VIRGULA)
	{
		consome(VIRGULA);
		variaveis();
	}
}
void comando_composto()
{	
	consome(BEGIN);
	laco0:
		comando();
		if(lookahead.atomo == PONTO_VIRGULA)
		{
			consome(PONTO_VIRGULA);
			goto laco0;
		}
	consome(END);
}
void comando()
{
	sentinela = 0;
	comando_atribuicao();
	comando_condicional();
	comando_repeticao();
	comando_saida();
	comando_entrada();
	if(sentinela == 0)
	{
		comando_composto();
	}
}
void comando_atribuicao()
{
	if(lookahead.atomo == IDENTIFICADOR)
	{
		consome(IDENTIFICADOR);
		consome(ATRIBUICAO);
		expressao();
		sentinela = 1;
	}
}
void comando_condicional()
{
	if(lookahead.atomo == IF)
	{
		consome(IF);
		consome(ABRE_PAR);
		expressao();
		consome(FECHA_PAR);
		consome(THEN);
		comando();
		sentinela = 1;
		if(lookahead.atomo == ELSE)
		{
			consome(ELSE);
			comando();
		}
	}
}
void comando_repeticao()
{
	if(lookahead.atomo == WHILE)
	{
		consome(WHILE);
		consome(ABRE_PAR);
		expressao();
		consome(FECHA_PAR);
		consome(DO);
		comando();
		sentinela = 1;
	}
}
void comando_saida()
{
	if(lookahead.atomo == WRITE)
	{
		consome(WRITE);
		consome(ABRE_PAR);
		volta0:
			expressao();
			if(lookahead.atomo == VIRGULA)
			{
				consome(VIRGULA);
				goto volta0;
			}
		consome(FECHA_PAR);
		sentinela = 1;
	}
}
void comando_entrada()
{
	if(lookahead.atomo == READ)
	{
		consome(READ);
		consome(ABRE_PAR);
		variaveis();
		consome(FECHA_PAR);
		sentinela = 1;
	}
}
void expressao()
{
	expressao_simples();
	if(lookahead.atomo == OP_RELACIONAL)
	{
		consome(OP_RELACIONAL);
		expressao_simples();
	}
}
void expressao_simples()
{
	if(lookahead.atomo == ADICAO && contador == 0)
	{
		consome(ADICAO);
		contador == 1;
	}
	else
	{
		if(lookahead.atomo == SUBTRACAO && contador == 0)
		{
			consome(SUBTRACAO);
			contador == 1;
		}
	}
	retorno0:
		termo();
		if(lookahead.atomo == ADICAO || lookahead.atomo == SUBTRACAO || lookahead.atomo == OR)
		{
			operador_simples();
			goto retorno0;
		}
	
}
void termo()
{
	fator();
	if(lookahead.atomo == MULTIPLICACAO|| lookahead.atomo == DIVISAO|| lookahead.atomo == MOD|| lookahead.atomo == AND)
	{
		operador_termo();
		termo();
	}	
}
void fator()
{
	if (lookahead.atomo == NOT)
	{
		consome(NOT);
		fator();
	}
	else if (lookahead.atomo == FALSE)
	{
		consome(FALSE);
	}
	else if (lookahead.atomo == TRUE)
	{
		consome(TRUE);
	}
	else if (lookahead.atomo == IDENTIFICADOR)
	{
		consome(IDENTIFICADOR);
	}
	else if (lookahead.atomo == NUMERO_INTEIRO)
	{
		consome(NUMERO_INTEIRO);
	}
	else if (lookahead.atomo == NUMERO_REAL)
	{
		consome(NUMERO_REAL);
	}
	else if (lookahead.atomo == CARACTERE)
	{
		consome(CARACTERE);
	}
	else if (lookahead.atomo == ABRE_PAR)
	{
		consome(ABRE_PAR);
		expressao();
		consome(FECHA_PAR);
	}
}
void operador_termo()
{
	if(lookahead.atomo == MULTIPLICACAO)
	{
		consome(MULTIPLICACAO);
	}
	else if(lookahead.atomo == DIVISAO)
	{
		consome(DIVISAO);
	}
	else if(lookahead.atomo == MOD)
	{
		consome(MOD);
	}
	else if(lookahead.atomo == AND)
	{
		consome(AND);
	}
}
void operador_simples()
{
	if(lookahead.atomo == ADICAO)
	{
		consome(ADICAO);
	}
	else if(lookahead.atomo == SUBTRACAO)
	{
		consome(SUBTRACAO);
	}
	else if(lookahead.atomo == OR)
	{
		consome(OR);
	}
}
TInfoAtomo obteratomo1()
{
	TInfoAtomo A;
	while(A.atomo != PROGRAM)
	{
		A = obter_atomo();
		if(A.atomo != COMENTARIO && A.atomo != PROGRAM)
		{
			printf("ERRO SINTATICO O PROGRAMA DEVE COMECAR COM O COMANDO PROGRAM");
			exit(1);
		}	
	}
	return(A);
}
void consome( TAtomo atomo){
	if(lookahead.atomo != COMENTARIO)
	{
    	if( lookahead.atomo == atomo )
        	lookahead = obter_atomo();
    	else{
        	printf("erro sintatico: esperado [%d] encontrado [%d]\n na linha [%d]",atomo,lookahead.atomo,linha);
        	exit(1);
    	}
	}
	else
	{
		lookahead = obter_atomo();
	}
}

char *le_arquivo(char *nome_arquivo){
    // abre o arquivo
    FILE *fp_entrada;
    fp_entrada = fopen(nome_arquivo,"r");
    if(fp_entrada == NULL){
        printf("erro na abertura do arquivo de entrada.\n");
        exit(1);
    }

    char *buffer_entrada;
    // calcula o tamanho do arquivo para alocar um buffer na memoria.
    fseek(fp_entrada,0,SEEK_END); // desloca o ponteiro do arquivo do inicio para o fim
    int size_entrada = ftell(fp_entrada); // retorna qtd de bytes deslocados
    fseek(fp_entrada,0,SEEK_SET); // volta o ponteiro para o inicio do arquivo

    // aloca memoria
    buffer_entrada = (char*)calloc(size_entrada+1, sizeof(char));

    // le o arquivo todo para o buffer_entrada
    fread(buffer_entrada, sizeof(char),size_entrada, fp_entrada);
    // fecha o arquivo
    fclose(fp_entrada);
    return buffer_entrada;
}
