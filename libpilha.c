#include <stdio.h>
#include <stdlib.h>
#include "libpilha.h"

#define MAX_TAM 2000

/* aloca memoria e retorna o endereço da pilha p */
pilha_t *pilha_cria(int nelem){
	pilha_t *pilha;	
	pilha = (pilha_t *) malloc(sizeof(pilha_t));
	if(pilha == NULL) /* retorna NULL se deu problema na alocação da memoria da pilha*/
		return NULL;	
		
	pilha->elems =malloc(sizeof(int) * nelem);
	if(pilha->elems == NULL)
		return NULL; /* retorn NULL se deu problema na alocação de memoria do vetor da pilha*/
				
	pilha->topo = -1;
	pilha->nelem = 0;
	return pilha;
}

/* empilha um novo elemento na pilha e atualiza tamanho e topo */
/* se a pilha ja estiver cheia retorna -1 */
int push(pilha_t *pilha, int elem){
	if (pilha_tamanho(pilha)==MAX_TAM){
		return -1;	
	}
	pilha->topo++;
	pilha->nelem++;
	pilha->elems[pilha->topo] = elem;
	return pilha->nelem;
	
}

/* desempilha o elemento do topo da pilha, atualiza topo e tam e retorna o valor desempilhado */
/* se a pilha ja estiver vazia retorna 0 */
int pop(pilha_t *pilha){
	int aux;
	if (pilha_vazia(pilha)){
		return 0;
	}
	pilha->topo--;
	pilha->nelem--;
	aux = pilha->elems[pilha->topo+1];
	pilha->elems[pilha->topo+1] = 0;
	return aux;
}

/* retorna o elemento do topo da pilha */
int pilha_topo (pilha_t* pilha){		
	return pilha->elems[pilha->topo];
}

/* Retorna o numero de elementos da pilha, que pode ser 0 */
int pilha_tamanho (pilha_t* pilha){
	return pilha->nelem;
}

/* Retorna 1 se pilha vazia, 0 em caso contrario */ 
int pilha_vazia(pilha_t *pilha){
	if (pilha->topo == -1)
		return 1;	
	return 0;
}

/*libera o espaço alocado para a pilha*/
pilha_t* pilha_destroi (pilha_t* pilha){
	free(pilha->elems);
	pilha->elems = NULL;
	free(pilha);
	return NULL;	
}


void pilha_imprime (pilha_t* pilha){
	int i;
	for (i = 0; i < pilha->topo+1; i++){
		printf("%d ",pilha->elems[i]);
	}
	printf("\n");

}




























