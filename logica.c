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
    printf("jogar %d %d\n", c.coluna + 1, c.linha + 1);
    e->tab[c.linha][c.coluna]=BRANCA;  //altera para a nova posição
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



int jogada_possivel(ESTADO *e){
    if (e->jogador_atual == 1){
        int c = e->jogadas->jogador1.coluna;
        int l = e->jogadas->jogador1.linha;
        if ((e->tab[l + 1][c] == VAZIO     || e->tab[l - 1][c] == VAZIO     || e->tab[l][c + 1] == VAZIO     || e->tab[l][c - 1] == VAZIO ||
            e->tab[l + 1][c + 1] == VAZIO  || e->tab[l + 1][c - 1] == VAZIO || e->tab[l - 1][c + 1] == VAZIO || e->tab[l - 1][c - 1] == VAZIO)
            && (l != 7 && c != 0) && (l != 0 && c != 7))
            return 1;
        else return 0;
    }
    else {
        int c = e->jogadas->jogador2.coluna;
        int l = e->jogadas->jogador2.linha;
        if ((e->tab[l + 1][c] == VAZIO     || e->tab[l - 1][c] == VAZIO     || e->tab[l][c + 1] == VAZIO     || e->tab[l][c - 1] == VAZIO ||
             e->tab[l + 1][c + 1] == VAZIO  || e->tab[l + 1][c - 1] == VAZIO || e->tab[l - 1][c + 1] == VAZIO || e->tab[l - 1][c - 1] == VAZIO)
             && (l != 0 && c != 0) && (l != 7 && c != 7))
            return 1;
        else return 0;
    }
}