#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada_dados.h"



int main() {
    printf("o pedro n sabe nada!...\n");
    ESTADO e;
    for(int l = 0; l < 8; l++){
        for(int c = 0; c < 8; c++){
            e.tab[l][c] = VAZIO;
        }
    }
    e.tab[3][4] = BRANCA;
    e.jogadas->jogador1.coluna = 5;
    e.jogadas->jogador1.linha  = 5;
    e.num_jogadas = 0;
    e.jogador_atual = 1;
    desenha_tabuleiro(e);
    printf("o pedro n sabe nada!...\n");
}
