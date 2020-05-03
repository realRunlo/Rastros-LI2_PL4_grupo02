//
// Created by runlo on 29/04/20.
//

#include "funcoes.h"
#include <stdio.h>
#include "dados.h"

// funcao auxiliar do comando ler que le o tabuleiro do ficheiro
int le_tabuleiro(ESTADO *e,FILE *fp){
    char crt;
    int l, c, feitas = 0; //posição do canto superior esquerdo do tabuleiro
    for (l = 7; l >=0; l--) { //lê cada linha do tabuleiro , a contagem das linhas vai de cima para baixo por uma questão de correspondência à imagem

        for (c = 0; c <= 8; c++) {
            if (fscanf(fp, "%c", &crt) == 1)
                if (crt == '#') feitas++;
            novo_tabuleiro(e, l, c, crt);

        }
    }
    return feitas;
}


void ler(ESTADO *e, const char *filename, const char *mode) {
    FILE *fp;
    fp = fopen(filename, mode);
    int l1, l2, rondas=0, nj = 1, feitas = le_tabuleiro(e, fp); // percorre o tabuleiro e calcula o numero de jogadas feitas
    char c1, c2, ronda;
    set_nJogadas(e, feitas);
    if (fscanf(fp, "\n") == 0) {
        for (; nj <= feitas; nj += 2) {
            if (fscanf(fp, "0%c: ", &ronda) == 1) {
                if ((feitas % 2 != 0) && nj == feitas) {
                    if (fscanf(fp, "%c%d\n", &c1, &l1) == 2)
                        set_jogada_efetuada(e, 1, rondas, c1, l1);
                } else {
                    if (fscanf(fp, "%c%d ", &c1, &l1) == 2)
                        set_jogada_efetuada(e, 1, rondas, c1, l1);
                    if (fscanf(fp, "%c%d\n", &c2, &l2) == 2)
                        set_jogada_efetuada(e, 2, rondas, c2, l2);
                    rondas++;
                }
            }
        }
        set_nRondas(e, rondas);
        if ((feitas % 2 != 0)) {
            set_jogador(e, 2);
            int coluna = converte_letra(c1);
            set_ultima_jogada(e, l1 - 1, coluna);
        } else {
            set_jogador(e, 1);
            int coluna = converte_letra(c2);
            set_ultima_jogada(e, l2 - 1, coluna);
        }
    }
    fclose(fp);

}


// FUNÇÔES DE MANUSEAMENTO DE FICHEIRO EXTERNO ///////////////////////////////////////////////////////////////

//auxiliar do comando gravar, que regista o tabuleiro
void grava_tabuleiro(ESTADO *e,FILE *filename){ // Função que grava o tabuleiro num dado ficheiro
    for(int l = 7; l >= 0; l--){
        for(int c = 0; c < 8; c++) {
            if (e_branca(e , l ,c)) fprintf(filename,"*");
            else if (c == 0 && l == 0) fprintf(filename,"1");
            else if (c == 7 && l == 7) fprintf(filename,"2");
            else if (e_preta(e , l ,c)) fprintf(filename,"#");
            else fprintf(filename,".");
        }
        fprintf(filename,"\n");
    }
}



//culminar da grava_tabuleiro e grava_estado
void gravar(ESTADO *e,const char *filename, const char *mode){
    FILE *fp;

    fp = fopen(filename,mode);
    grava_tabuleiro(e,fp);
    flista_movimentos(e,fp);

    fclose(fp);
}

// //////////////////////// Listar movimentos //////////////////////////////////////////////

//Imprime a jogada efetuada numero i no ficheiro
void flista_ronda(ESTADO *e,int i,FILE *filename){
    if(i==get_Nrondas(e) && get_Njogadas(e)%2!=0)
        fprintf(filename,"%c%d",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha + 1);
    else{
        fprintf(filename,"%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha + 1);
        fprintf(filename,"%c%d",converte_numero(e->jogadas[i].jogador2.coluna),e->jogadas[i].jogador2.linha + 1);
    }

}

//Imprime jogadas efetuadas no ficheiro
void flista_movimentos(ESTADO *e,FILE *filename){
    int j = 1;
    int i = 0;
    fprintf(filename,"\n");
    if (get_Njogadas(e) == 0) {}
    else{
        for(int nj=1; nj <= get_Njogadas(e) ;nj += 2){
            fprintf(filename,"0%d: ",j);
            flista_ronda(e,i,filename);
            j++;
            i++;
            fprintf(filename,"\n");
        }
    }
}


