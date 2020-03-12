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

#endif //___CAMADADEDADOS_H__
