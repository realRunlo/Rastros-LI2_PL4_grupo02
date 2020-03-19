#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada_dados.h"
#include "interface.h"
#include "logica.h"



int main() {
    printf("PRONTOS PARA COMECAR O JOGO?\n");
    ESTADO *e = inicializar_estado();
    desenha_tabuleiro(e);
    printf("Digite um comando->");
    interpretador(e);
    //lista_movimentos(e); //errada precisa de ser trabalhada

    printf("JOGO TERMINADO\n");
}
