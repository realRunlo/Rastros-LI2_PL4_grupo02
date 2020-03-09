#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada_dados.h"
#include "interpretador.h"


int main() {
    printf("PRONTOS PARA COMECAR O JOGO?\n");
    ESTADO *e = inicializar_estado();
    desenha_tabuleiro(e);
    interpretador(e);
    printf("JOGO TERMINADO\n");
}
