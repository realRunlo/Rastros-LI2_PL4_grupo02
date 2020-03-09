//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada_dados.h"




// //////////////////////////////////////////////////////////////////////////////////////////////////////


// Função que deve ser completada e colocada na camada de dados
ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    for(int l = 0; l < 8; l++){
        for(int c = 0; c < 8; c++){
            e->tab[l][c] = VAZIO;
        }
    }
    e->tab[3][4] = BRANCA;
    e->jogadas->jogador1.coluna = 5;
    e->jogadas->jogador1.linha  = 5;
    e->jogador_atual = 1;
    e->num_jogadas = 0;
// Falta a resto da inicialização.
    return e;
}


