//
// Created by runlo on 09/04/20.
//

#include "listaslig.h"
#include <stdlib.h>

LISTA criar_lista(){
    LISTA l1 = malloc(sizeof(LISTA));

}

LISTA insere_cabeca(LISTA L, void *valor){
    LISTA head = malloc(sizeof(LISTA));
    head->valor = valor;
    head->prox = L;

    L = head;   //pode não ser necessário mas tbm não há problema
    return L;
}

void *devolve_cabeca(LISTA L){
    return (L->valor);
}

LISTA proximo(LISTA L){
    return (L->prox);
}

LISTA remove_cabeca(LISTA L){
    LISTA r = L->prox;
    free(L);
    return r;

}

int lista_esta_vazia(LISTA L){

    return (L->valor == NULL); //talvez 0 e não null
}