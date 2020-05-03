
#include <stdio.h>
#include "funcoes.h"
#include "dados.h"
#include "logica_bot.h"

int main(int argc, char *argv[ ]){
    if (argc == 3) {
        ESTADO *e = inicializar_estado();
        ler(e, argv[1], "r");
        bot_joga(e);
        gravar(e, argv[2], "w");
    }
    else return 0;

}