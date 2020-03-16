//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <stdlib.h>
#include "camada_dados.h"


//Funcao que realiza a jogada emitida e altera o estado do jogo de acordo
int jogar(ESTADO *e, COORDENADA c){
    printf("Jogada efetuda: %d %d\n", c.coluna + 1, c.linha + 1);
    int l = c.linha;
    int co = c.coluna;
    int l_anterior = e->ultima_jogada.coluna;
    int c_anterior = e->ultima_jogada.linha;
    int j = get_jogador(e);
    set_branca(e, l ,co);  //altera para a nova posição
    set_preta(e, l_anterior, c_anterior);  //altera a ultima posição para preta
    adiciona_lista_jogadas(e, l, co, j);
    e->num_jogadas++;
    e->ultima_jogada.coluna=c.coluna;
    e->ultima_jogada.linha=c.linha;
    return 1;
}


//Verifica de há casas disponiveis para jogar
int espaco_vazio(ESTADO *e){
    int c = e->ultima_jogada.coluna;
    int l = e->ultima_jogada.linha;
    if ((e->tab[l + 1][c] == VAZIO     || e->tab[l - 1][c] == VAZIO     || e->tab[l][c + 1] == VAZIO     || e->tab[l][c - 1] == VAZIO ||
         e->tab[l + 1][c + 1] == VAZIO  || e->tab[l + 1][c - 1] == VAZIO || e->tab[l - 1][c + 1] == VAZIO || e->tab[l - 1][c - 1] == VAZIO))
         return 1;
    else {
        printf("Jogador %d bloqueado!Perdeu\n",e->jogador_atual);
        return 0;
    }

}

//Verifica se está numa casa de vitória e felicita o repetivo jogador pela vitória
int espaco_vitoria(ESTADO *e){

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

//Funcao que verifica se e possivel continuar a jogar
int jogada_possivel(ESTADO *e){

    if(espaco_vazio(e)  && espaco_vitoria(e))
        return 1;
    return 0;

}

//Funcao que verifica se a jogada e valida
int jogada_valida(ESTADO *e,COORDENADA c){
    int cAnt = e->ultima_jogada.coluna;
    int lAnt = e->ultima_jogada.linha;
    int cJog = c.coluna;
    int lJog = c.linha;
    if(abs(cJog-cAnt)>1 || abs(lJog-lAnt)>1 || (e->tab[lJog][cJog])==PRETA)
        return 0;

    return 1;

}