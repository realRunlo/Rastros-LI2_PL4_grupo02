//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF_SIZE 1024
#include "camada_dados.h"
#include "logica.h"


// Funcao que desenha o tabuleiro
void desenha_tabuleiro(ESTADO *e){
    printf ("   A B C D E F G H \n");
    printf ("   _ _ _ _ _ _ _ _ \n");
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
void imprime_estadoI(ESTADO *e){ //prompt só para o estado inicial
    printf("#  %d Jog:%d N:%d \n",get_Ncomandos(e) ,get_jogador(e),get_Nrondas(e));

}
void imprime_estado(ESTADO *e,COORDENADA c){ //prompt
    printf("#  %d Jog:%d N:%d >>%c%d\n",get_Ncomandos(e) ,get_jogador(e),get_Nrondas(e),converte_numero(get_coluna(c)),get_linha(c)+1);

}

// //////////////////////// Listar movimentos //////////////////////////////////////////////

//Imprime a jogada efetuada numero i no ficheiro
void flista_ronda(ESTADO *e,int i,FILE *filename){
    if(i==get_Nrondas(e)-1 && get_Njogadas(e)%2!=0)
        fprintf(filename,"%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha + 1);
    else{
        fprintf(filename,"%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha + 1);
        fprintf(filename,"%c%d",converte_numero(e->jogadas[i].jogador2.coluna),e->jogadas[i].jogador2.linha + 1);
    }

}

//Imprime jogadas efetuadas no ficheiro
void flista_movimentos(ESTADO *e,FILE *filename){
    int j=1;
    fprintf(filename,"\n");
    for(int i=0;i<(get_Nrondas(e)-1);i++){
        fprintf(filename,"0%d:",j);
        flista_ronda(e,i,filename);
        j++;
        fprintf(filename,"\n");
    }
}



//Imprime a jogada efetuada numero i
void lista_ronda(ESTADO *e,int i){
    if(i==get_Nrondas(e) && get_Njogadas(e)%2!=0)
        printf("%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha + 1);
    else{
        printf("%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha + 1);
        printf("%c%d",converte_numero(e->jogadas[i].jogador2.coluna),e->jogadas[i].jogador2.linha + 1);
    }

}


//Imprime jogadas efetuadas
void lista_movimentos(ESTADO *e){
    int j=1;
    printf("\n");
    for(int i=0;i<=get_Nrondas(e) && get_Njogadas(e) != 0;i++){
        printf("0%d:",j);
        lista_ronda(e,i);
        j++;
        printf("\n");
    }
}





// FUNÇÔES DE MANUSEAMENTO DE FICHEIRO EXTERNO ///////////////////////////////////////////////////////////////

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


void ler(ESTADO *e, const char *filename, const char *mode) {
    FILE *fp;

    fp = fopen(filename, mode);

    char crt;
    int l, c, feitas = 0; //posição do canto superior esquerdo do tabuleiro
    for (l = 7; l >=
                0; l--) { //lê cada linha do tabuleiro , a contagem das linhas vai de cima para baixo por uma questão de correspondência à imagem
        for (c = 0; c <= 8; c++) {
            fscanf(fp, "%c", &crt);
            if (crt == '#') feitas++;
            novo_tabuleiro(e, l, c, crt);
        }
    }
    set_nJogadas(e, feitas);

    fscanf(fp, "\n");
    char ronda;
    int l1, l2, Nrondas, rondas=0;
    char c1, c2;
    if (feitas % 2 != 0) Nrondas = (feitas + 1) / 2;
    else Nrondas = feitas/2;

    for (int i = 1; i <= Nrondas; i++) {
        fscanf(fp, "0%c: ", &ronda);
        if ((feitas % 2 != 0) && i == Nrondas) {
            fscanf(fp, "%c%d", &c1, &l1);
            set_jogada_efetuada(e, 1, rondas , c1, l1);
        } else {
            fscanf(fp, "%c%d ", &c1, &l1);
            set_jogada_efetuada(e, 1, rondas, c1, l1);
            fscanf(fp, "%c%d", &c2, &l2);
            set_jogada_efetuada(e, 2, rondas , c2, l2);rondas++;
        }
        fscanf(fp, "\n");
    }
    set_nRondas(e, Nrondas);
    if ((feitas % 2 != 0))
    {
        set_jogador(e, 2);
        int coluna = converte_letra(c1);
        printf("%c%d %d\n",c1,l1,coluna);   // teste
        set_ultima_jogada(e, l1 - 1, coluna);
    }
    else {
        set_jogador(e, 1);
        int coluna = converte_letra(c2);
        printf("%c%d %d\n",c2,l2,coluna);  // teste
        set_ultima_jogada(e, l2 - 1, coluna);
    }
    fclose(fp);
}


//funcao que retorna o tabuleiro para uma ronda especificada
void volta_tabuleiro(ESTADO *e, int n_ronda){
    printf("teste\n");
    int n_rondas= get_Nrondas(e);
    int n_jogadas= get_Njogadas(e);
    int impar;
    printf("%d\n",n_rondas);
    printf("%d\n",n_jogadas);
    if (n_jogadas % 2 != 0) impar = 1;
    for(int i = n_rondas+1; i > n_ronda;i--) {
        if (impar == 1) {    // apaga a jogada caso o ultimo a jogar tenha sido o jogador 1
            printf("teste1\n");
            printf("teste\n");
            int linha  = get_jogada_efetuada(e,1,i-1,0);
            int coluna = get_jogada_efetuada(e,1,i-1,1);
            printf("%d %d\n",linha,coluna);
            set_vazio(e, linha, coluna);
            impar = 0;
        }
        else {               // apaga a jogadas normalmente
            printf("teste2\n");
            printf("teste\n");
            int linha1  = get_jogada_efetuada(e,1,i-1,0);
            int coluna1 = get_jogada_efetuada(e,1,i-1,1);
            int linha2  = get_jogada_efetuada(e,2,i-1,0);
            int coluna2 = get_jogada_efetuada(e,2,i-1,1);
            printf("%d %d\n",linha1,coluna1);
            printf("%d %d\n",linha2,coluna2);
            set_vazio(e, linha1, coluna1);
            set_vazio(e, linha2, coluna2);
            printf("teste\n");
        }
    }
    // torna a ultima casa da ronda n como branca
    printf("teste3\n");
    int linha  = get_jogada_efetuada(e,2,n_ronda-1,0);
    int coluna = get_jogada_efetuada(e,2,n_ronda-1,1);
    set_branca(e, linha, coluna);
    set_ultima_jogada(e,linha,coluna);
}




// funcao principal que reverte o estado do jogo
void pos(ESTADO *e, int n_ronda){
    if (n_ronda == 0)
    {
        reset_estado(e);

    }
    else {
        volta_tabuleiro(e, n_ronda); // funcao que apaga do tabuleiro as jogadas menos as pretendidas
        set_nJogadas(e, n_ronda * 2);
        set_nRondas(e, n_ronda);
        set_jogador(e, 1);
    }
}




// //////////////////////////////////////////////////////////////////////////////////////////////////

// Função de interface,que permite a intereção com os jogadores
int interpretador(ESTADO *e) {

    char linha[BUF_SIZE];
    int n_ronda;
    char col[2], lin[2],q,c1,c2,c3,c4;
    char filename[50];
    while (jogada_possivel(e) == 1) {
        printf("Digite um comando->");
        if (fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;
        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            if(jogada_valida(e, coord) == 1) {
                jogar(e, coord);
                desenha_tabuleiro(e);
                imprime_estado(e,coord);

            }else{
                printf("Faça uma jogada válida pf\n");       //se a jogada não for válida pede por uma jogada válida
                add_numcomandos(e);
                imprime_estado(e,coord);
                interpretador(e);
                return 1;
            }

        }
        else if(sscanf(linha,"%c%c%c%s", &c1, &c2, &c3, filename) == 4 && c1=='g' && c2=='r' && c3 == ' '){
            gravar(e,filename,"w");
            printf("O seu jogo foi salvo!\n");
        }
        else if (sscanf(linha,"%c%c%c %s",&c1,&c2,&c3,filename) == 4 && c1=='l' && c2=='e' && c3=='r' ){
            ler(e,filename, "r");  //lê o novo tabuleiro atualizando o respetivo estado
            desenha_tabuleiro(e);   //desenha um novo tabuleiro
            imprime_estadoI(e);

        }
        else if (sscanf(linha,"%c%c%c%c",&c1,&c2,&c3,&c4) == 4 && c1=='m' && c2=='o' && c3=='v' && c4 == 's'){
            lista_movimentos(e);
        }
        else if (sscanf(linha,"%c%c%c%c%d",&c1,&c2,&c3,&c4,&n_ronda) == 5 && c1=='p' && c2=='o' && c3=='s' && c4 == ' ' && n_ronda >= 0 && n_ronda <= get_Nrondas(e)){
                pos(e, n_ronda);  //lê o novo tabuleiro atualizando o respetivo estado
                desenha_tabuleiro(e);   //desenha um novo tabuleiro
                imprime_estadoI(e);
        }

        else if(strlen(linha) == 2 && sscanf(linha, "%c",&q) == 1 && q=='q')      //comando de saída
            return 1;
        else
            printf("Digite um comando válido por favor!\n");

        if(jogada_possivel(e) !=1) return 1;  //este return é de forma a não haver a repetição do jogada_possivel na quebra do ciclo
        add_numcomandos(e);
    }

}



