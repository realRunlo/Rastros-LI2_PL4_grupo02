//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#include "camada_dados.h"
#include "logica.h"

// Funcao que desenha o tabuleiro
void desenha_tabuleiro(ESTADO *e){
    printf ("   A B C D E F G H\n");
    printf ("   _ _ _ _ _ _ _ _\n");
    for(int l = 7; l >= 0; l--){
        printf("%d| ", l+1 );  //depois por (l+1)
        for(int c = 0; c < 8; c++) {
            if (e_branca(e , l ,c)) printf("* ");
            else if (c == 0 && l == 0) printf("1 ");
            else if (c == 7 && l == 7) printf("2 ");
            else if (e_preta(e , l ,c)) printf("# ");
            else printf(". ");
        }
        printf("\n");
    }
}



// ////////////////////////////////////////////////////////////////////////////
void imprime_estado(ESTADO *e,COORDENADA c){ //prompt
    printf("#  %d Jog:%d N:%d >>%c%d\n",get_Njogadas(e)+1 ,get_jogador(e),get_Njogadas(e),converte_numero(get_coluna(c)),get_linha(c)+1);

}

void gravar(const char *filename, const char *mode){
    FILE *fp;

    fp = fopen(filename,mode);
    fprintf(fp,"%c",);


    fclose(fp);
}

// Função que deve ser completada e colocada na camada de interface
int interpretador(ESTADO *e) {

    char linha[BUF_SIZE];
    char col[2], lin[2];
    while (jogada_possivel(e) == 1) {
        if (fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;
        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            if(jogada_valida(e, coord) == 1) {
                imprime_estado(e,coord);
                jogar(e, coord);
                desenha_tabuleiro(e);
            }else{
                printf("Faça uma jogada válida pf\n");       //se a jogada não for válida pede por uma jogada válida
                interpretador(e);
            }

        }
    }
    return 1;

}



// ////////////////////////  WORK IN PROGRESS //////////////////////////////////////////////


//Imprime jogadas efetuadas
void lista_movimentos(ESTADO *e){
    printf("\n");

    for(int i=01;i<=e->num_jogadas;i++){
        printf("%d:",i);
        for(int j=0;j<2;j++){

            printf("%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha);
        }
        printf("\n");
    }
    printf("\n");
}





