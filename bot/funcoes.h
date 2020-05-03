//
// Created by runlo on 29/04/20.
//
#include "dados.h"
#include <stdio.h>

/**
@file interface.h
Funçoes que interpretam os comandos dados pelo jogador.
*/
#include <stdio.h>
#ifndef ___INTERPRETADOR_H___
#define ___INTERPRETADOR_H___



/**
 * \brief Funçao que grava o tabuleiro, num ficheiro .txt especificado, de acordo com o estado atual do jogo.
 * @param e Apontador para o estado.
 * @param filename Nome do ficheiro onde se guardara o tabuleiro.
 */
void grava_tabuleiro(ESTADO *e,FILE *filename);

//COMANDOS

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



#endif //___INTERPRETADOR_H__

