//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define BUF_SIZE 1024
#include "camada_dados.h"
#include "logica.h"
#include "lista.h"



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
    if(i==get_Nrondas(e) && get_Njogadas(e)%2!=0)
        fprintf(filename,"%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha + 1);
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



//Imprime a jogada efetuada numero i
void lista_ronda(ESTADO *e,int i){
    if(i==get_Nrondas(e) && get_Njogadas(e)%2!=0)
        printf("%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha + 1);
    else{
        printf("%c%d ",converte_numero(e->jogadas[i].jogador1.coluna),e->jogadas[i].jogador1.linha + 1);
        printf("%c%d",converte_numero(e->jogadas[i].jogador2.coluna),e->jogadas[i].jogador2.linha + 1);
    }

}

void lista_movimentos(ESTADO *e){
    int j = 1;
    int i = 0;
    printf("\n");
    if (get_Njogadas(e) == 0) {}
    else{
        for(int nj=1; nj <= get_Njogadas(e) ;nj += 2){
            printf("0%d: ",j);
            lista_ronda(e,i);
            j++;
            i++;
            printf("\n");
        }
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
    for (l = 7; l >=0; l--) { //lê cada linha do tabuleiro , a contagem das linhas vai de cima para baixo por uma questão de correspondência à imagem

        for (c = 0; c <= 8; c++) {
            fscanf(fp, "%c", &crt);
            if (crt == '#') feitas++;
            novo_tabuleiro(e, l, c, crt);
        }
    }
    set_nJogadas(e, feitas);

    fscanf(fp, "\n");
    char ronda;
    int l1, l2,rondas=0;
    char c1, c2;
    int nj = 1;

    for (nj; nj <= feitas;nj += 2) {
        fscanf(fp, "0%c: ", &ronda);

        if ((feitas % 2 != 0) && nj == feitas) {
            fscanf(fp, "%c%d ", &c1, &l1);
            set_jogada_efetuada(e, 1, rondas , c1, l1);
        } else {
            fscanf(fp, "%c%d ", &c1, &l1);
            set_jogada_efetuada(e, 1, rondas, c1, l1);
            fscanf(fp, "%c%d", &c2, &l2);
            set_jogada_efetuada(e, 2, rondas , c2, l2);
            rondas++;
        }

        fscanf(fp, "\n");
    }

    set_nRondas(e, rondas);
    if ((feitas % 2 != 0))
    {
        set_jogador(e, 2);
        int coluna = converte_letra(c1);
        set_ultima_jogada(e, l1 -1, coluna);
    }
    else {
        set_jogador(e, 1);
        int coluna = converte_letra(c2);
        set_ultima_jogada(e, l2-1 , coluna);
    }
    fclose(fp);
}


//funcao que retorna o tabuleiro para uma ronda especificada
void volta_tabuleiro(ESTADO *e, int indice){
    int n_rondas= get_Nrondas(e);
    int n_jogadas= get_Njogadas(e);
    int i;
    int impar=0;
    if (n_jogadas % 2 != 0) impar = 1;
    COORDENADA cord1;
    COORDENADA cord2;

    if(indice<=n_rondas){

    for(i = n_rondas+1; i > indice;i--) {
        if (impar == 1) {    // apaga a jogada caso o ultimo a jogar tenha sido o jogador 1
            printf("entrei crlh");
            cord1  = get_ultima_jogada(e);
            set_vazio(e, cord1.linha, cord1.coluna);
            impar = 0;
        }
        else {    // apaga a jogadas normalmente
            cord1  = get_jogada_efetuada(e,1,i-1);
            set_vazio(e, cord1.linha, cord1.coluna);
            cord2  = get_jogada_efetuada(e,2,i-1);
            set_vazio(e, cord2.linha, cord2.coluna);
        }
    }
    // torna a ultima casa da ronda n como branca
    cord2  = get_jogada_efetuada(e,2,indice-1);
    set_branca(e, cord2.linha, cord2.coluna);
    set_ultima_jogada(e,cord2.linha,cord2.coluna);
    }else{
        for(int i=n_rondas;i<indice;i++){
            cord1  = get_jogada_efetuada(e,1,i);
            jogar(e,cord1);
            cord2  = get_jogada_efetuada(e,2,i);
            jogar(e,cord2);
        }

    }

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
    time_t t;
    srand((unsigned) time(&t));

    char linha[BUF_SIZE];
    LISTA lista,saveL;
    int aleatorio;
    COORDENADA coordal;
    int n_ronda;
    char col[2], lin[2],q,c1,c2,c3,c4;
    char filename[50];
    while (jogada_possivel(e) == 1) {
        printf("Digite um comando->");
        if (fgets(linha, BUF_SIZE, stdin) == NULL) {
            return 0;
        }
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
    else if (sscanf(linha,"%c%c%c%c%d",&c1,&c2,&c3,&c4,&n_ronda) == 5 && c1=='p' && c2=='o' && c3=='s' && c4 == ' ' && n_ronda >= 0){
        pos(e, n_ronda);  //lê o novo tabuleiro atualizando o respetivo estado
        desenha_tabuleiro(e);   //desenha um novo tabuleiro
        imprime_estadoI(e);
    }
    else if(sscanf(linha,"%c%c%c%c",&c1,&c2,&c3,&c4) == 4 && c1=='j' && c2=='o' && c3=='g' && c4== '2'){
        lista = criar_lista();
        lista = lista_insere_vazias(lista, e);
        joga_euclidiana(e,lista);
    }
    else if(sscanf(linha,"%c%c%c",&c1,&c2,&c3) == 3 && c1=='j' && c2=='o' && c3=='g'){
        lista = criar_lista();
        lista = lista_insere_vazias(lista, e);
        joga_aleatorio(e,lista);
    }


    else if(strlen(linha) == 2 && sscanf(linha, "%c",&q) == 1 && q=='q')      //comando de saída
        return 1;
    else
        printf("Digite um comando válido por favor!\n");


        if(jogada_possivel(e) !=1) return 1;  //este return é de forma a não haver a repetição do jogada_possivel na quebra do ciclo
        add_numcomandos(e);


    }

}



