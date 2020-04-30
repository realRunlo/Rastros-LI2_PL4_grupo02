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

/**
\brief Cria uma lista vazia
*/
LISTA criar_lista();

/** \brief Insere um valor na cabeça da lista
 * @param L Lista
 * @param valor Valor a inserir*/
LISTA insere_cabeca(LISTA L, void * valor);

/** \brief Retorna a cabeça da lista
 * @param L Lista*/
void * devolve_cabeca(LISTA L);

/** \brief Retorna a cauda da lista
 * @param L Lista*/
LISTA proximo(LISTA L);

/** \brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
 * @param L Lista*/
LISTA remove_cabeca(LISTA L);

/** \brief Retorna verdareiro se a lista é vazia
 * @param L Lista*/
int lista_esta_vazia(LISTA L);

//imprime valores da lista
void imprimeLista(LISTA l);

/** \brief Verifica a casas vazias em volta da ultima jogada e adiciona a uma lista essas casa
 * @param L Lista
 * @param e Estado*/
LISTA lista_insere_vazias(LISTA lista, ESTADO *e);

/** \brief Retorna o comprimento da lista
 * @param L Lista*/
int lengthL(LISTA l);

/** \brief Procura na lista o elemento no indice fornecido
 * @param L Lista
 * @param i Indice fornecido*/
void * procuraL (LISTA l,int i);

/** \brief Limpa lista
 * @param L Lista*/
void limpaL(LISTA l);

/** \brief Joga uma jogada aleatória
 * @param e Estado
 * @param L Lista*/
void joga_aleatorio(ESTADO* e,LISTA lista);

/** \brief Joga uma jogada baseada da distãncia à casa de vitória do jogador (euclidiana)
 * @param e Estado
 * @param L Lista*/
void joga_euclidiana(ESTADO* e,LISTA lista);


/** \brief Procura o caminho mais curto para a casa objetivo
 * @param e Estado
 * @param L Lista*/
COORDENADA procura_caminho_curto(ESTADO* e, LISTA l);

/** \brief Verifica se um elemento pertence a lista
 * @param L Lista
 * @param c_objetivo Valor*/
COORDENADA verifica_na_lista(LISTA l,int c_objetivo);
#endif //___LISTASLIG_H___
