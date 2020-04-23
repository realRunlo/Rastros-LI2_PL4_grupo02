//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <stdlib.h>
#include "camada_dados.h"



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


//Verifica de há casas disponiveis para jogar
int espaco_vazio(ESTADO *e){
    int c = e->ultima_jogada.coluna;
    int l = e->ultima_jogada.linha;
    int j = get_jogador(e);
    if (c == 0 && l == 7 && (e_vazio(e, l - 1, c) || e_vazio(e, l, c + 1) || e_vazio(e, l - 1, c + 1) ))           // canto superior esquerdo
        return 1;
    else if (l == 0 && c == 7 && (e_vazio(e, l + 1, c) || e_vazio(e, l + 1, c - 1) || e_vazio(e, l, c - 1)))       // canto inferior direito
        return 1;
    else if (c == 0 && l != 7 && (e_vazio(e, l + 1, c) || e_vazio(e, l - 1, c) || e_vazio(e, l, c + 1) ||          // esta na primeira coluna
                                  e_vazio(e, l + 1, c + 1) || e_vazio(e, l - 1, c + 1) ))
        return 1;
    else if (c == 7 && l != 0 && (e_vazio(e, l + 1, c) || e_vazio(e, l - 1, c) || e_vazio(e, l, c - 1) ||          // esta na ultima coluna
                                  e_vazio(e, l + 1, c - 1) || e_vazio(e, l - 1, c - 1)))
          return 1;
    else if (l == 0 && c != 7 && (e_vazio(e, l + 1, c) || e_vazio(e, l, c + 1) || e_vazio(e, l, c - 1) ||          // esta na primeira linha
                                  e_vazio(e, l + 1, c + 1)  || e_vazio(e, l + 1, c - 1) ))
          return 1;
    else if (l == 7 && c != 0 && (e_vazio(e, l - 1, c) || e_vazio(e, l, c + 1) || e_vazio(e, l, c - 1) ||          // esta na ultima linha
                                  e_vazio(e, l + 1, c - 1) || e_vazio(e, l - 1, c + 1) || e_vazio(e, l - 1, c - 1)))
          return 1;
    else if ( c != 0 && c != 7 && l != 0 && l != 7 && (e_vazio(e, l + 1, c)  || e_vazio(e, l - 1, c)  || e_vazio(e, l, c + 1) || e_vazio(e, l, c - 1) ||                 // fora das fronteiras
                                                       e_vazio(e, l + 1, c + 1)  || e_vazio(e, l + 1, c - 1) || e_vazio(e, l - 1, c + 1) || e_vazio(e, l - 1, c - 1)))
             return 1;
    else {
            printf("Jogador %d bloqueado!Perdeu\n", j);
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
    if(espaco_vitoria(e) && espaco_vazio(e))
        return 1;
    return 0;

}

//Funcao que verifica se a jogada e valida
int jogada_valida(ESTADO *e,COORDENADA c){
    int cAnt = e->ultima_jogada.coluna;
    int lAnt = e->ultima_jogada.linha;
    int cJog = c.coluna;
    int lJog = c.linha;
    if(abs(cJog-cAnt)>1 || abs(lJog-lAnt)>1 || e_preta(e, lJog, cJog) || (cJog == cAnt && lJog == lAnt) || e_vazio(e, lJog, cJog) == 0)
        return 0;

    return 1;

}
