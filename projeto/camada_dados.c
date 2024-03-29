//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <stdlib.h>
#include "camada_dados.h"
#include "lista.h"





// //////////////////////////////////////////////////////////////////////////////////////////////////////


// Função que deve ser completada e colocada na camada de dados
ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    limpaTab(e);
    e->tab[4][4] = BRANCA;
    e->ultima_jogada.coluna=4;
    e->ultima_jogada.linha=4;
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->num_rondas = 0;
    e->num_comandos = 0;
// Falta a resto da inicialização.
    return e;
}


// Função que da reset ao jogo
void reset_estado(ESTADO *e) {
    limpaTab(e);
    e->tab[4][4] = BRANCA;
    e->ultima_jogada.coluna=4;
    e->ultima_jogada.linha=4;
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    e->num_rondas = 0;
    e->num_comandos = 0;
}

void limpaTab (ESTADO *e){
    for(int l = 7; l >= 0; l--){
        for(int c = 0; c < 8; c++){
            set_vazio(e,l, c);
        }
    }
}
//Converte um numero de uma coluna na sua letra correspondente
char converte_numero(int x){
    return 'a' + x;
}

//Converte uma letra no seu numero correspondente
int converte_letra(char x){
    return x - 'a';
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

//Coloca a casa como sendo uma peca vazio
void set_vazio(ESTADO *e, int l, int c){
    e->tab[l][c] = VAZIO;
}



//Funcao que retorna o numero do jogador atual
int get_jogador(ESTADO *e){
    return e->jogador_atual;
}

//Funcao que atualiza o numero do jogador atual
void set_jogador(ESTADO *e, int j){
    e->jogador_atual = j;
}


int get_Njogadas(ESTADO *e){ //retorna o número de jogadas
    return e->num_jogadas;
}

int get_Nrondas(ESTADO *e){ //retorna o número de rondas
    return e->num_rondas;
}

int get_Ncomandos(ESTADO *e){ //retorna o número de comandos
    return e->num_comandos;
}

void set_nJogadas(ESTADO *e, int nJ){ //atualiza o número de jogadas
    e->num_jogadas = nJ;
}

void set_nRondas(ESTADO *e, int nR){ //atualiza o número de rondas
    e->num_rondas = nR;
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

//Funcao que adiciona 1 ao numero de rondas
void add_numrondas(ESTADO *e){
    e->num_rondas++;
}


//Funcao que adiciona 1 ao numero de jogadas
void add_numcomandos(ESTADO *e){
    e->num_comandos++;
}


//Funcao que adiciona na lista de jogadas a ultima jogada feita
void adiciona_lista_jogadas(ESTADO *e, int l, int c, int jogador){
    if (jogador == 1) {
        e->jogadas[e->num_rondas].jogador1.linha  = l;
        e->jogadas[e->num_rondas].jogador1.coluna = c;
    }
    else {
        e->jogadas[e->num_rondas].jogador2.linha  = l;
        e->jogadas[e->num_rondas].jogador2.coluna = c;
    }
}


//Funcao que modifica o estado do tabuleiro quando o le
void novo_tabuleiro(ESTADO *e, int l, int c, char x){
    if (x == '.') set_vazio(e, l, c);
    else if(x == '#') set_preta(e, l, c);
    else if (x== '*') {
        set_branca(e, l, c);
        set_ultima_jogada(e,l,c); //sou deus
    }
}


//funcao que atualiza o estado das jogadas efetuadas
void set_jogada_efetuada(ESTADO *e, int j, int jogada, char coluna, int linha){
    int c = converte_letra(coluna);
    int l = linha - 1;
    if (j == 1) {
        e->jogadas[jogada].jogador1.linha = l;
        e->jogadas[jogada].jogador1.coluna = c;
    }
    else {
        e->jogadas[jogada].jogador2.linha = l;
        e->jogadas[jogada].jogador2.coluna = c;
    }
}





//funcao que retorna as coordenadas de uma jogada ja efetuada
COORDENADA get_jogada_efetuada(ESTADO *e, int j, int jogada){
    COORDENADA c;
    if (j == 1) {
        c.linha  = e->jogadas[jogada].jogador1.linha;
        c.coluna = e->jogadas[jogada].jogador1.coluna;
    }
    else {
        c.linha  = e->jogadas[jogada].jogador2.linha;
        c.coluna = e->jogadas[jogada].jogador2.coluna;
    }
    return c;
}


//funcao que retorna o estado das jogadas efetuadas
COORDENADA get_ultima_jogada(ESTADO *e){
    COORDENADA c;
    c.linha  = e->ultima_jogada.linha;
    c.coluna = e->ultima_jogada.coluna;
    return c;
}
