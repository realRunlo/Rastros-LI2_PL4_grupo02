//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dados.h"
#include "lista_bot.h"


//Funcao que realiza a jogada emitida e altera o estado do jogo de acordo
int jogar(ESTADO *e, COORDENADA c){
    int l = c.linha;
    int co = c.coluna;
    int l_anterior = e->ultima_jogada.linha;
    int c_anterior = e->ultima_jogada.coluna;
    int j = get_jogador(e);
    set_branca(e, l ,co);  //altera a peça para a nova posição
    set_preta(e, l_anterior, c_anterior);  //altera a ultima posição da peça para preta
    adiciona_lista_jogadas(e, l, co, j);  //adiciona a jogada atual a lista de jogadas
    add_numjogadas(e);
    set_ultima_jogada(e, l, co);
    if(j==1){
        set_jogador(e,2);

    }
    else{
        set_jogador(e,1);
        add_numrondas(e);
    }


    return 1;
}


//funcao que joga aleatoriamente
        void joga_aleatorio(ESTADO* e,LISTA lista){
    time_t t;
    srand((unsigned) time(&t));
    int aleatorio;
    COORDENADA coordal;
    //imprimeLista(lista);
    if (lengthL(lista) == 0){
        coordal = * (COORDENADA *) devolve_cabeca(lista);
    }
    else {
        aleatorio = rand() % lengthL(lista);
        coordal = * (COORDENADA *) (procuraL (lista,aleatorio));
    }

    //printf("%d %d\n", coordal.linha + 1, coordal.coluna + 1);
    jogar(e,coordal);
    limpaL(lista);
}


//funcao que utiliza a estrategia euclidiana
void joga_euclidiana(ESTADO* e,LISTA lista){
    COORDENADA c = procura_caminho_curto(e, lista);
    printf("%d %d\n", c.linha + 1, c.coluna + 1);
    jogar(e,c);
    limpaL(lista);
}

//funcao que decide como o bot vai jogar
void bot_joga(ESTADO * e){
    LISTA l = criar_lista();
    l = lista_insere_vazias(l, e);
    if ((get_jogador(e) == 1 && perto_derrota(e, 1)) || (get_jogador(e) == 2 && perto_derrota(e, 2))){
        joga_euclidiana(e, l);
    }
    else joga_aleatorio(e, l);
}

//Funcao que verifica se a jogada e valida
int jogada_valida(ESTADO *e,COORDENADA c){
    int cAnt = e->ultima_jogada.coluna;
    int lAnt = e->ultima_jogada.linha;
    int cJog = c.coluna;
    int lJog = c.linha;
    if(abs(cJog-cAnt)>1 || abs(lJog-lAnt)>1 || e_preta(e, lJog, cJog) || (cJog == cAnt && lJog == lAnt) || e_vazio(e, lJog, cJog) == 0 || cJog<0 || cJog>7 || lJog<0 ||  lJog>7)
        return 0;

    return 1;

}
