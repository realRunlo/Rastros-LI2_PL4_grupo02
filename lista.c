//
// Created by runlo on 09/04/20.
//

#include "lista.h"
#include "camada_dados.h"
#include <stdio.h>
#include <stdlib.h>



LISTA criar_lista(){
    LISTA l1 = malloc(sizeof(LISTA));
    return l1;

}

LISTA insere_cabeca(LISTA L, COORDENADA valor){
    LISTA head = malloc(sizeof(LISTA));
    head->valor = valor;
    head->prox = L;

    L = head;
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

void imprimeLista(LISTA l){
    for(l;l->prox;l = l->prox){
        printf("%d%d->",l->valor.coluna,l->valor.linha);
    }

}

/*int lista_esta_vazia(LISTA L){
    return (L->valor == NULL); //talvez 0 e não null
}*/

LISTA lista_insere_vazias(LISTA lista, ESTADO *e){
     COORDENADA cord = get_ultima_jogada(e);
     COORDENADA valor;
     int c = cord.coluna;
     int l = cord.linha;
     int casas_envolta = get_num_casas_envolta(e, cord);
     for(int iC = 0,iL = 0, acc = 0; acc < casas_envolta; acc++){
         switch (jogador_local_tabuleiro(cord))
         {
             case (0):
                 if ((iC == (-1) && iL < 1) || (iC == 0 && iL == 0)) iL++;          // interior do tabuleiro
                 else if (iC > (-1) && iL == (-1)) iC--;
                 else if (iC == 1 && iL > (-1)) iL--;
                 else if (iC < 1 && iL == 1) iC++;
                 break;
             case (1):
                 if ((iC == 0 && iL == 0)) iC++;
                 else if (iC == 1 && iL == 0) iL--;                          // canto superior esquerdo
                 else iC--;
                 break;
             case (2):
                 if ((iC == 0 && iL == 0)) iC--;
                 else if (iC == (-1) && iL == 0) iL++;               // canto inferior direito
                 else iC++;
                 break;
             case (3):
                 if (iC == 0 && iL == 0) iC++;
                 else if (iC == 1 && iL == 0) iL--;
                 else if (iC > (-1) && iL == (-1)) iC--;             // fronteira superior
                 else iL++;
                 break;
             case (4):
                 if (iC == 0 && iL == 0) iC++;
                 else if (iC == 1 && iL == 0) iL++;            // fronteira inferior
                 else if (iC > (-1) && iL == 1) iC--;
                 else iL--;
                 break;
             case (5):
                 if (iC == 0 && iL == 0) iL++;
                 else if (iC == 0 && iL == 1) iC++;    // fronteira esquerdo
                 else if (iC == 1 && iL > (-1)) iL--;
                 else iC--;
                 break;
             case (6):
                 if (iC == 0 && iL == 0) iL++;
                 else if (iC == 0 && iL == 1) iC--;
                 else if (iC == 1 && iL > (-1)) iL--;          // fronteira direito
                 else iC++;
                 break;
         }
         valor.coluna = c + iC;
         valor.linha  = l + iL;
         if (e_vazio(e, valor.linha, valor.coluna))
            lista = insere_cabeca(lista, valor);            // guarda na lista a casa se for vazia
     }
     return lista;
}

int lengthL(LISTA l){
    int r = 0;
    for(l;l->prox;l = l->prox){
        r++;
    }
    return r;
}

COORDENADA procuraL (LISTA l,int i){

    for(int j=0;j<=i;j++,l = l->prox);

    return l->valor;


}

void limpaL(LISTA l){

    for(l;l->prox;l = l->prox)
        free(l);

}