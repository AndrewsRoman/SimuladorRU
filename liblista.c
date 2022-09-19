#include <stdio.h>
#include <stdlib.h>
#include "liblista.h"

#define MAX_TAM 1000

/* Cria uma lista vazia e a retorna, se falhar retorna NULL.*/
lista_t* lista_cria (){
	lista_t *l;
	l=malloc(sizeof(lista_t));
	if (l == NULL){
		return NULL;
	}
	l->ini = NULL;
	l->tamanho=0;	
	return l;
}

/* Remove todos os elementos da lista, libera espaco e retorna NULL. */
lista_t* lista_destroi (lista_t* l){
	nodo_l_t* temp;
	if (l!=NULL){
		while(l->ini != NULL){
			temp=l->ini;
			l->ini=l->ini->prox;
			free(temp);
		}
		free(l);
	}	
	return NULL;
}

/* Retorna 1 se a lista esta vazia e 0 caso contrario. */
int lista_vazia (lista_t* l){
	if(l->ini==NULL){
		return 1;
	}
	return 0;
}

/* Retorna o tamanho da lista, isto eh, o numero de elementos presentes nela. */
int lista_tamanho (lista_t* l){
	return l->tamanho;
}

/* Insere o elemento no inicio da lista.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario. */
int lista_insere_inicio (lista_t* l, int elemento){
	if(l->tamanho == MAX_TAM)
		return 0;

	nodo_l_t* temp;
	temp = malloc(sizeof(nodo_l_t));
	if (temp == NULL){
		return 0;
	}
	temp->elemento=elemento;
	temp->prox=l->ini; /* atualiza o apontador prox com o endereço para o elemento que ja estava na lista*/ 
	l->ini = temp; /* recebe o novo nó/elemento */
	l->tamanho++;
	return 1;
}

/* Insere o elemento no final da lista.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario. */
int lista_insere_fim (lista_t* l, int elemento){
	if(l->tamanho == MAX_TAM)
		return 0;

	nodo_l_t* temp;
	temp = malloc(sizeof(nodo_l_t));
	if (temp == NULL)
		return 0;
	temp->elemento = elemento;
	temp->prox = NULL;
	
	if(lista_vazia(l)){ /* se a lista for vazia insere no inicio*/
		l->ini=temp;
		l->tamanho++;
		return 1;
	}
	nodo_l_t* aux;
	aux = l->ini;
	/* se a lista não for vazia percorre a lista ate o final e insere o elemento */
	while(aux->prox != NULL){
		aux=aux->prox; /* enquanto o proximo elemento for diferente de null aux recebe o proximo nó*/
	}
	aux->prox=temp; /* insere nessa posição o novo nó*/
	l->tamanho++;
	return 1;
}

/* Insere o elemento na lista garantindo ordenacao em ordem crescente.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario. */
int lista_insere_ordenado (lista_t* l, int elemento){
	if(l->tamanho == MAX_TAM)
		return 0;
		
	nodo_l_t* temp;
	temp = malloc(sizeof(nodo_l_t));
	if (temp == NULL)
		return 0;	
	temp->elemento = elemento;
	temp->prox = NULL; 
	
	/* se a lista for vazia insere no inicio */
	if(lista_vazia(l)){ 
		temp->prox=l->ini;
		l->ini=temp;
		l->tamanho++;
		return 1;
	}
	else{
		nodo_l_t *anterior, *atual;
		atual=l->ini;
		/*enquanto atual não for null e o elemento da lista for 
		menor que o elemento a ser inserido, o anterior recebe o atual
		e o atual recebe o proximo*/
		while( (atual != NULL) && (atual->elemento < elemento) ){
			anterior=atual;
			atual=atual->prox;
		}
		/* se o atual for o inicio da lista, deve inserir o novo nó 
		no inicio da lista */
		if(atual==l->ini){
			temp->prox=l->ini;
			l->ini=temp;
		}
		else{
			temp->prox = anterior->prox;
			anterior->prox = temp;
		}
		
	}
	l->tamanho++;
	return 1;
}

/* Remove o elemento do inicio da lista e o retorna em 'elemento'.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario. */
int lista_retira_inicio (lista_t* l, int* elemento){
	if(lista_vazia(l))
		return 0;
	nodo_l_t *temp;
	
	temp = l->ini;
	l->ini=temp->prox;
	l->tamanho--;
	*elemento= temp->elemento;
	free(temp);
	return 1;
}

/* Remove o elemento do final da lista e o retorna em 'elemento'.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario. */
int lista_retira_fim (lista_t* l, int* elemento){
	if(lista_vazia(l))
		return 0;
	nodo_l_t *temp, *anterior;
	temp=l->ini;
	while(temp->prox!=NULL){
		anterior = temp;
		temp = temp->prox;
	}
	*elemento= temp->elemento;
	if(temp == l->ini)
		l->ini = temp->prox;
	else
		anterior->prox=temp->prox;
	l->tamanho--;
	free(temp);

	return 1;
}


/* Remove o elemento 'elemento' caso ele exista na lista.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
 * Se o elemento nao for encontrado na lista tambem retorna 0. */
int lista_retira_elemento (lista_t *l, int *elemento){
	nodo_l_t *temp,*aux;
	temp=l->ini;
	int cont=0;
	while(cont < l->tamanho){
		if (temp->elemento == *elemento){
			
			if (temp==l->ini){
				l->ini=temp->prox;
				free(temp);
				return 1;
			}
			aux->prox = temp->prox;
			free(temp);
			return 1;
		}
		aux=temp;
		temp=temp->prox;
		cont++;
	}
	return 0;

}

/* Retorna 1 se o elemento existe na lista e 0 caso contrario. */
int lista_pertence (lista_t* l, int elemento){
	nodo_l_t *temp;
	temp=l->ini;
	int cont=0;
	while(cont < l->tamanho){
		if (temp->elemento == elemento){
			return 1;
		}
		temp=temp->prox;
		cont++;
	}
	return 0;
}



void lista_imprime (lista_t* l){
	
	if (lista_vazia(l)){
		printf("lista vazia, não há o que imprimir\n");
		return;
	}
	nodo_l_t *temp;
	temp=l->ini; /* endereço de l->ini */
	
	printf("lista: ");
	while(temp != NULL){
		
		printf("%d ",temp->elemento);
		temp=temp->prox;
	}
	printf("\n");

}













