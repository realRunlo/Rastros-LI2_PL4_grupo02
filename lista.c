//
// Created by runlo on 09/04/20.
//

#include "lista.h"
#include "camada_dados.h"
#include "logica.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>



LISTA criar_lista(){
    LISTA l1 = NULL;
    return l1;

}

LISTA insere_cabeca(LISTA L, void * valor){
    LISTA head = malloc(sizeof(LISTA));
    head->valor = valor;
    head->prox  = L;
    L = head;
    return L;
}

void * devolve_cabeca(LISTA L){
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
    for(;!lista_esta_vazia(l);l = proximo(l)){
        COORDENADA c = * (COORDENADA *) l->valor;
        printf("%d %d->",c.linha + 1,c.coluna + 1);
    }
    printf("\n");
}

int lista_esta_vazia(LISTA L){
    if (L == NULL) return 1;
    return 0;//talvez 0 e não null
}

LISTA lista_insere_vazias(LISTA lista, ESTADO *e){
     COORDENADA cord = get_ultima_jogada(e);
     COORDENADA valor[sizeof(COORDENADA)*50];
     int c = cord.coluna;
     int l = cord.linha;
     int casas_envolta = get_num_casas_envolta(e, cord);
     for(int iC = 0,iL = 0, acc = 0; acc < casas_envolta; acc++){
                 if ((iC == (-1) && iL < 1) || (iC == 0 && iL == 0)) iL++;          // interior do tabuleiro
                 else if (iC > (-1) && iL == (-1)) iC--;
                 else if (iC == 1 && iL > (-1)) iL--;
                 else if (iC < 1 && iL == 1) iC++;
         valor[acc].coluna = c + iC;
         valor[acc].linha  = l + iL;
         if (jogada_valida(e, valor[acc]) == 1){
             printf("%d %d\n",valor[acc].linha+1, valor[acc].coluna+1);      //teste para saber o k esta a ser gravado
             lista = insere_cabeca(lista, (void *) &valor[acc]); // guarda na lista a casa se for vazia
         }
     }
     return lista;
}

int lengthL(LISTA l){
    int r = 0;
    for(;l != NULL;l = proximo(l)){
        /*printf("%d ",r);
        COORDENADA c = * (COORDENADA *) l->valor;
        printf("%d %d->\n",c.linha + 1,c.coluna + 1);*/
        r++;
    }
    return r;
}

void * procuraL (LISTA l,int i){

    for(int j=0;j<=i;j++,l = proximo(l));
    return l->valor;


}

void limpaL(LISTA L){
    while(!lista_esta_vazia(L)) {
        L = remove_cabeca(L);
    }
}

//funcao que joga aleatoriamente
void joga_aleatorio(ESTADO* e,LISTA lista){
    int aleatorio = rand() % (lengthL(lista) - 1);
    //printf("%d %d",aleatorio,lengthL(lista)); printf("\n");    //usar isto para testes
    COORDENADA coordal = * (COORDENADA *) (procuraL (lista,aleatorio));
    jogar(e,coordal);
    desenha_tabuleiro(e);
    imprime_estado(e,coordal);
    limpaL(lista);
}

//funcao que utiliza a estrategia euclidiana
void joga_euclidiana(ESTADO* e,LISTA lista){
    //imprimeLista(lista);
    COORDENADA c = procura_caminho_curto(e, lista);
    jogar(e,c);
    desenha_tabuleiro(e);
    imprime_estado(e,c);
    limpaL(lista);
}

COORDENADA procura_caminho_curto(ESTADO* e, LISTA l){
    printf("entrei\n");
    COORDENADA c;
    imprimeLista(l);
    if (get_jogador(e) == 2){
        c = verifica_na_lista(l, 14);
    }
    else {
        c = verifica_na_lista(l, 0);
    }
    return c;
}

COORDENADA verifica_na_lista(LISTA l, int c_objetivo){
    COORDENADA c;
    COORDENADA jogada;
    imprimeLista(l);
    int melhor_pontuacao;
    if (c_objetivo == 0) melhor_pontuacao = 50;
    else melhor_pontuacao = 0;
    int pontuacao;
    for(; l != NULL ; l = l->prox){
        c = * (COORDENADA *) l->valor;
        pontuacao = c.linha + c.coluna;
        if (c_objetivo == 0)
        {
            if (pontuacao < melhor_pontuacao) {
                jogada = c;
                melhor_pontuacao = pontuacao;
            }
        }
        else
        {
            if (pontuacao > melhor_pontuacao)
            {
                jogada = c;
                melhor_pontuacao = pontuacao;
            }
        }
    }
    return jogada;
}
