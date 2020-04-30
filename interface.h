//
// Created by runlo on 09/03/20.
//
/**
@file interface.h
Funçoes que interpretam os comandos dados pelo jogador.
*/
#include <stdio.h>
#ifndef ___INTERPRETADOR_H___
#define ___INTERPRETADOR_H___

/**
 * \brief Funçao que desenha o tabuleiro de acordo com o estado dado.
 * @param e Apontador para o estado.
 */
void desenha_tabuleiro(ESTADO *e);


/**
 * \brief Funçao que grava o tabuleiro, num ficheiro .txt especificado, de acordo com o estado atual do jogo.
 * @param e Apontador para o estado.
 * @param filename Nome do ficheiro onde se guardara o tabuleiro.
 */
void grava_tabuleiro(ESTADO *e,FILE *filename);

//COMANDOS

/**
 * \brief Funçao que desenha o prompt do jogo de acordo com o estado atual
 * @param e Apontador para o estado.
 * @param c A coordenada.
 */
void imprime_estado(ESTADO *e,COORDENADA c);

/**
 * \brief Funçao que desenha o prompt do jogo de acordo com o estado lido
 * @param e Apontador para o estado.
 */
void imprime_estadoI(ESTADO *e);

/**
 * \brief Funçao que grava num documento .txt especificado o tabuleiro do estado atual e o respetivo prompt.
 * @param e Apontador para o estado.
 * @param filename Nome do ficheiro .txt onde se ira gravar tabuleiro e o prompt.
 * @param mode Modo de uso do ficheiro, dado ao fopen, por exemplo para escrever ou apenas para leitura.
 */
void gravar(ESTADO *e,const char *filename, const char *mode);


/**
 * \brief Funçao que le o tabuleiro no ficheiro e conta o numero de jogadas realizadas
 * @param e Apontador para o estado.
 * @param fp Nome do ficheiro .txt onde se ira gravar tabuleiro e o prompt.
 * @return Numero de jogadas realizadas no tabuleiro lido.
 */
int le_tabuleiro(ESTADO *e,FILE *fp);


/**
 * \brief Funçao que le o tabuleiro e respetivo prompt de um ficheiro .txt especificado.
 * @param e Apontador para o estado.
 * @param filename Nome do ficheiro .txt onde se ira ler tabuleiro e o prompt.
 * @param mode Modo de uso do ficheiro, neste caso, read.
 */
void ler(ESTADO *e, const char *filename, const char *mode);

// MOVS ///


/**
 * \brief Funçao que imprime uma dada ronda consoante o argumento i passado
 * @param e Apontador para o estado.
 * @param i Indice
 * @param filename Ficheiro
 */
void flista_ronda(ESTADO *e,int i,FILE *filename);

/**
 * \brief Funçao nao terminada que ira imprimir os movimentos ja realizados no jogo.
 * @param e Apontador para o estado.
 */
void flista_movimentos(ESTADO *e,FILE *filename);


/**
 * \brief Funçao que imprime uma dada ronda consoante o argumento i passado
 * @param e Apontador para o estado.
 * @param i Indice
 */
void lista_ronda(ESTADO *e,int i);

/**
 * \brief Funcao que imprime a lista de movimentos efetuados
 * @param e Apontador para o estado.
 */
void lista_movimentos(ESTADO *e);

// POS//

/**
 * \brief funcao auxiliar da pos que limpa as jogadas ja realizadas do tabuleiro
 * @param e Apontador para o estado.
 * @param n_rondas numero de rondas realizadas no tabuleiro.
 * @param n_jogadas numero de jogadas realizadas no tabuleiro.
 * @param indice Indice da ronda para retornar.
 * @param impar Indicador se o numero de jogadas e impar ou par.
 * @param cord1 Coordenada do jogador 1.
 * @param cord2 Coordenada do jogador 2.
 */
void limpa_jogadas(ESTADO *e,int n_rondas, int n_jogadas, int indice, int impar, COORDENADA cord1, COORDENADA cord2);

/**
 * \brief Funcao que retorna o tabuleiro para uma ronda especificada
 * @param e Apontador para o estado.
 * @param indice Indice da ronda
 */
void volta_tabuleiro(ESTADO *e, int indice);

/**
 * \brief Funcao que reverte o estado do jogo para onde é pretendido
 * @param e Apontador para o estado.
 * @param n_ronda Ronda a qual se quer regresar
 */
void pos(ESTADO *e, int n_ronda);

// /////////////////////////////////////////////////////////////////////////////////////
//INTERPRETADOR

/**
 * \brief Funçao principal deste modulo, que recolhe o comando dado pelo jogador e o executa.
 * Comandos :
 * jogada (linha, coluna): executa a funçao jogar para, se possivel realizar a jogada desejada.
 * gr: grava o estado atual do jogo num ficheiro .txt aparte para futura continuaçao do jogo se desejado.
 * ler: altera o estado do jogo para o gravado num ficheiro .txt para continuar o jogo neste guardado.
 * movs: lista os movimentos realizadas
 * pos: Volta atrás a uma ronda pretendida
 * jog: jogada automática aleatória
 * jog2: jogada automática seguindo um pensamento euclidiano
 * q: termina o jogo.
 * @param e Apontador para o estado.
 * @return 1 Caso o jogo continue.
 * @return 0 Caso o jogo termine.
 */
int interpretador(ESTADO *e);






#endif //___INTERPRETADOR_H__
