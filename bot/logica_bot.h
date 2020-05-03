/**
@file logica.h
Funçoes que realizam e verificam a validade das jogadas no jogo.
*/

#ifndef ___LOGICA_H___
#define ___LOGICA_H___

#include "lista_bot.h"

/**
 * \brief Funçao principal da logica, que altera o estado do tabuleiro dependendo da jogada efetuada.
 * @param e Apontador para o estado.
 * @param c A coordenada.
 * @return Um valor de confirmaçao de sucesso.
*/
int jogar(ESTADO *e, COORDENADA c); // funcao que modifica o estado do jogo dependendo da jogada efetuada

// /////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Joga uma jogada aleatória
 * @param e Estado
 * @param L Lista*/
void joga_aleatorio(ESTADO* e,LISTA lista);

/** \brief Joga uma jogada baseada da distãncia à casa de vitória do jogador (euclidiana)
 * @param e Estado
 * @param L Lista*/
void joga_euclidiana(ESTADO* e,LISTA lista);

/**
 * \brief Funcao que decide como o bot joga dependendo do estado do jogo
 * @param e Apontador para o estado
 */
void bot_joga(ESTADO *e);


/**
 * \brief Funçao que verifica se a jogada indicada pelo jogador atual e valida.
 * @param e Apontador para o estado.
 * @param c A coordenada.
 * @return 0 Caso a jogada nao seja valida.
 * @return 1 Caso a jogada seja valida.
 */
int jogada_valida(ESTADO *e,COORDENADA c); //verifica se a jogada é válida


#endif //___LOGICA_H___
