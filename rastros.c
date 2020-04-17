#include <stdio.h>
#include "camada_dados.h"
#include "interface.h"
#include "listaslig.h"




int main() {
    printf("PRONTOS PARA COMECAR O JOGO?\n");
    LISTA l = criar_lista();
    ESTADO *e = inicializar_estado();
    desenha_tabuleiro(e);
    imprime_estadoI(e);
    l = lista_insere_vazias(l, e);
    interpretador(e);


    printf("JOGO TERMINADO\n");
}