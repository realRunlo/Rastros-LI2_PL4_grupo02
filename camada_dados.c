//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada_dados.h"

void desenha_tabuleiro(ESTADO e){
    for(int l = 0; l < 8; l++){
        for(int c = 0; c < 8; c++) {
            if (e.tab[l][c] == BRANCA) printf("*");
            else if (c == 0 && l == 7) printf("1");
                else if (c == 7 && l == 0) printf("2");
                    else if (e.tab[l][c] == PRETA) printf("#");
                        else printf(".");
        }
        printf("\n");
    }
}


