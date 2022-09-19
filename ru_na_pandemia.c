#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "libfila.h"
#include "libpilha.h"
#include "liblista.h"

#define MAX_MASC 100
#define MAX_REFEICOES 1000
#define MAX_TAM_FILA 1000

/* retorna um numero aleatorio entre o intervalo n e m */
int aleat(int n, int m){ 
	int aux;
	srand(time(NULL) );
	aux= n + (rand()%m);
	while( aux > m){
		aux=n + (rand()%m);
	}
	return aux;
}

int verifica_existencia(int vetor[], int n, int tam){
	int i;
	for(i=0;i<tam;i++){
		if(vetor[i] == n){
			return 1;
		}
	}
	return 0;
}

/*criando vetor de numeros aleatorios não repetidos*/
void vetor_aleatorio(int vetor[], int tam){		
	int aux,i;
	for (i=0;i<tam;i++){
		aux=1+rand()%tam;
		while(verifica_existencia(vetor,aux,tam)){
			aux=1+rand()%tam;
		}
		vetor[i]=aux;
	}
}



int main(){
		
	int i, qtd_refeicoes, ticket, qtd_masc, vetor[MAX_MASC], aux;
	pilha_t *pilha_masc, *pilha_refeicoes;
	lista_t *lista_ru;
	
	
	/* criando pilha de mascaras */
	/* cada mascara possui um identificador de 1 a 100 aleatorio*/
	printf("***CRIANDO PILHA DE MASCARAS***\n"); /* pode apagar depois */
	qtd_masc=aleat(1,MAX_MASC); /* quantidade de mascaras disponiveis */
	pilha_masc=pilha_cria(qtd_masc);
	if (pilha_masc == NULL){
		printf("criação da pilha FALHOU\n");
		return 0;
	}
	else{
		printf("criação da pilha realizada com SUCESSO\n");
	}
	
	/* cria um vetor com numeros aleatorios não repetidos */
	vetor_aleatorio(vetor,qtd_masc);
	
	/*inserindo mascaras na pilha de mascaras*/
	for (i=0; i<qtd_masc;i++){
		if (push(pilha_masc,vetor[i])==-1){
			printf("pilha de mascaras cheia\n");
		}
	}
	printf("o tamanho da pilha de mascaras é %d\n ", pilha_tamanho(pilha_masc));
	pilha_imprime(pilha_masc);/*pode apagar depois*/
	printf("\n\n");
	
	
	/* criando pilha de refeições */
	printf("\n***CRIANDO PILHA DE REFEIÇÕES***\n");/*pode apagar depois*/
	qtd_refeicoes=aleat(500,1000);
	printf("quantidade de refeiçoes: %d\n", qtd_refeicoes);

	
	return 0;
}
