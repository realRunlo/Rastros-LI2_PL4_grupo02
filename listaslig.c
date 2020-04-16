//
// Created by runlo on 09/04/20.
//

#include "listaslig.h"
#include "camada_dados.h"
#include <stdlib.h>

LISTA criar_lista(){
    LISTA l1 = malloc(sizeof(LISTA));

}

LISTA insere_cabeca(LISTA L, COORDENADA valor){
    LISTA head = malloc(sizeof(LISTA));
    head->valor = valor;
    head->prox = L;

    L = head;   //pode não ser necessário mas tbm não há problema
    return L;
}

COORDENADA devolve_cabeca(LISTA L){
    return (L->valor);
}

LISTA proximo(LISTA L){
    return (L->prox);
}

LISTA remove_cabeca(LISTA L){
    LISTA r = L->prox;
    free(L);
    return r;
}

/*int lista_esta_vazia(LISTA L){
    return (L->valor == NULL); //talvez 0 e não null
}*/

void lista_insere_vazias(LISTA lista, ESTADO *e){
     COORDENADA cord = get_ultima_jogada(e);
     COORDENADA valor;
     int c = cord.coluna;
     int l = cord.linha;
     int casas_envolta = get_num_casas_envolta(e, cord);
     for(int iC = 0,iL = 0, acc = 0; acc < casas_envolta; acc++){
        if (jogador_local_tabuleiro(cord) == 0) {                      // interior do tabuleiro
            if ((iC == (-1) && iL < 1 ) || (iC == 0 && iL == 0)) iL++;
            else if (iC > (-1) && iL == (-1)) iC--;
            else if (iC == 1 && iL > (-1)) iL--;
            else if (iC < 1 && iL == 1) iC++;
        }
        else if (jogador_local_tabuleiro(cord) == 1)                // canto superior esquerdo
        {
            if ((iC == 0 && iL == 0)) iC++;
            else if (iC == 1 && iL == 0) iL--;
            else iC--;
        }
        else if (jogador_local_tabuleiro(cord) == 2)                // canto inferior direito
        {
            if ((iC == 0 && iL == 0)) iC--;
            else if (iC == (-1) && iL == 0) iL++;
            else iC++;
        }
        else if (jogador_local_tabuleiro(cord) == 3)                // fronteira superior
        {
            if (iC == 0 && iL == 0) iC++;
            else if (iC == 1 && iL == 0) iL--;
            else if (iC > (-1) && iL == (-1)) iC--;
            else iL++;
        }
        else if (jogador_local_tabuleiro(cord) == 4)                // fronteira inferior
        {
            if (iC == 0 && iL == 0) iC++;
            else if (iC == 1 && iL == 0) iL++;
            else if (iC > (-1) && iL == 1) iC--;
            else iL--;
        }
        else if (jogador_local_tabuleiro(cord) == 5)                // fronteira esquerdo
        {
            if (iC == 0 && iL == 0) iL++;
            else if (iC == 0 && iL == 1) iC++;
            else if (iC ==1 && iL > (-1)) iL--;
            else iC--;
        }
        else                                                        // fronteira direito
        {
            if (iC == 0 && iL == 0) iL++;
            else if (iC == 0 && iL == 1) iC--;
            else if (iC ==1 && iL > (-1)) iL--;
            else iC++;
        }
         valor.coluna = c + iC;
         valor.linha  = l + iL;
         if (e_branca(e, valor.linha, valor.coluna))
            insere_cabeca(lista, valor);            // guarda na lista a casa se for branca
     }
}

