//
// Created by runlo on 09/04/20.
//

#ifndef ___LISTASLIG_H___
#define ___LISTASLIG_H___

#include "camada_dados.h"

typedef struct NODO {
    void *valor;
    struct NODO * prox;

}*LISTA;

// Cria uma lista vazia
LISTA criar_lista();
// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void * valor);

// Devolve a cabeça da lista
void * devolve_cabeca(LISTA L);

// Devolve a cauda da lista
LISTA proximo(LISTA L);

// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L);

// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L);

//imprime valores da lista
void imprimeLista(LISTA l);

LISTA lista_insere_vazias(LISTA lista, ESTADO *e);

int lengthL(LISTA l);

void * procuraL (LISTA l,int i);

void limpaL(LISTA l);






#endif //___LISTASLIG_H___
