//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada_dados.h"




// //////////////////////////////////////////////////////////////////////////////////////////////////////


// Função que deve ser completada e colocada na camada de dados
ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    for(int l = 7; l >= 0; l--){
        for(int c = 0; c < 8; c++){
            e->tab[l][c] = VAZIO;
        }
    }
    e->tab[4][4] = BRANCA;
    e->ultima_jogada.coluna=4;
    e->ultima_jogada.linha=4;
    e->jogador_atual = 1;
    e->num_jogadas = 0;
// Falta a resto da inicialização.
    return e;
}


//Converte um numero de uma coluna na sua letra correspondente
char converte_numero(int x){
    return 'a' + x;
}



//Verifica se a casa tem peca branca
int e_branca(ESTADO *e, int l, int c){
    if (e->tab[l][c] == BRANCA) return 1;
    else return 0;
}



//Verifica se a casa tem peca preta
int e_preta(ESTADO *e, int l, int c){
    if (e->tab[l][c] == PRETA) return 1;
    else return 0;
}



//Verifica se a casa tem peca vazia
int e_vazio(ESTADO *e, int l, int c){
    if (e->tab[l][c] == VAZIO) return 1;
    else return 0;
}



//Coloca a casa como sendo uma peca branca
void set_branca(ESTADO *e, int l, int c){
    e->tab[l][c] = BRANCA;
}



//Coloca a casa como sendo uma peca preta
void set_preta(ESTADO *e, int l, int c){
    e->tab[l][c] = PRETA;
}



//Funcao que retorna o numero do jogador atual
int get_jogador(ESTADO *e){
    return e->jogador_atual;
}

int get_Njogadas(ESTADO *e){ //retorna o número de jogadas
    return e->num_jogadas;
}

int get_coluna(COORDENADA c){
    return c.coluna;
}

int get_linha (COORDENADA c){
return c.linha;
}


//Funcao que modifica a ultima jogada
void set_ultima_jogada(ESTADO *e, int l, int c){
    e->ultima_jogada.coluna=c;
    e->ultima_jogada.linha=l;
}



//Funcao que adiciona 1 ao numero de jogadas
void add_numjogadas(ESTADO *e){
    e->num_jogadas++;
}



//Funcao que adiciona na lista de jogadas a ultima jogada feita
void adiciona_lista_jogadas(ESTADO *e, int l, int c, int jogador){
    if (jogador == 1) {
        e->jogadas[e->num_jogadas].jogador1.coluna = c;
        e->jogadas[e->num_jogadas].jogador1.linha = l;
        e->jogador_atual = 2;
    }
    else {
        e->jogadas[e->num_jogadas].jogador1.coluna = c;
        e->jogadas[e->num_jogadas].jogador1.linha = l;
        e->jogador_atual = 1;
    }
}
