//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <stdlib.h>
#include "camada_dados.h"



int jogar(ESTADO *e, COORDENADA c){
    printf("jogar %d %d\n", c.coluna + 1, c.linha + 1);
    e->tab[c.linha][c.coluna]=BRANCA;  //altera para a nova posição
    e->tab[e->ultima_jogada.linha][e->ultima_jogada.coluna] = PRETA;  //altera a ultima posição para preta

    e->num_jogadas++;
    if(e->jogador_atual==1){
        e->jogadas[e->num_jogadas].jogador1.coluna=c.coluna;  //não sei se é suposto ser array, é preciso ver como se atualiza o o campo jogadas do estado
        e->jogadas[e->num_jogadas].jogador1.linha=c.linha;
        e->jogador_atual=2;
    }else{
        e->jogadas[e->num_jogadas].jogador2.coluna=c.coluna;  //não sei se é suposto ser array
        e->jogadas[e->num_jogadas].jogador2.linha=c.linha;
        e->jogador_atual=1;
    }
    e->ultima_jogada.coluna=c.coluna;
    e->ultima_jogada.linha=c.linha;
    return 1;
}

int espaco_vazio(ESTADO *e){    //verifica de há casas disponiveis para jogar
    int c = e->ultima_jogada.coluna;
    int l = e->ultima_jogada.linha;
    if ((e->tab[l + 1][c] == VAZIO     || e->tab[l - 1][c] == VAZIO     || e->tab[l][c + 1] == VAZIO     || e->tab[l][c - 1] == VAZIO ||
         e->tab[l + 1][c + 1] == VAZIO  || e->tab[l + 1][c - 1] == VAZIO || e->tab[l - 1][c + 1] == VAZIO || e->tab[l - 1][c - 1] == VAZIO))
         return 1;
    return 0;
}

int espaco_preto(ESTADO *e){   //verifica se está preso ou não
    int c = e->ultima_jogada.coluna;
    int l = e->ultima_jogada.linha;
    if((e->tab[l + 1][c] == PRETA  && e->tab[l - 1][c] == PRETA  && e->tab[l][c + 1] == PRETA   && e->tab[l][c - 1] == PRETA &&
         e->tab[l + 1][c + 1] == PRETA  && e->tab[l + 1][c - 1] == PRETA && e->tab[l - 1][c + 1] == PRETA && e->tab[l - 1][c - 1] == PRETA)){
        if(e->jogador_atual==1){
            printf("Jogador 1 bloqueado!Ganha jogador 2\n");
            return 0; // se estiver rodeada por pretas retorna 0
        } else{
            printf("Jogador 2 bloqueado!Ganha jogador 1\n");
            return 0; // se estiver rodeada por pretas retorna 0
        }
    }

    return 1;
}

int espaco_vitoria(ESTADO *e){  //verifica se está numa casa de vitória e felicita o repetivo jogador pela vitória
    int c = e->ultima_jogada.coluna;
    int l = e->ultima_jogada.linha;
    if((l != 0 || c != 0) && (l != 7 || c != 7))
        return 1;
    if(l==0 ){
        printf("Jogador 1 ganhou\n");
        return 0;
    }else{
        printf("Jogador 2 ganhou\n");
        return 0;
    }


}

int jogada_possivel(ESTADO *e){

    if(espaco_vazio(e) && espaco_preto(e) && espaco_vitoria(e))
        return 1;
    return 0;

}


int jogada_valida(ESTADO *e,COORDENADA c){
    int cAnt = e->ultima_jogada.coluna;
    int lAnt = e->ultima_jogada.linha;
    int cJog = c.coluna;
    int lJog = c.linha;
    if(abs(cJog-cAnt)>1 || abs(lJog-lAnt)>1 || (e->tab[lJog][cJog])==PRETA)
        return 0;

    return 1;

}