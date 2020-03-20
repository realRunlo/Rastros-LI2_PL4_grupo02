//
// Created by runlo on 09/03/20.
//

/**
@file dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef ___CAMADADEDADOS_H___
#define ___CAMADADEDADOS_H___

// conjunto de tipos utilizados para armazenamento e edicao dos dados do estado do jogo

/**
\brief Tipo de dados para a casa
*/
typedef enum {VAZIO, BRANCA, PRETA} CASA;

/**
\brief Tipo de dados para as coordenadas
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

/**
\brief Tipo de dados para jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

/**
\brief Tipo de dados para o estado
*/
typedef struct{
    /** O tabuleiro */
    CASA tab[8][8];
    /** Coordenada da ultima jogada*/
    COORDENADA ultima_jogada;
    /** Jogadas efetuadas */
    JOGADAS jogadas;
    /** Número de jogadas*/
    int num_jogadas;
    int jogador_atual;
    int num_comandos;
} ESTADO;

// //////////////////////////////////////////////////////////////////////////////////////////////////////

ESTADO *inicializar_estado(); // funcao que da o estado inicial do jogo

char converte_numero(int x); // funcao que torna um numero de uma coluna numa letra

int e_branca(ESTADO *e, int l, int c); // funcao que verifica se uma casa tem peca branca

int e_preta(ESTADO *e, int l, int c); // funcao que verifica se uma casa tem peca preta

int e_vazio(ESTADO *e, int l, int c); // funcao que verifica se uma casa tem peca vazio

void set_branca(ESTADO *e, int l, int c); // funcao que torna uma casa numa peca branca

void set_preta(ESTADO *e, int l, int c); // funcao que torna uma casa numa peca preta

void set_vazio(ESTADO *e, int l, int c); // funcao que torna uma casa numa peca vazio

int get_jogador(ESTADO *e); //funcao que retorna o numero do jogador atual

int set_jogador(ESTADO *e, int j); //funcao que atualiza o numero do jogador atual

int get_Njogadas(ESTADO *e);//retorna o número de jogadas

int get_Ncomandos(ESTADO *e);//retorna o número de comandos

int set_nJogadas(ESTADO *e, int nJ);//atualiza o número de jogadas

int set_nComandos(ESTADO *e, int nJ);//atualiza o número de comandos

int get_coluna(COORDENADA c); // retorna o número da coluna de uma coordenada

int get_linha(COORDENADA c); // retorna o número da linha de uma coordenada



void adiciona_lista_jogadas(ESTADO *e, int l, int c, int jogador); // funcao que adiciona na lista de jogadas a ultima jogada feita

void set_ultima_jogada(ESTADO *e, int l, int c); //Funcao que modifica as coordenadas da ultima jogada

void add_numjogadas(ESTADO *e); //Adiciona 1 ao numero de jogadas

void add_numcomandos(ESTADO *e); //Adiciona 1 ao numero de comandos

void novo_tabuleiro(ESTADO *e, int l, int c, char x); // atualiza o tabuleiro no estado de acordo com o que esta gravado no ficheiro de texto

void novo_prompt(ESTADO *e, int jogador, int nJogadas, int nComandos); // atualiza o estado a partir do prompt do que esta gravado no ficheiro
#endif //___CAMADADEDADOS_H__
