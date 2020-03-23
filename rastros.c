#include <stdio.h>
#include "camada_dados.h"
#include "interface.h"




int main() {
    printf("PRONTOS PARA COMECAR O JOGO?\n");
    ESTADO *e = inicializar_estado();
    desenha_tabuleiro(e);
    imprime_estadoI(e);
    printf("Digite um comando->");
    interpretador(e);


    printf("JOGO TERMINADO\n");
}
