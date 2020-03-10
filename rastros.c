#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada_dados.h"
#include "interpretador.h"
#include "logica.h"


int main() {
    printf("PRONTOS PARA COMECAR O JOGO?\n");

    ESTADO *e = inicializar_estado();
    int x=jogada_possivel(e);
    desenha_tabuleiro(e);
    while(x == 1) {         //ciclo está a quebrar na segunda jogada
        interpretador(e);
        x=jogada_possivel(e);
    }

    printf("JOGO TERMINADO\n");
}
