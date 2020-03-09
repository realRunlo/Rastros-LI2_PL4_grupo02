//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include "camada_dados.h"

/*Função que deve ser completada
modifica estado ao jogar na casa correta se a jogada for válida
falta validar a jogada
alterar a posição anterior para PRETA*/

int jogar(ESTADO *e, COORDENADA c){
    printf("jogar %d %d\n", c.coluna, c.linha);
    e->tab[c.coluna][c.linha]=BRANCA;  //altera para a nova posição
    e->ultima_jogada.coluna=c.coluna;
    e->ultima_jogada.linha=c.linha;

    e->num_jogadas++;
    if(e->jogador_atual==1){
        e->jogadas[e->num_jogadas].jogador1.coluna=c.coluna;  //não sei se é suposto ser array
        e->jogadas[e->num_jogadas].jogador1.linha=c.linha;
        e->jogador_atual=2;
    }else{
        e->jogadas[e->num_jogadas].jogador2.coluna=c.coluna;  //não sei se é suposto ser array
        e->jogadas[e->num_jogadas].jogador2.linha=c.linha;
        e->jogador_atual=1;
    }
    return 1;
}