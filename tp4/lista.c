#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
/* coloque demais includes aqui */

/* ------------------- Nao altere estas structs ------------------------- */
struct nodo {
    int chave;
    struct nodo *prox;
};

struct lista {
    struct nodo *ini;
    struct nodo *ptr; /* ponteiro para algum nodo da lista (iterador) */
    int tamanho;

};
/* ---------------------------------------------------------------------- */

struct lista *lista_cria (){
    struct lista *l;

    l = malloc(sizeof(struct lista));

    if (l == NULL)
        return NULL;

    l -> ini = NULL;
    l -> ptr = NULL;
    l -> tamanho = 0;
    
    return l;
} /*nao testada ainda*/

void lista_destroi (struct lista **lista){
    struct nodo *aux;
    if ((*lista) == NULL)
        return;

    (*lista)->ptr = (*lista)->ini;

    while (!((*lista)->ptr == NULL))
    {
        aux = (*lista)->ptr;
        (*lista)->ptr = (*lista)->ptr->prox;
        free(aux);    
    }

    free(*lista);
    lista = NULL;

}

int lista_insere_inicio (struct lista *lista, int chave){
    if (lista == NULL)
        return 0;

    struct nodo *novo;
            
    novo = malloc(sizeof(struct nodo *));
    
    if (novo == NULL)
        return 0;    
        
    novo -> chave = chave;
    novo -> prox = lista -> ini;
    lista -> ini = novo;
    lista -> tamanho++;

    return 1;
}

int lista_insere_fim (struct lista *lista, int chave){	
    if (lista == NULL)
        return 0;	
    
    struct nodo *novo;
    struct nodo *aux;

	novo = malloc(sizeof(struct nodo *));
	
    if (novo == NULL)
        return 0;         

    novo -> chave = chave;
    novo -> prox = NULL;

    if (lista -> ini == NULL)
    {
        lista -> ini = novo;
        return 1;
    }

    aux = lista -> ini;

    while (aux->prox != NULL)
        aux = aux -> prox;

    aux -> prox = novo;
    lista -> tamanho++;
    
    return 1;
    
}

/*
int lista_insere_ordenado (struct lista *lista, int chave){
}
*/

int lista_remove_inicio (struct lista *lista, int *chave){
    struct nodo *aux;
    
    if (lista -> ini == NULL)
        return 0;

    *chave = lista -> ini -> chave;
    aux = lista -> ini -> prox;
    free(lista -> ini);
    lista -> ini = aux;
    lista -> tamanho--;

    return 1;

}

int lista_remove_fim (struct lista *lista, int *chave){
    if (lista == NULL || lista -> ini == NULL)
        return 0;

    struct nodo *aux;

    aux = lista -> ini;

    if (aux -> prox == NULL)
    {
        *chave = lista -> ini -> chave;
        free(lista -> ini);
        lista -> ini = NULL;
        lista -> tamanho--;

        return 1;
    }
  

    while (aux->prox->prox != NULL)
        aux = aux -> prox;

    *chave = aux -> prox -> chave;
    free(aux -> prox);
    aux -> prox = NULL;
    lista -> tamanho--;

    return 1;

}

/*
int lista_remove_ordenado (struct lista *lista, int chave){
}
*/

int lista_vazia (struct lista *lista){
    if (lista -> ini == NULL)
        return 1;
    return 0;
}
/*
int lista_tamanho (struct lista *lista){
}
*/
int lista_pertence (struct lista *lista, int chave){
    if (lista == NULL || lista -> ini == NULL)
        return 0;

    struct nodo *aux;

    aux = lista -> ini;

    while (aux -> chave != chave && aux -> prox != NULL)
        aux = aux -> prox;

    if (aux -> chave != chave)
        return 0;

    return 1;
}

void lista_inicia_iterador (struct lista *lista){
    lista -> ptr = lista -> ini;
}

int lista_incrementa_iterador (struct lista *lista, int *chave){
    if (lista -> ptr == NULL)
        return 0;

    *chave = lista -> ptr -> chave;
    lista -> ptr = lista -> ptr -> prox;
    return 1;
}
