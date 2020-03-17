//
// Created by runlo on 09/03/20.
//

#ifndef ___CAMADADEDADOS_H___
#define ___CAMADADEDADOS_H___

// conjunto de tipos utilizados para armazenamento e edicao dos dados do estado do jogo

typedef enum {VAZIO, BRANCA, PRETA} CASA;

typedef struct {
    int coluna;
    int linha;
} COORDENADA;

typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct{
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

// //////////////////////////////////////////////////////////////////////////////////////////////////////

ESTADO *inicializar_estado(); // funcao que da o estado inicial do jogo

char converte_numero(int x); // funcao que torna um numero de uma coluna numa letra

int e_branca(ESTADO *e, int l, int c); // funcao que verifica se uma casa tem peca branca

int e_preta(ESTADO *e, int l, int c); // funcao que verifica se uma casa tem peca preta

int e_vazio(ESTADO *e, int l, int c); // funcao que verifica se uma casa tem peca vazio

void set_branca(ESTADO *e, int l, int c); // funcao que torna uma casa numa peca branca

void set_preta(ESTADO *e, int l, int c); // funcao que torna uma casa numa peca preta

int get_jogador(ESTADO *e); //funcao que retorna o numero do jogador atual

void adiciona_lista_jogadas(ESTADO *e, int l, int c, int jogador); // funcao que adiciona na lista de jogadas a ultima jogada feita

void set_ultima_jogada(ESTADO *e, int l, int c); //Funcao que modifica as coordenadas da ultima jogada

void add_numjogadas(ESTADO *e); //Adiciona 1 ao numero de jogadas

#endif //___CAMADADEDADOS_H__
