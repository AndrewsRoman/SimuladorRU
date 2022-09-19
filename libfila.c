#include <stdio.h>
#include <stdlib.h>
#include "libfila.h"

#define MAX_TAM 10


/* Cria uma fila vazia e a retorna, se falhar retorna NULL. */
fila_t* fila_cria (){
	fila_t *f;
	f=malloc(sizeof(fila_t));
	if (f == NULL){
		return NULL;
	}
	f->ini=NULL;
	f->fim=NULL;
	f->tamanho=0;
	return f;

}

/* Remove todos os elementos da fila, libera espaco e devolve NULL. */
fila_t* fila_destroi (fila_t* f){
	if(f != NULL){
		nodo_f_t *aux;
		while (f->ini != NULL){
			aux = f->ini;
			f->ini = f->ini->prox;
			free(aux);
		}
	}
	f->tamanho = 0;
	free(f);
	return NULL;
}


/* Retorna 1 se a fila esta vazia e 0 caso contrario. */
int fila_vazia (fila_t* f){
	if (f->tamanho == 0){
		return 1;
	}
	return 0;
}


/* Retorna o tamanho da fila, isto eh, o numero de elementos presentes nela. */
int fila_tamanho (fila_t* f){
	return f->tamanho;
}


 /* Insere o elemento no final da fila (politica FIFO).
	 Retorna 1 se a operacao foi bem sucedida e 0 caso contrario. */
int queue (fila_t* f, int elemento){
	if (f->tamanho == MAX_TAM){ /* pilha cheia */
		return 0;
	}		
	nodo_f_t *temp;
	temp = malloc(sizeof(nodo_f_t));
	if(temp==NULL) 
		return 0;
	temp->chave=elemento;
	temp->prox=NULL;
	/*se a fila for vazia o inicio da fila recebe temp */
	if(fila_vazia(f)){
		f->ini = temp;
	}
	
	else{ /*se nao o final que aponta para o proximo aponta para temp */
		f->fim->prox=temp;
	}
	/* final aponta para o temp */
	f->fim = temp;
	f->tamanho++;
	return 1;
}


/* Remove elemento do inicio da fila (politica FIFO) e o retorna.
	* Remove elemento do inicio da fila (politica FIFO) e o retorna.
	 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario. */
int dequeue (fila_t* f, int* elemento){
	
	if(fila_vazia(f)){ /*verifica se a fila é vazia*/
		return 0;
	}
	
	nodo_f_t *temp;
	temp = f->ini; /* temp recebe o inicio da fila*/
	f->ini = f->ini->prox; /*inicio da fila aponta para o prox*/
	f->tamanho--;
	*elemento= temp->chave;
	free(temp);
	return 1;
}


void fila_imprime (fila_t* f){
	if (fila_vazia(f)){
		printf("fila vazia, não há o que imprimir\n");
		return;
	}
	nodo_f_t *temp;
	temp=f->ini; /* endereço de f->ini */
	
	printf("fila: ");
	while(temp != NULL){
		
		printf("%d ",temp->chave);
		temp=temp->prox;
	}
	printf("\n");	
}







