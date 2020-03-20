/**
@file logica.h
Funçoes que realizam e verificam a validade das jogadas no jogo.
*/

#ifndef ___LOGICA_H___
#define ___LOGICA_H___


/**
 * \brief Funçao principal da logica, que altera o estado do tabuleiro dependendo da jogada efetuada.
 * @param e Apontador para o estado.
 * @param c A coordenada.
 * @return Um valor de confirmaçao de sucesso.
*/
int jogar(ESTADO *e, COORDENADA c); // funcao que modifica o estado do jogo dependendo da jogada efetuada

// /////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Funçao que verifica se envolta da peça branca existem peças vazias onde se possa jogar.
 * @param e Apontador para o estado.
 * @return 1 Caso haja jogadas possiveis.
 * @return 0 Caso nao seja possivel continuar a jogar.
 */
int espaco_vazio(ESTADO *e);


/**
 * \brief Funçao que verifica se a peça branca se encontra numa das casas objetivo para vitoria.
 * @param e Apontador para o estado.
 * @return 1 Caso tal nao se verifique.
 * @return 0 Caso se encontre numa das casas objetivo.
 */
int espaco_vitoria(ESTADO *e);


/**
 * \brief Funçao que atraves das funçoes 'espaco_vazio' e 'espaco_vitoria' verifica se ainda e possivel continuar o jogo.
 * @param e Apontador para o estado.
 * @return 1 Caso ainda haja espaços vazios ou ainda nao se encontre numa casa objetivo.
 * @return 0 Caso nao seja possivel continuar a jogar.
 */
int jogada_possivel(ESTADO *e); // funcao que verifica se o jogo continua ou ja acabou


/**
 * \brief Funçao que verifica se a jogada indicada pelo jogador atual e valida.
 * @param e Apontador para o estado.
 * @param c A coordenada.
 * @return 0 Caso a jogada nao seja valida.
 * @return 1 Caso a jogada seja valida.
 */
int jogada_valida(ESTADO *e,COORDENADA c); //verifica se a jogada é válida


#endif //___LOGICA_H___
